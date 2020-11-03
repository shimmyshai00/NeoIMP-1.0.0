set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(Qt QtApplication.cpp)

add_subdirectory(Controller)
add_subdirectory(View)

target_link_libraries(Qt Controller View Qt5::Widgets)
