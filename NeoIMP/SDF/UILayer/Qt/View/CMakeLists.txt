add_library(View MainWindow.cpp)
add_subdirectory(QtResources)
target_link_libraries(View QtResources Qt5::Widgets)
