target_include_directories(DocumentModel PRIVATE ".")

target_sources(DocumentModel PRIVATE
  IColorChannel.hpp
  IRGBColor.hpp
  ICMYKColor.hpp
  TColorChannel.hpp
  TColorChannel.tpp
  TRGBColor.hpp
  TRGBColor.tpp
  TCMYKColor.hpp
  TCMYKColor.tpp
  ColorTypes.hpp
)
