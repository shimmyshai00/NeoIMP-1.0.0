add_subdirectory(Layers/UILayer/Metrics)
add_subdirectory(Layers/UILayer/Qt)

add_library(SDF IApplication.cpp)
target_link_libraries(SDF Qt)
