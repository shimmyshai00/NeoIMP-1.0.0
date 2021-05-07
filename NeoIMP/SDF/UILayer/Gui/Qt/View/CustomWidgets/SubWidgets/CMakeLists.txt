target_include_directories(neoimp PUBLIC .)

add_subdirectory(EditViewWidget)

target_sources(neoimp PUBLIC
  DocumentEditorWidget.cpp
  DocumentRulerWidget.cpp
)
