add_subdirectory(Param)

target_sources(ModelLayer PUBLIC
  DocumentHandle.hpp
  Exceptions.hpp
  IDocumentService.hpp
  IDocumentServiceDependency.hpp
  IDocumentModel.hpp
  IDocumentModelDependency.hpp
  IModelLayer.hpp
)
