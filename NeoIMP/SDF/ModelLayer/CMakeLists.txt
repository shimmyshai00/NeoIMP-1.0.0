add_library(ModelLayer STATIC
  Impl/CModelLayer.cpp
  Impl/IModelLayer.cpp)

add_subdirectory(DocumentModel)

target_include_directories(ModelLayer PRIVATE ${CMAKE_SOURCE_DIR} .)
target_include_directories(ModelLayer PUBLIC include)
target_link_libraries(ModelLayer DocumentModel)
