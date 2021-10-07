﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2021 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* DependencyInjection.h                                       (C) 2000-2021 */
/*                                                                           */
/* Types et fonctions pour gérer le pattern 'DependencyInjection'.           */
/*---------------------------------------------------------------------------*/
#ifndef ARCANE_DEPENDENCYINJECTION_H
#define ARCANE_DEPENDENCYINJECTION_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*
 * NOTE: API en cours de définition. Ne pas utiliser.
 */

#include "arcane/utils/Ref.h"
#include "arcane/utils/ExternalRef.h"

#include "arccore/base/ReferenceCounterImpl.h"

//TODO Mettre le lancement des exceptions dans le '.cc'
#include "arcane/utils/NotImplementedException.h"
#include "arcane/utils/FatalErrorException.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane::DependencyInjection
{

class Injector;
namespace impl
{
class FactoryInfo;
class IInstanceFactory;
template<typename InterfaceType>
class IConcreteFactory;
}

}

ARCCORE_DECLARE_REFERENCE_COUNTED_CLASS(Arcane::DependencyInjection::impl::IInstanceFactory)

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane::DependencyInjection
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class ARCANE_UTILS_EXPORT IInjectedInstance
{
 public:

  virtual ~IInjectedInstance() = default;
  virtual bool hasName(const String& str) const =0;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \warning Cette classe est utilisées dans des constructeurs/destructeurs
 * globaux et ne doit pas faire d'allocation/désallocation ni utiliser de
 * types qui en font.
 */
class ARCANE_UTILS_EXPORT ProviderProperty
{
 public:
  ProviderProperty(const char* name) : m_name(name){}
 public:
  const char* name() const { return m_name; }
 private:
  const char* m_name;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace impl
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Interface typée gérant l'instance d'un service.
 */
template<typename InterfaceType>
class IInjectedInstanceT
: public IInjectedInstance
{
 public:
  virtual Ref<InterfaceType> instance() =0;
 private:
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Interface typée gérant l'instance d'un service.
 */
template<typename InterfaceType>
class InjectedInstance
: public IInjectedInstanceT<InterfaceType>
{
 public:
  InjectedInstance(Ref<InterfaceType> t_instance,const String& t_name)
  : m_instance(t_instance), m_name(t_name){}
 public:
  Ref<InterfaceType> instance() override { return m_instance; }
  bool hasName(const String& str) const override { return m_name==str; }
 private:
  Ref<InterfaceType> m_instance;
  String m_name;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Interface typée gérant une instance
 */
template<typename Type>
class IInjectedValueInstance
: public IInjectedInstance
{
 public:
  virtual Type instance() =0;
 private:
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Interface typée gérant l'instance d'un service.
 */
template<typename Type>
class InjectedValueInstance
: public IInjectedValueInstance<Type>
{
 public:
  InjectedValueInstance(Type t_instance,const String& t_name)
  : m_instance(t_instance), m_name(t_name){}
 public:
  Type instance() override { return m_instance; }
  bool hasName(const String& str) const override { return m_name==str; }
 private:
  Type m_instance;
  String m_name;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Référence sur une instance injectée.
 *
 * Cette classe est gérée via un compteur de référence à la manière
 * de la classe std::shared_ptr.
 */
class ARCANE_UTILS_EXPORT InjectedInstanceRef
{
  typedef Ref<IInjectedInstance> RefType;
 private:
  InjectedInstanceRef(const RefType& r) : m_instance(r){}
 public:
  InjectedInstanceRef() = default;
 public:
  static InjectedInstanceRef createRef(IInjectedInstance* p)
  {
    return InjectedInstanceRef(RefType::create(p));
  }
  static InjectedInstanceRef createRefNoDestroy(IInjectedInstance* p)
  {
    return InjectedInstanceRef(RefType::_createNoDestroy(p));
  }
  static InjectedInstanceRef createWithHandle(IInjectedInstance* p,Internal::ExternalRef handle)
  {
    return InjectedInstanceRef(RefType::createWithHandle(p,handle));
  }
 public:
  IInjectedInstance* get() const { return m_instance.get(); }
  void reset() { m_instance.reset(); }
 private:
  RefType m_instance;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Fabrique pour une instance encapsulée par une référence (i.e Ref<T>).
 */
class ARCANE_UTILS_EXPORT IInstanceFactory
{
  ARCCORE_DECLARE_REFERENCE_COUNTED_INCLASS_METHODS();

 protected:

  virtual ~IInstanceFactory() = default;

 public:

  virtual InjectedInstanceRef createGenericReference(Injector& injector,const String& name) =0;

  virtual const FactoryInfo* factoryInfo() const =0;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief internal.
 * \brief Classe de base pour une fabrique.
 *
 * Cette classe s'utiliser via un ReferenceCounter pour gérer sa destruction.
 */
class ARCANE_CORE_EXPORT AbstractInstanceFactory
: public ReferenceCounterImpl
, public IInstanceFactory
{
  ARCCORE_DEFINE_REFERENCE_COUNTED_INCLASS_METHODS();
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename InterfaceType>
class InstanceFactory
: public AbstractInstanceFactory
{
 public:

  InstanceFactory(FactoryInfo* si,IConcreteFactory<InterfaceType>* sub_factory)
  : m_factory_info(si), m_sub_factory(sub_factory)
  {
  }

  ~InstanceFactory() override
  {
    delete m_sub_factory;
  }

  InjectedInstanceRef createGenericReference(Injector& injector,const String& name) override
  {
    return _create(_createReference(injector),name);
  }

  Ref<InterfaceType> createReference(Injector& injector)
  {
    return _createReference(injector);
  }

  const FactoryInfo* factoryInfo() const override
  {
    return m_factory_info;
  }

 protected:

  FactoryInfo* m_factory_info;
  IConcreteFactory<InterfaceType>* m_sub_factory;

 private:

  Ref<InterfaceType> _createReference(Injector& injector)
  {
    return m_sub_factory->createReference(injector);
  }

  InjectedInstanceRef _create(Ref<InterfaceType> it,const String& name)
  {
    IInjectedInstance* x = (!it) ? nullptr : new InjectedInstance<InterfaceType>(it,name);
    return InjectedInstanceRef::createRef(x);
  }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Interface d'un fonctor de création d'une instance de service
 * correspondant à l'interface \a InterfaceType.
 */
template<typename InterfaceType>
class IConcreteFactory
{
 public:
  virtual ~IConcreteFactory() = default;
 public:
  //! Créé une instance du service .
  virtual Ref<InterfaceType> createReference(Injector&) =0;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Fabrique pour le service \a ServiceType pour l'interface \a InterfaceType.
 */
template<typename ServiceType,typename InterfaceType>
class ConcreteFactory
: public IConcreteFactory<InterfaceType>
{
 public:

  Ref<InterfaceType> createReference(Injector& injector) override
  {
    ServiceType* st = new ServiceType(injector);
    return makeRef<InterfaceType>(st);
  }
};


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 */
template<typename ServiceType,typename ConstructorType>
class Concrete2Factory
{
 public:

  template<typename Args>
  ServiceType* create(const Args& tuple_args)
  {
    ServiceType* st = std::apply([](auto &&... args) -> ServiceType* { return new ServiceType(args...); }, tuple_args);
    return st;
  }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Informations pour une fabrique.
 */
class ARCANE_UTILS_EXPORT FactoryInfo
{
  friend class Arcane::DependencyInjection::Injector;
  class Impl;
 public:
  FactoryInfo(const FactoryInfo&) = delete;
  FactoryInfo& operator=(const FactoryInfo&) = delete;
  ~FactoryInfo();
 private:
  FactoryInfo(const ProviderProperty& property);
 public:
  static FactoryInfo* create(const ProviderProperty& property,const char* file_name,int line_number)
  {
    ARCANE_UNUSED(file_name);
    ARCANE_UNUSED(line_number);
    return new FactoryInfo(property);
  }
  void addFactory(Ref<IInstanceFactory> f);
  bool hasName(const String& str) const;
 private:
  Impl* m_p = nullptr;
};


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class ARCANE_UTILS_EXPORT GlobalRegisterer
{
 public:

  typedef FactoryInfo* (*FactoryCreateFunc)(const ProviderProperty& property);

 public:

  /*!
   * \brief Crée en enregistreur pour le service \a name et la fonction \a func.
   *
   * Ce constructeur est utilisé pour enregistrer un service.
   */
 GlobalRegisterer(FactoryCreateFunc func,const ProviderProperty& property) ARCANE_NOEXCEPT;

 public:

  FactoryCreateFunc infoCreatorWithPropertyFunction() { return m_factory_create_func; }

  //! Nom du service
  const char* name() { return m_name; }

  const ProviderProperty& property() const { return m_factory_property; }

  //! Service précédent (0 si le premier)
  GlobalRegisterer* previousService() const { return m_previous; }

  //! Service suivant (0 si le dernier)
  GlobalRegisterer* nextService() const { return m_next; }

 public:

  //! Accès au premier élément de la chaine d'enregistreur de service
  static GlobalRegisterer* firstService();

  //! Nombre d'enregisteur de service dans la chaine
  static Integer nbService();

 private:

  FactoryCreateFunc m_factory_create_func = nullptr;
  const char* m_name = nullptr;
  ProviderProperty m_factory_property;
  GlobalRegisterer* m_previous = nullptr;
  GlobalRegisterer* m_next = nullptr;

 private:

  void _init();

  //! Positionne le service précédent
  /*! Utilisé en interne pour construire la chaine de service */
  void _setPreviousService(GlobalRegisterer* s) { m_previous = s; }

  //! Positionne le service suivant
  /*! Utilisé en interne pour construire la chaine de service */
  void _setNextService(GlobalRegisterer* s) { m_next = s; }
};


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Classe permettant d'enregistrer une fabrique pour un service
 * implémentant l'interface \a InterfaceType.
 */
template<typename InterfaceType>
class ServiceInterfaceRegisterer
{
 public:

  static constexpr bool isConstructor() { return false; }

  typedef InterfaceType Interface;

  explicit ServiceInterfaceRegisterer(const char* name)
  : m_name(name), m_namespace_name(nullptr)
  {
  }

  ServiceInterfaceRegisterer(const char* namespace_name,const char* name)
  : m_name(name), m_namespace_name(namespace_name)
  {
  }

 public:

  //! Enregistre dans \a si une fabrique pour créer une instance du service \a ServiceType
  template<typename ServiceType> void
  registerToFactoryInfo(FactoryInfo* si) const
  {
    IConcreteFactory<InterfaceType>* factory = new ConcreteFactory<ServiceType,InterfaceType>();
    si->addFactory(makeRef<IInstanceFactory>(new InstanceFactory<InterfaceType>(si,factory)));
  }

 private:

  const char* m_name;
  const char* m_namespace_name;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Classe permettant d'enregistrer un constructeur pour créer un service.
 */
template<typename InterfaceType>
class ConstructorRegisterer
{
 public:

  static constexpr bool isConstructor() { return true; }

  ConstructorRegisterer()
  {
  }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Classe permettant de créer et d'enregistrer les fabriques pour un service.
 */
template<typename ServiceType>
class ServiceAllInterfaceRegisterer
{
 private:

  //! Surcharge pour 1 interface
  template <typename InterfaceType> static void
  _create(FactoryInfo* si, const InterfaceType& i1)
  {
    if constexpr (InterfaceType::isConstructor()) {
      Concrete2Factory<ServiceType, InterfaceType> c2f;
      ARCANE_UNUSED(si);
      ARCANE_UNUSED(c2f);
    }
    else
      i1.template registerToFactoryInfo<ServiceType>(si);
  }

  //! Surcharge pour 2 interfaces ou plus
  template<typename I1,typename I2,typename ... OtherInterfaces>
  static void _create(FactoryInfo* si,const I1& i1,const I2& i2,const OtherInterfaces& ... args)
  {
    _create<I1>(si,i1);
    // Applique la récursivité sur les types restants
    _create<I2,OtherInterfaces...>(si,i2,args...);
  }

 public:

  //! Enregistre dans le service les fabriques pour les interfacs \a Interfaces
  template<typename ... Interfaces> static void
  registerProviderInfo(FactoryInfo* si, const Interfaces& ... args)
  {
    //si->setSingletonFactory(new Internal::SingletonServiceFactory<ServiceType,typename Interfaces::Interface ... >(si));
    _create(si,args...);
  }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace impl

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 */
class ARCANE_UTILS_EXPORT Injector
{
  class Impl;

 public:
  Injector();
  Injector(const Injector&) = delete;
  Injector& operator=(const Injector&) = delete;
  ~Injector() = default;

 public:
  template <typename InterfaceType> void
  bind(Ref<InterfaceType> iref, const String& name = String())
  {
    auto* x = new impl::InjectedInstance<InterfaceType>(iref, name);
    _add(x);
  }

  template <typename Type> void
  bind(Type iref, const String& name = String())
  {
    auto* x = new impl::InjectedValueInstance<Type>(iref, name);
    _add(x);
  }

  template <typename Type> Type
  get(const String& name = String())
  {
    return _getValue<Type>(name);
  }

  template <typename InterfaceType> Ref<InterfaceType>
  getRef(const String& name = String())
  {
    return _getRef<InterfaceType>(name);
  }

  template <typename InterfaceType> Ref<InterfaceType>
  createInstance(const String& service_name = String())
  {
    using FactoryType = impl::InstanceFactory<InterfaceType>;
    Ref<InterfaceType> instance;
    auto f = [&](impl::IInstanceFactory* v) -> bool {
      auto* t = dynamic_cast<FactoryType*>(v);
      if (t) {
        Ref<InterfaceType> x = t->createReference(*this);
        if (x.get()) {
          instance = x;
          return true;
        }
      }
      return false;
    };
    _iterateFactories(service_name, f);
    if (instance.get())
      return instance;
    // TODO: améliorer le message
    ARCANE_FATAL("Can not create instance");
    return instance;
  }

  void fillWithGlobalFactories();

 private:
  Impl* m_p = nullptr;

 private:
  void _add(IInjectedInstance* instance);

  // Itère sur la lambda et s'arrête dès que cette dernière retourne \a true
  template <typename Lambda> void
  _iterateInstances(const String& instance_name, const Lambda& lambda)
  {
    bool has_no_name = instance_name.empty();
    Integer n = _nbValue();
    for (Integer i = 0; i < n; ++i) {
      IInjectedInstance* ii = _value(i);
      if (has_no_name || ii->hasName(instance_name))
        if (lambda(ii))
          return;
    }
  }
  Integer _nbValue() const;
  IInjectedInstance* _value(Integer i) const;

  /*!
   * \brief Itère sur la lambda et s'arrête dès que cette dernière retourne \a true.
   * Si \a factory_name n'est pas nul, seules les fabriques pour lequelles
   * FactoryInfo::hasName(factory_name) est vrai sont utilisées.
   */
  template <typename Lambda> void
  _iterateFactories(const String& factory_name, const Lambda& lambda)
  {
    bool has_no_name = factory_name.empty();
    Integer n = _nbFactory();
    for (Integer i = 0; i < n; ++i) {
      impl::IInstanceFactory* f = _factory(i);
      if (has_no_name || f->factoryInfo()->hasName(factory_name))
        if (lambda(f))
          return;
    }
  }
  Integer _nbFactory() const;
  impl::IInstanceFactory* _factory(Integer i) const;

  // Spécialisation pour les références
  template <typename InterfaceType> Ref<InterfaceType>
  _getRef(const String& instance_name)
  {
    using InjectedType = impl::IInjectedInstanceT<InterfaceType>;
    InjectedType* t = nullptr;
    auto f = [&](IInjectedInstance* v) -> bool {
      t = dynamic_cast<InjectedType*>(v);
      return t;
    };
    _iterateInstances(instance_name, f);
    if (t)
      return t->instance();
    // TODO: faire un fatal ou créer l'instance
    ARCANE_THROW(NotImplementedException, "Create Ref<InterfaceType> from factory");
  }

  template <typename Type> Type
  _getValue(const String& instance_name)
  {
    using InjectedType = impl::IInjectedValueInstance<Type>;
    InjectedType* t = nullptr;
    auto f = [&](IInjectedInstance* v) -> bool {
      t = dynamic_cast<InjectedType*>(v);
      return t;
    };
    _iterateInstances(instance_name, f);
    if (t)
      return t->instance();
    ARCANE_FATAL("Can not find value for type");
  }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#define ARCANE_DI_CONSTRUCTOR(args)\
  ::Arcane::DependencyInjection::impl::ConstructorRegisterer< void args >()

#define ARCANE_DI_SERVICE_INTERFACE(ainterface)                         \
  ::Arcane::DependencyInjection::impl::ServiceInterfaceRegisterer< ainterface >(#ainterface)

#define ARCANE_DI_SERVICE_INTERFACE_NS(ainterface_ns,ainterface) \
  ::Arcane::DependencyInjection::impl::ServiceInterfaceRegisterer<ainterface_ns :: ainterface>(#ainterface_ns,#ainterface)

// TODO: garantir au moins une interface

#define ARCANE_DI_REGISTER_PROVIDER(t_class,t_provider_property,...)  \
namespace\
{\
  Arcane::DependencyInjection::impl::FactoryInfo*                       \
  ARCANE_JOIN_WITH_LINE(arcaneCreateDependencyInjectionProviderInfo##t_class) (const Arcane::DependencyInjection::ProviderProperty& property) \
  {\
    auto* si = Arcane::DependencyInjection::impl::FactoryInfo::create(property,__FILE__,__LINE__); \
    Arcane::DependencyInjection::impl::ServiceAllInterfaceRegisterer<t_class> :: registerProviderInfo(si,__VA_ARGS__); \
    return si;\
  }\
}\
 Arcane::DependencyInjection::impl::GlobalRegisterer ARCANE_EXPORT ARCANE_JOIN_WITH_LINE(globalServiceRegisterer##aclass) \
  (& ARCANE_JOIN_WITH_LINE(arcaneCreateDependencyInjectionProviderInfo##t_class),t_provider_property)

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane::DependencyInjection

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
