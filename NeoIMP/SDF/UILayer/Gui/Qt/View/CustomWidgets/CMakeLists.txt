target_include_directories(neoimp PUBLIC .)

add_subdirectory(SubWidgets)

target_sources(neoimp PUBLIC
  DocumentWidget.cpp
  ToolButtonWidget.cpp
  EditableSlider.cpp
)
