set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(UILayer)

add_subdirectory(Qt)

target_link_libraries(UILayer Qt)
