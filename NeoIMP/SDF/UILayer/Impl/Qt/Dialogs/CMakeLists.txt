target_include_directories(UILayer PRIVATE ".")

target_sources(UILayer PUBLIC
  NewDocumentDialog.ui
)

target_sources(UILayer PRIVATE
  CNewDocumentDimensionCalc.hpp
  CNewDocumentDimensionCalc.cpp
  CNewDocumentDialog.hpp
  CNewDocumentDialog.cpp
)
