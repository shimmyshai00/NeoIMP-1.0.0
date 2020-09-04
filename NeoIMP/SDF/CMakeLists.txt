add_library(SDF STATIC)

add_subdirectory(ModelLayer)
add_subdirectory(UILayer)

target_link_libraries(SDF UILayer)
