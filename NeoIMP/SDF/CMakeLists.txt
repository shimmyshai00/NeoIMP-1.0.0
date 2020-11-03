set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(SDF)

add_subdirectory(DataLayer)
add_subdirectory(ModelLayer)
add_subdirectory(UILayer)

target_link_libraries(SDF DataLayer ModelLayer UILayer)
