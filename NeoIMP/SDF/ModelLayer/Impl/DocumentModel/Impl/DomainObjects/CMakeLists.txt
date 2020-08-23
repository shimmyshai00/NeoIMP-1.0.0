add_subdirectory(Color)
target_include_directories(DocumentModel PRIVATE ".")

target_sources(DocumentModel PRIVATE
  SUnit.hpp
  Units.hpp
  CUnitConverter.hpp
  CUnitConverter.cpp
  IAlphaOperation.hpp
  IColorOperation.hpp
  CLayer.hpp
  CLayer.cpp
  CDocument.hpp
  CDocument.cpp
  CDocumentLibrary.hpp
  CDocumentLibrary.cpp
)
