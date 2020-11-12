target_include_directories(Qt PUBLIC .)

add_subdirectory(QtResources)
add_subdirectory(CustomWidgets)

target_sources(Qt PUBLIC
  NewDocumentDialog.cpp
  MainWindow.cpp
)
