target_include_directories(neoimp PUBLIC .)

add_subdirectory(SubWidgets)

target_sources(neoimp PUBLIC
  UnitQuantityInput.cpp
  DocumentWidget.cpp
)
