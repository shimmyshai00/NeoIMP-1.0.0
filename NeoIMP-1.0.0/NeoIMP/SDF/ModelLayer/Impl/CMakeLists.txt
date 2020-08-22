target_include_directories(ModelLayer PRIVATE ".")

target_sources(ModelLayer PRIVATE
  CModelLayer.hpp
  CModelLayer.cpp
)

target_sources(ModelLayer PUBLIC PRIVATE
  IModelLayer.cpp
)

add_subdirectory(DocumentModel)

target_link_libraries(ModelLayer PRIVATE DocumentModel)
