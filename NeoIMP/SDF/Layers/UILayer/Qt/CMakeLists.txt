add_library(Qt CQtApplication.cpp)
add_subdirectory(Controller)
add_subdirectory(View)

target_link_libraries(Qt Controller View Qt5::Widgets)
