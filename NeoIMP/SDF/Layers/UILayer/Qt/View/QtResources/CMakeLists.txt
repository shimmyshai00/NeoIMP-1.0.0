add_library(QtResources MainWindow.qrc
  MainWindow.ui
  NewDocumentDialog.ui)

target_sources(QtResources PUBLIC Icons.qrc)
