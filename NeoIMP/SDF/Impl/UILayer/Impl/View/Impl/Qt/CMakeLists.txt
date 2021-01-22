target_include_directories(neoimp PUBLIC .)

add_subdirectory(QtResources)
add_subdirectory(Windows)
add_subdirectory(Dialogs)
add_subdirectory(CustomWidgets)

target_sources(neoimp PUBLIC
  ApplicationView.cpp
  NewDocumentView.cpp
  SaveDocumentView.cpp
  DocumentView.cpp
  ViewFactory.cpp
  ViewSink.cpp
)
