add_subdirectory(Layers/UILayer)

add_library(SDF IApplication.cpp)
target_link_libraries(SDF UILayer)
