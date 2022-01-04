set(CURRENT_SRC_PATH  ${Arcane_SOURCE_DIR}/src)
set( ARCANE_SOURCES    AbstractCaseDocumentVisitor.cc
   AbstractCaseDocumentVisitor.h
   AbstractDataVisitor.cc
   AbstractDataVisitor.h
   AbstractModule.cc
   AbstractModule.h
   AbstractService.cc
   AbstractService.h
   AbstractItemOperationByBasicType.cc
   AbstractItemOperationByBasicType.h
   AcceleratorRuntimeInitialisationInfo.h
   ArcaneTypes.cc
   ArcaneTypes.h
   ApplicationBuildInfo.cc
   ApplicationBuildInfo.h
   Array2Variable.cc
   Array2Variable.h
   Assertion.h
   Assertion.cc
   CaseDatasetSource.h
   CaseDatasetSource.cc
   CaseOptionsMain.cc
   CaseOptionsMain.h
   BasicModule.cc
   BasicModule.h
   BasicService.cc
   BasicService.h
   BasicUnitTest.cc
   BasicUnitTest.h
   CaseFunction.cc
   CaseFunction.h
   CaseNodeNames.cc
   CaseNodeNames.h
   CaseOptionBase.cc
   CaseOptionBase.h
   CaseOptionBuildInfo.cc
   CaseOptionBuildInfo.h
   CaseOptions.cc
   CaseOptions.h
   CaseOptionError.cc
   CaseOptionError.h
   CaseOptionException.cc
   CaseOptionException.h
   CaseOptionList.cc
   CaseOptionService.cc
   CaseOptionService.h
   CaseOptionServiceImpl.h
   CaseOptionTypes.h
   CaseTable.cc
   CaseTable.h
   CaseTableParams.cc
   CaseTableParams.h
   CodeService.cc
   CodeService.h
   Concurrency.cc
   Concurrency.h
   Connectivity.cc
   Connectivity.h
   core/internal/IDataInternal.h
   core/internal/ICartesianMeshGenerationInfo.h
   core/internal/CartesianMeshGenerationInfo.h
   core/internal/CartesianMeshGenerationInfo.cc
   Data.cc
   DataTypeDispatchingDataVisitor.cc
   DataTypeDispatchingDataVisitor.h
   DotNetRuntimeInitialisationInfo.cc
   DotNetRuntimeInitialisationInfo.h
   EntryPoint.cc
   EntryPoint.h
   FactoryService.cc
   FactoryService.h
   GeometricUtilities.cc
   GeometricUtilities.h
   GroupIndexTable.cc
   GroupIndexTable.h
   InterfaceImpl.cc
   IndexedItemConnectivityView.h
   Item.cc
   Item.h
   ItemEnumerator.cc
   ItemEnumerator.h
   ItemFunctor.cc
   ItemFunctor.h
   ItemPairEnumerator.cc
   ItemPairEnumerator.h
   ItemPairGroup.cc
   ItemPairGroup.h
   ItemPairGroupBuilder.cc
   ItemPairGroupBuilder.h
   ItemPairGroupImpl.cc
   ItemPairGroupImpl.h
   ItemGroupImpl.cc
   ItemGroupImpl.h
   ItemGroup.cc
   ItemGroup.h
   ItemGroupComputeFunctor.cc
   ItemGroupComputeFunctor.h
   ItemGroupRangeIterator.cc
   ItemGroupRangeIterator.h
   ItemInternal.cc
   ItemInternal.h
   ItemSharedInfo.cc
   ItemSharedInfo.h
   ItemTypeInfo.cc
   ItemTypeInfo.h
   ItemTypeInfoBuilder.cc
   ItemTypeInfoBuilder.h
   ItemTypeMng.cc
   ItemTypeMng.h
   MeshAccessor.cc
   MeshAccessor.h
   MeshArea.cc
   MeshArea.h
   MeshAreaAccessor.cc
   MeshAreaAccessor.h
   MeshHandle.h
   MeshHandle.cc
   MeshPartInfo.cc
   MeshPartInfo.h
   MeshVisitor.cc
   MeshVisitor.h
   MeshStats.cc
   MeshStats.h
   ModuleBuildInfo.cc
   ModuleBuildInfo.h
   ModuleFactory.cc
   ModuleFactory.h
   NullXmlDocumentHolder.cc
   Observable.h
   Observer.h
   ObserverPool.cc
   ObserverPool.h
   OutputChecker.cc
   OutputChecker.h
   PreciseOutputChecker.cc
   PreciseOutputChecker.h
   Parallel.cc
   Parallel.h
   Properties.cc
   Properties.h
   RessourceMng.cc
   StringDictionary.h
   XmlNode.cc
   XmlNode.h
   XmlNodeList.cc
   XmlNodeList.h
   XmlProperty.cc
   XmlProperty.h
   DomUtils.cc
   DomUtils.h
   DomLibXml2V2.cc
   SerializedData.cc
   SerializeBuffer.cc
   SerializeBuffer.h
   SimpleSVGMeshExporter.h
   SimpleSVGMeshExporter.cc
   TimeLoop.cc
   TimeLoop.h
   Timer.cc
   Timer.h
   TemporaryVariableBuildInfo.cc
   TemporaryVariableBuildInfo.h
   Directory.cc
   Directory.h
   SharedReference.cc
   SharedReference.h
   StandardCaseFunction.cc
   StandardCaseFunction.h
   ParallelMngDispatcher.cc
   ParallelMngDispatcher.h
   ParallelMngUtils.h
   ParallelMngUtils.cc
   ParallelNonBlockingCollectiveDispatcher.cc
   ParallelNonBlockingCollectiveDispatcher.h
   ParallelSuperMngDispatcher.cc
   ParallelSuperMngDispatcher.h
   CheckpointService.cc
   CheckpointService.h
   CheckpointInfo.cc
   CheckpointInfo.h
   Variable.cc
   Variable.h
   VariableInfo.cc
   VariableInfo.h
   VariableRef.cc
   VariableRef.h
   VariableTypeInfo.h
   VariableTypeInfo.cc
   VariableBuildInfo.cc
   VariableBuildInfo.h
   VariableRefScalar.cc
   VariableRefScalar.h
   VariableRefArray.cc
   VariableRefArray.h
   VariableRefArray2.cc
   VariableRefArray2.h
   VariableScalar.cc
   VariableScalar.h
   VariableSynchronizerEventArgs.cc
   VariableSynchronizerEventArgs.h
   VariableArray.cc
   VariableArray.h
   VariableDependInfo.cc
   VariableDependInfo.h
   VariableExpressionImpl.cc
   VariableExpressionImpl.h
   VariableMetaData.cc
   VariableMetaData.h
   VariableFactory.cc
   VariableFactory.h
   VerifierService.cc
   VerifierService.h
   MeshUtils.cc
   MeshUtils.h
   MeshVariableRef.cc
   MeshVariableRef.h
   PrivateVariableScalarTpl.cc
   PrivateVariableArrayTpl.cc
   MeshVariableTpl.cc
   MeshVariableTplArray.cc
   GroupIndexTable.cc
   GroupIndexTable.h
   ServiceFactory.cc
   ServiceFactory.h
   ServiceBuildInfo.cc
   ServiceBuildInfo.h
   ServiceBuilder.cc
   ServiceBuilder.h
   ServiceInfo.cc
   ServiceInfo.h
   ServiceInstance.h
   ServiceRegisterer.cc
   ServiceRegisterer.h
   SimdItem.cc
   SimdItem.h
   PostProcessorWriterBase.cc
   PostProcessorWriterBase.h
   ModuleMaster.cc
   ModuleMaster.h
   SerializeMessage.cc
   SerializeMessage.h
   SubDomainBuildInfo.cc
   SubDomainBuildInfo.h
   ArcaneException.cc
   ArcaneException.h
   CommonVariables.cc
   CommonVariables.h
   VariableFactoryRegisterer.cc
   VariableFactoryRegisterer.h
   MathUtils.cc
   MathUtils.h
   Property.cc
   SequentialSection.cc
   SequentialSection.h
   ItemPrinter.cc
   ItemPrinter.h
   MeshToMeshTransposer.cc
   MeshToMeshTransposer.h
   ItemRefinementPattern.cc
   ItemRefinementPattern.h
   SynchronizerMatrixPrinter.cc
   SynchronizerMatrixPrinter.h
   datatype/ArrayVariant.cc
   datatype/ArrayVariant.h
   datatype/BadVariantTypeException.cc
   datatype/BadVariantTypeException.h
   datatype/DataStorageTypeInfo.h
   datatype/DataStorageTypeInfo.cc
   datatype/DataTracer.cc
   datatype/DataTracer.h
   datatype/DataTypes.cc
   datatype/DataTypes.h
   datatype/ScalarVariant.cc
   datatype/ScalarVariant.h
   datatype/SmallVariant.cc
   datatype/SmallVariant.h
   datatype/VariantBase.cc
   datatype/VariantBase.h
   expr/ArrayExpressionImpl.cc
   expr/ArrayExpressionImpl.h
   expr/BadExpressionException.cc
   expr/BadExpressionException.h
   expr/BadOperandException.cc
   expr/BadOperandException.h
   expr/BadOperationException.cc
   expr/BadOperationException.h
   expr/Expression.cc
   expr/Expression.h
   expr/ExpressionResult.cc
   expr/ExpressionResult.h
   expr/ExpressionImpl.cc
   expr/ExpressionImpl.h
   expr/UnaryExpressionImpl.cc
   expr/UnaryExpressionImpl.h
   expr/LitteralExpressionImpl.cc
   expr/LitteralExpressionImpl.h
   expr/BinaryExpressionImpl.cc
   expr/BinaryExpressionImpl.h
   expr/WhereExpressionImpl.cc
   expr/WhereExpressionImpl.h
   expr/OperatorMng.cc
   expr/OperatorMng.h
   matvec/AMG.cc
   matvec/Matrix.cc
   matvec/Matrix.h
   matvec/Vector.cc
   matvec/Vector.h
   parallel/VariableParallelOperationBase.cc
   parallel/VariableParallelOperationBase.h
   parallel/GhostItemsVariableParallelOperation.cc
   parallel/GhostItemsVariableParallelOperation.h
   parallel/Stat.cc
   parallel/MultiReduce.cc
   AbstractCaseDocumentVisitor.h
   AbstractDataVisitor.h
   AbstractModule.h
   AbstractService.h
   AbstractItemOperationByBasicType.h
   ArcaneTypes.h
   ApplicationBuildInfo.h
   Array2Variable.h
   CaseOptionsMain.h
   BasicModule.h
   BasicService.h
   BasicUnitTest.h
   CaseFunction.h
   CaseNodeNames.h
   CaseOptionBase.h
   CaseOptionBuildInfo.h
   CaseOptions.h
   CaseOptionError.h
   CaseOptionException.h
   CaseOptionService.h
   CaseTable.h
   CaseTableParams.h
   CodeService.h
   Concurrency.h
   Connectivity.h
   DataTypeDispatchingDataVisitor.h
   EntryPoint.h
   FactoryService.h
   GeometricUtilities.h
   GroupIndexTable.h
   Item.h
   ItemEnumerator.h
   ItemFunctor.h
   ItemPairEnumerator.h
   ItemPairGroup.h
   ItemPairGroupBuilder.h
   ItemPairGroupImpl.h
   ItemGroupImpl.h
   ItemGroup.h
   ItemGroupComputeFunctor.h
   ItemGroupRangeIterator.h
   ItemInternal.h
   ItemSharedInfo.h
   ItemTypeInfo.h
   ItemTypeInfoBuilder.h
   ItemTypeMng.h
   MeshAccessor.h
   MeshArea.h
   MeshAreaAccessor.h
   MeshPartInfo.h
   MeshVisitor.h
   MeshStats.h
   ModuleBuildInfo.h
   ModuleFactory.h
   Observable.h
   Observer.h
   ObserverPool.h
   OutputChecker.h
   Parallel.h
   Properties.h
   StringDictionary.h
   XmlNode.h
   XmlNodeList.h
   XmlProperty.h
   DomUtils.h
   SerializeBuffer.h
   TimeLoop.h
   Timer.h
   TemporaryVariableBuildInfo.h
   Directory.h
   SharedReference.h
   StandardCaseFunction.h
   ParallelMngDispatcher.h
   ParallelNonBlockingCollectiveDispatcher.h
   ParallelSuperMngDispatcher.h
   CheckpointService.h
   CheckpointInfo.h
   Variable.h
   VariableInfo.h
   VariableRef.h
   VariableBuildInfo.h
   VariableRefScalar.h
   VariableRefArray.h
   VariableRefArray2.h
   VariableScalar.h
   VariableSynchronizerEventArgs.h
   VariableArray.h
   VariableDependInfo.h
   VariableExpressionImpl.h
   VariableMetaData.h
   VariableFactory.h
   VerifierService.h
   MeshUtils.h
   MeshVariableRef.h
   GroupIndexTable.h
   ServiceFactory.h
   ServiceBuildInfo.h
   ServiceBuilder.h
   ServiceInfo.h
   ServiceRegisterer.h
   SimdItem.h
   PostProcessorWriterBase.h
   ModuleMaster.h
   SerializeMessage.h
   SubDomainBuildInfo.h
   ArcaneException.h
   CommonVariables.h
   VariableFactoryRegisterer.h
   MathUtils.h
   SequentialSection.h
   ItemPrinter.h
   MeshToMeshTransposer.h
   ItemRefinementPattern.h
   SynchronizerMatrixPrinter.h
   Algorithm.h
   BasicTimeLoopService.h
   CaseOptionsMulti.h
   Configuration.h
   ConfigurationPropertyReader.h
   ConnectivityItemVector.h
   EnumeratorTraceWrapper.h
   IArcaneMain.h
   IBackwardMng.h
   IBase.h
   ICaseMng.h
   ICaseDocument.h
   ICaseFunction.h
   ICaseFunctionProvider.h
   ICaseDocumentVisitor.h
   ICaseMeshMasterService.h
   ICaseMeshReader.h
   ICaseMeshService.h
   ICheckpointMng.h
   ICheckpointReader.h
   ICheckpointWriter.h
   IConfiguration.h
   IConfigurationMng.h
   IConfigurationSection.h
   IDeflateService.h
   IServiceMng.h
   IMeshBuilder.h
   IGridMeshPartitioner.h
   IMeshChecker.h
   IMeshPartitionerBase.h
   IMeshUniqueIdMng.h
   IModuleMng.h
   IGetVariablesValuesParallelOperation.h
   IGhostLayerMng.h
   ICodeService.h
   ISubDomain.h
   IServiceInfo.h
   IService.h
   ITransferValuesParallelOperation.h
   IApplication.h
   IDirectExecution.h
   IDirectSubDomainExecuteFunctor.h
   IMainFactory.h
   IDataFactory.h
   IDataFactoryMng.h
   IDataStorageFactory.h
   ISerializer.h
   ISerializedData.h
   IData.h
   IDataReader.h
   IDataReader2.h
   IDataReaderWriter.h
   IDataVisitor.h
   IDataWriter.h
   IDumpRW.h
   IDumpR.h
   IDumpW.h
   IDirectory.h
   ILoadBalanceMng.h
   ItemFamilyCompactInfos.h
   ItemTypes.h
   ItemUniqueId.h
   ItemVectorView.h
   ItemVector.h
   ItemInternalVectorView.h
   ISharedReference.h
   ITimeStats.h
   IInitialPartitioner.h
   IIncrementalItemConnectivity.h
   IItemConnectivity.h
   IItemConnectivityAccessor.h
   IItemConnectivityMng.h
   IItemConnectivityInfo.h
   IItemConnectivitySynchronizer.h
   IItemEnumeratorTracer.h
   IItemFamily.h
   IItemFamilyCompactPolicy.h
   IItemFamilyExchanger.h
   IItemFamilySerializeStep.h
   IItemFamilyPolicyMng.h
   IItemFamilyTopologyModifier.h
   ItemFamilySerializeArgs.h
   IItemFamilySerializer.h
   IItemFamilyNetwork.h
   IItemFamilyModifier.h
   IItemInternalSortFunction.h
   ItemInternalSortFunction.h
   ItemGroupObserver.h
   ITimeHistoryCurveWriter.h
   ITimeHistoryTransformer.h
   ITimeHistoryCurveWriter2.h
   IItemOperationByBasicType.h
   ITimerMng.h
   ITimeLoopMng.h
   IEntryPoint.h
   IEntryPointMng.h
   IMeshPartitionConstraint.h
   IMeshPartitionConstraintMng.h
   IMeshPartitioner.h
   IExtraGhostCellsBuilder.h
   IExtraGhostParticlesBuilder.h
   IMeshArea.h
   IMeshCompactMng.h
   IMeshCompacter.h
   IMeshExchangeMng.h
   IMeshExchanger.h
   IMeshFactoryMng.h
   IMeshMng.h
   IMeshModifier.h
   IMeshReader.h
   IMeshWriter.h
   ICaseOptions.h
   ICaseOptionList.h
   IMeshStats.h
   IMeshUtilities.h
   IMeshWriter.h
   IModule.h
   IParallelNonBlockingCollective.h
   IParallelMng.h
   IParallelMngUtilsFactory.h
   IParallelReplication.h
   IParallelTopology.h
   IParallelSort.h
   IParallelSuperMng.h
   IParallelDispatch.h
   IParallelNonBlockingCollectiveDispatch.h
   IParticleExchanger.h
   IAsyncParticleExchanger.h
   IParallelExchanger.h
   IParticleFamily.h
   IPhysicalUnit.h
   IPhysicalUnitConverter.h
   IPhysicalUnitSystem.h
   IPhysicalUnitSystemService.h
   IProperty.h
   IPropertyMng.h
   IRessourceMng.h
   ITimeLoop.h
   IFactoryService.h
   IObserver.h
   IObservable.h
   IRayMeshIntersection.h
   ISession.h
   IServiceLoader.h
   IServiceAndModuleFactoryMng.h
   ISerializeMessageList.h
   ISerializeMessage.h
   ITiedInterface.h
   ITimeLoopService.h
   IVariable.h
   IVariableReader.h
   IVariableComputeFunction.h
   IVariableFactory.h
   IVariableFilter.h
   IVariableMng.h
   IVariableWriter.h
   IVariableParallelOperation.h
   IVariableSynchronizer.h
   IVerifierService.h
   IVariableUtilities.h
   IServiceFactory.h
   IModuleFactory.h
   IStandardFunction.h
   IXmlDocumentHolder.h
   ItemInternalEnumerator.h
   ItemInternal.h
   ItemArrayEnumerator.h
   ItemGroupRangeIterator.h
   ItemLocalId.h
   ItemLoop.h
   Dom.h
   DomDeclaration.h
   MeshItemInternalList.h
   ModuleProperty.h
   MultiArray2Variable.h
   MultiArray2VariableRef.h
   SimpleProperty.h
   ServiceUtils.h
   ServiceProperty.h
   ServiceFinder.h
   ServiceFinder2.h
   SimdMathUtils.h
   StdNum.h
   TimeLoopEntryPointInfo.h
   UnstructuredMeshConnectivity.h
   UnstructuredMeshConnectivity.cc
   UnitTestServiceAdapter.h
   VariableCollection.h
   VariableCollection.cc
   VariableComputeFunction.h
   VariableList.h
   VariableTypes.h
   VariableTypedef.h
   VariableRefArrayLock.h
   VariableDataTypeTraits.h
   VariableDiff.h
   VariableView.h
   VariableStatusChangedEventArgs.h
   MeshVariable.h
   PrivateVariableScalar.h
   PrivateVariableArray.h
   MeshBuildInfo.h
   MeshBuildInfo.cc
   MeshReaderMng.h
   MeshReaderMng.cc
   MeshVariableScalarRef.h
   MeshPartialVariableScalarRef.h
   MeshVariableArrayRef.h
   MeshPartialVariableArrayRef.h
   MeshVariableInfo.h
   ItemCompare.h
   ItemIndexArrayView.h
   IPostProcessorWriter.h
   IMeshFactory.h
   IModuleMaster.h
   ITimeHistoryMng.h
   IUnitTest.h
   IIOMng.h
   ObservablePool.h
   Service.h
   Factory.h
   XmlInfo.h
   XmlException.h
   XmlNodeIterator.h
   ArcaneVersion.h
   TiedNode.h
   TiedFace.h
   IMesh.h
   IGraph2.h
   IGraphModifier2.h
   IPrimaryMesh.h
   IMeshSubMeshTransition.h
   SharedVariable.h
   ServiceOptions.h
   IExtraGhostItemsBuilder.h
   VariableAccessor.h
   IVariableAccessor.h
   MeshVariableScalarRefT.H
   MeshVariableArrayRefT.H
   MeshPartialVariableScalarRefT.H
   MeshPartialVariableArrayRefT.H
   PrivateVariableScalarT.H
   PrivateVariableArrayT.H
   IMeshBase.h
   datatype/ArrayVariant.h
   datatype/BadVariantTypeException.h
   datatype/DataTracer.h
   datatype/DataTypes.h
   datatype/ScalarVariant.h
   datatype/SmallVariant.h
   datatype/VariantBase.h
   datatype/IDataOperation.h
   datatype/IDataTracer.h
   datatype/DataTypeTraits.h
   datatype/DataStorageBuildInfo.h
   datatype/DataStorageBuildInfo.cc
   expr/ArrayExpressionImpl.h
   expr/BadExpressionException.h
   expr/BadOperandException.h
   expr/BadOperationException.h
   expr/Expression.h
   expr/ExpressionResult.h
   expr/ExpressionImpl.h
   expr/UnaryExpressionImpl.h
   expr/LitteralExpressionImpl.h
   expr/BinaryExpressionImpl.h
   expr/WhereExpressionImpl.h
   expr/OperatorMng.h
   expr/IExpressionImpl.h
   matvec/Matrix.h
   matvec/Vector.h
   parallel/VariableParallelOperationBase.h
   parallel/GhostItemsVariableParallelOperation.h
   parallel/IStat.h
   parallel/IRequestList.h
   parallel/IMultiReduce.h
   parallel/BitonicSort.h
   parallel/BitonicSortT.H
   packages/Variable.h
   packages/Mesh.h
   random/ConstMod.h
   random/InversiveCongruential.h
   random/LinearCongruential.h
   random/MersenneTwister.h
   random/NormalDistribution.h
   random/RandomGlobal.h
   random/TKiss.h
   random/TMrg32k3a.h
   random/Uniform01.h
   random/UniformInt.h
   random/UniformOnSphere.h
   random/UniformSmallInt.h
   anyitem/AnyItem.h
   anyitem/AnyItemGlobal.h
   anyitem/AnyItemPrivate.h
   anyitem/AnyItemArray.h
   anyitem/AnyItemArray2.h
   anyitem/AnyItemFamily.h
   anyitem/AnyItemFamilyObserver.h
   anyitem/AnyItemGroup.h
   anyitem/AnyItem.h
   anyitem/AnyItemLinkFamily.h
   anyitem/AnyItemLinkVariable.h
   anyitem/AnyItemLinkVariableArray.h
   anyitem/AnyItemUserGroup.h
   anyitem/AnyItemVariable.h
   anyitem/AnyItemVariableArray.h
)
