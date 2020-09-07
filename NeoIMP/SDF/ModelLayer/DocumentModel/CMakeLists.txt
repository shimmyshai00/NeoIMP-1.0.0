add_library(DocumentModel STATIC
  Impl/DomainObjects/Color/CRGBColor.cpp
  Impl/DomainObjects/Color/CCMYKColor.cpp
  Impl/DomainObjects/CLayer.cpp
  Impl/DomainObjects/CDocument.cpp
  Impl/DomainObjects/CDocumentRepository.cpp
  Impl/Services/CDocumentService.cpp
  Impl/Services/CDocumentModelInformationService.cpp
  Impl/Services/CDocumentMeasurementsService.cpp
  Impl/Services/CDocumentImageDataService.cpp
  Impl/CDocumentModel.cpp
  Impl/IDocumentModel.cpp)

target_include_directories(DocumentModel PRIVATE ${CMAKE_SOURCE_DIR} .)
target_include_directories(DocumentModel PUBLIC include)
