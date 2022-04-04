add_subdirectory(ImageEditor)
add_subdirectory(Color)

target_sources(neoimp PUBLIC
  DimensionalQuantityEdit.hpp
  ResolutionQuantityEdit.hpp
  LengthQuantityEdit.hpp
  ResolutionQuantityEdit.cpp
  LengthQuantityEdit.cpp
)
