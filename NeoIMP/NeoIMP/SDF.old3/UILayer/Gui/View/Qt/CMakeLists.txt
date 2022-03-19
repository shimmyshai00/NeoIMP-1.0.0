add_subdirectory(CustomWidgets)
add_subdirectory(Resources)

target_sources(neoimp PUBLIC
  MainWindow.cpp
  NewDocumentDialog.cpp
  ViewFactory.cpp
  GuiManager.cpp
  Component.cpp
)
