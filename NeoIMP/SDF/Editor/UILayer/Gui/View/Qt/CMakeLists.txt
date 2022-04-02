add_subdirectory(CustomWidgets)
add_subdirectory(Resources)

target_sources(neoimp PUBLIC
  MainWindow.cpp
  NewDocumentDialog.cpp
  FileChooserDialog.cpp
  DocumentView.cpp
  ViewFactory.cpp
  ViewManager.cpp
  getComponent.cpp
)
