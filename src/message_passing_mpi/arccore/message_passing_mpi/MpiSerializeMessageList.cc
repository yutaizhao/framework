﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
/*---------------------------------------------------------------------------*/
/* MpiSerializeMessageList.cc                                  (C) 2000-2020 */
/*                                                                           */
/* Gestion des messages de sérialisationd via MPI.                           */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arccore/message_passing_mpi/MpiSerializeMessageList.h"
#include "arccore/message_passing_mpi/MpiSerializeMessage.h"
#include "arccore/message_passing_mpi/MpiSerializeDispatcher.h"
#include "arccore/message_passing_mpi/MpiAdapter.h"
#include "arccore/message_passing/ISerializeMessage.h"
#include "arccore/serialize/BasicSerializer.h"
#include "arccore/trace/ITraceMng.h"
#include "arccore/base/FatalErrorException.h"
#include "arccore/base/TimeoutException.h"

#include <algorithm>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arccore::MessagePassing::Mpi
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class MpiSerializeMessageList::_SortMessages
{
 public:

  bool operator()(const MpiSerializeMessage* m1,const MpiSerializeMessage* m2)
  {
    return _SortMessages::compare(m1->message(),m2->message());
  }
  
  bool operator()(const ISerializeMessage* pm1,const ISerializeMessage* pm2)
  {
    return compare(pm1,pm2);
  }
  static bool compare(const ISerializeMessage* pm1,const ISerializeMessage* pm2)
  {
    Int32 dest_p1 = pm1->destRank();
    Int32 dest_p2 = pm2->destRank();
    Int32 p1_tag = pm1->tag();
    Int32 p2_tag = pm2->tag();
      
    // TODO: traiter le cas destRank()==A_NULL_RANK
    if (dest_p1==dest_p2){
      Int32 orig_p1 = pm1->origRank();
      Int32 orig_p2 = pm2->origRank();

      if (pm1->isSend()){
        if (orig_p1==orig_p2 && (p1_tag!=p2_tag))
          return p1_tag < p2_tag;
        if (orig_p1<dest_p1)
          return true;
      }
      if (!pm1->isSend()){
        if (orig_p1==orig_p2 && (p1_tag!=p2_tag))
          return p1_tag < p2_tag;
        if (dest_p1<orig_p1)
          return true;
      }
      return false;
    }
    if (dest_p1 < dest_p2)
      return true;
    return false;
  }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

MpiSerializeMessageList::
MpiSerializeMessageList(MpiSerializeDispatcher* dispatcher)
: m_dispatcher(dispatcher)
, m_adapter(dispatcher->adapter())
, m_trace(m_adapter->traceMng())
{}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void MpiSerializeMessageList::
addMessage(ISerializeMessage* msg)
{
  Integer nb_msg = m_messages_to_process.size();
  MpiSerializeMessage* msm = new MpiSerializeMessage(msg,nb_msg);
  m_messages_to_process.add(msm);
}
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void MpiSerializeMessageList::
processPendingMessages()
{
  // L'envoie de messages peut se faire en mode bloquant ou non bloquant.
  // Quel que soit le mode, l'ordre d'envoie doit permettre de ne pas
  // avoir de deadlock. Pour cela, on applique l'algorithme suivant:
  // - chaque processeur effectue ces envois et réceptions dans l'ordre
  // croissant des rang de processeurs
  // - lorsque deux processeurs communiquent, c'est celui dont le rang est
  // le plus faible qui envoie ces messages d'abord.
  ITraceMng* msg = m_trace;
  Integer nb_message = m_messages_to_process.size();
  std::stable_sort(std::begin(m_messages_to_process),std::end(m_messages_to_process),_SortMessages());
  for( Integer i=0, is=m_messages_to_process.size(); i<is; ++i ){
    ISerializeMessage* pmsg = m_messages_to_process[i]->message();
    // Tag 0 indique le tag par defaut
    if (pmsg->tag()==0)
      pmsg->setTag(MpiSerializeDispatcher::DEFAULT_SERIALIZE_TAG);
    msg->debug() << "Sorted message " << i
                 << " orig=" << pmsg->origRank()
                 << " dest=" << pmsg->destRank()
                 << " tag=" << pmsg->tag()
                 << " send?=" << pmsg->isSend();
  }

  Int64 serialize_buffer_size = m_dispatcher->serializeBufferSize();
  for( Integer i=0; i<nb_message; ++i ){
    MpiSerializeMessage* mpi_msg = m_messages_to_process[i];
    ISerializeMessage* pmsg = mpi_msg->message();
    msg->debug() << "sending message " << i << " to " << pmsg->destRank()
                 << (pmsg->isSend() ? " To send" : " To receive");
    Request new_request;
    if (pmsg->isSend()){
      new_request = m_dispatcher->sendSerializerWithTag(pmsg->serializer(),pmsg->destRank(),pmsg->tag(),false);
    }
    else{
      BasicSerializer* sbuf = mpi_msg->serializeBuffer();
      msg->debug() << "call recvSerializer2 tag=" << pmsg->tag() << " from=" << pmsg->destRank();
      sbuf->preallocate(serialize_buffer_size);
      new_request = m_dispatcher->recvSerializerBytes(sbuf->globalBuffer(),pmsg->destRank(),pmsg->tag(),false);
    }
    m_messages_request.add(MpiSerializeMessageRequest(mpi_msg,new_request));
  }
  // Plus de messages à exécuter
  m_messages_to_process.clear();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

Integer MpiSerializeMessageList::
waitMessages(eWaitType wait_type)
{
  //Timer::Phase tphase(m_parallel_mng->timeStats(),TP_Communication);
  if (wait_type==WaitAll){
    while (_waitMessages(WaitSome)!=(-1))
      ;
    return (-1);
  }
  return _waitMessages(wait_type);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

Integer MpiSerializeMessageList::
_waitMessages(eWaitType wait_type)
{
  Integer nb_message_finished = 0;
  ITraceMng* msg = m_trace;
  Integer nb_message = m_messages_request.size();
  Int32 comm_rank = m_adapter->commRank();
  UniqueArray<MPI_Status> mpi_status(nb_message);
  UniqueArray<Request> requests(nb_message);
  UniqueArray<bool> done_indexes(nb_message);
  done_indexes.fill(false);
#ifdef ARCANE_TRACE_MPI
  msg->info() << "Waiting for "
              << " rank =" << m_parallel_mng->commRank()
              << " for  " << nb_message << " messages";
#endif
  for( Integer z=0; z<nb_message; ++z ){
    MpiSerializeMessage* msm = m_messages_request[z].m_mpi_message;
    requests[z] = m_messages_request[z].m_request;
    msg->debug() << "Waiting for message: "
                 << " rank=" << comm_rank
                 << " issend=" << msm->message()->isSend()
                 << " dest=" << msm->message()->destRank()
                 << " tag=" << msm->message()->tag()
                 << " request=" << (MPI_Request)requests[z];
  }
  mpi_status.resize(nb_message);
  MpiAdapter* adapter = m_adapter;
  try{
    switch(wait_type){
    case WaitAll:
      ARCCORE_FATAL("Bad value WaitAll");
    case WaitSome:
      msg->debug() << " rank=" << comm_rank << "Wait some " << nb_message;
      if (nb_message>0)
        adapter->waitSomeRequestsMPI(requests,done_indexes,mpi_status,false);
      break;
    case WaitSomeNonBlocking:
      msg->debug() << " rank=" << comm_rank << "Wait some non blocking " << nb_message;
      if (nb_message>0)
        adapter->waitSomeRequestsMPI(requests,done_indexes,mpi_status,true);
      break;
    }
  }
  catch(const TimeoutException&){
    std::ostringstream ostr;
    for( Integer z=0; z<nb_message; ++z ){
      MpiSerializeMessage* msm = m_messages_request[z].m_mpi_message;
      ostr << "IndexReturn message: "
           << " issend=" << msm->message()->isSend()
           << " dest=" << msm->message()->destRank()
           << " done_index=" << done_indexes[z]
           << " status_src=" << mpi_status[z].MPI_SOURCE
           << " status_tag=" << mpi_status[z].MPI_TAG
           << " status_err=" << mpi_status[z].MPI_ERROR
           << " request=" << (MPI_Request)requests[z]
           << "\n";
    }
    msg->pinfo() << "Info messages: myrank=" << comm_rank << " " << ostr.str();
    throw;
  }
  for( Integer z=0; z<nb_message; ++z ){
    MpiSerializeMessage* msm = m_messages_request[z].m_mpi_message;
    msg->debug() << "IndexReturn message: "
                 << " issend=" << msm->message()->isSend()
                 << " dest=" << msm->message()->destRank()
                 << " done_index=" << done_indexes[z]
                 << " status_src=" << mpi_status[z].MPI_SOURCE
                 << " status_tag=" << mpi_status[z].MPI_TAG
                 << " status_err=" << mpi_status[z].MPI_ERROR
                 << " request=" << (MPI_Request)requests[z];
  }

  UniqueArray<MpiSerializeMessageRequest> new_messages;

  int mpi_status_index = 0;
  for( Integer i=0; i<nb_message; ++i ){
    MpiSerializeMessage* mpi_msg = m_messages_request[i].m_mpi_message;
    if (done_indexes[i]){
      MPI_Status status = mpi_status[mpi_status_index];
      MPI_Request rq = (MPI_Request)requests[i];
      msg->debug() << "Message number " << i << " Ok, source=" << status.MPI_SOURCE
                   << " tag=" << mpi_status[i].MPI_TAG
                   << " err=" << mpi_status[i].MPI_ERROR
                   << " request=" << rq;
      ++mpi_status_index;
      Request r = this->_processOneMessage(mpi_msg,status.MPI_SOURCE,status.MPI_TAG);
      if (r.isValid()){
        msg->debug() << "Add new receive operation for message number " << i
                     << " request=" << (MPI_Request)r;
        new_messages.add(MpiSerializeMessageRequest(mpi_msg,r));
      }
      else{
        mpi_msg->message()->setFinished(true);
        ++nb_message_finished;
        delete mpi_msg;
      }
    }
    else{
      msg->debug() << "Message number " << i << " not finished"
                   << " request=" << (MPI_Request)requests[i];
      new_messages.add(MpiSerializeMessageRequest(mpi_msg,requests[i]));
    }
  }
  m_messages_request = new_messages;
  if (m_messages_request.empty())
    return (-1);
  return nb_message_finished;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Effectue la requête. Retourne une éventuelle requête si non nul.
 */
Request MpiSerializeMessageList::
_processOneMessage(MpiSerializeMessage* msm, int source, int mpi_tag)
{
  Request request;
  m_trace->debug() << "Process one message msg=" << this
                   << " number=" << msm->messageNumber()
                   << " is_send=" << msm->message()->isSend();
  if (msm->message()->isSend())
    return request;
  return _processOneMessageGlobalBuffer(msm,source,mpi_tag);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Effectue la requête. Retourne une éventuelle requête si non nul.
 */
Request MpiSerializeMessageList::
_processOneMessageGlobalBuffer(MpiSerializeMessage* msm,int source,int mpi_tag)
{
  Request request;
  m_trace->debug() << "Process one message (GlobalBuffer) msg=" << this
                   << " number=" << msm->messageNumber()
                   << " is_send=" << msm->message()->isSend();

  Int32 dest_rank = msm->message()->destRank();
  if (dest_rank==A_NULL_RANK)
    // Signife que le message était un MPI_ANY_SOURCE
    dest_rank = static_cast<Int32>(source);
  BasicSerializer* sbuf = msm->serializeBuffer();

  Int64 message_size = sbuf->totalSize();

  // S'il s'agit du premier message, récupère la longueur totale.
  // et si le message total est trop gros (>m_serialize_buffer_size)
  // poste un nouveau message pour récupèrer les données sérialisées.
  if (msm->messageNumber()==0){
    if (message_size<=m_dispatcher->serializeBufferSize()){
      sbuf->setFromSizes();
      return request;
    }
    m_dispatcher->_checkBigMessage(message_size);
    sbuf->preallocate(message_size);
    Span<Byte> bytes = sbuf->globalBuffer();
    request = m_dispatcher->recvSerializerBytes(bytes,dest_rank,mpi_tag+1,false);
    msm->incrementMessageNumber();
    return request;
  }
  sbuf->setFromSizes();
  return request;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arccore::MessagePassing::Mpi

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
