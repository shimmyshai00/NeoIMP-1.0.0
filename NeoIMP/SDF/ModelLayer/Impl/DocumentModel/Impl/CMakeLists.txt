add_subdirectory(DomainObjects)
add_subdirectory(Services)
target_include_directories(DocumentModel PRIVATE ".")

target_sources(DocumentModel PRIVATE
  CDocumentModel.hpp
  CDocumentModel.cpp
)

target_sources(DocumentModel PUBLIC PRIVATE
  IDocumentModel.cpp
)
