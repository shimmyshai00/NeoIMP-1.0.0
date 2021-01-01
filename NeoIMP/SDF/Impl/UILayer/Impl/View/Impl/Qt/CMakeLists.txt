target_include_directories(neoimp PUBLIC .)

add_subdirectory(QtResources)
add_subdirectory(CustomWidgets)
add_subdirectory(Windows)
add_subdirectory(Dialogs)

target_sources(neoimp PUBLIC
  ApplicationView.cpp
  NewDocumentView.cpp
  OpenDocumentsView.cpp
  ViewManager.cpp
)
