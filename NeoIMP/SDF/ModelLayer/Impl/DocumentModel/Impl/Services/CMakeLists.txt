target_include_directories(DocumentModel PRIVATE ".")

target_sources(DocumentModel PRIVATE
  CDocumentService.hpp
  CDocumentService.cpp
  CDocumentModelInformationService.hpp
  CDocumentModelInformationService.cpp
  CDocumentMeasurementsService.hpp
  CDocumentMeasurementsService.cpp
)
