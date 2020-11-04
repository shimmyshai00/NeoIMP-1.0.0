add_library(View MainWindow.cpp
  NewDocumentDialog.cpp)

add_subdirectory(QtResources)
add_subdirectory(CustomWidgets)
target_link_libraries(View QtResources CustomWidgets Qt5::Widgets)
