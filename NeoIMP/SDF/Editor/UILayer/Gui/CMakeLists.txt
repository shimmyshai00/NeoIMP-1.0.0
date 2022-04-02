add_subdirectory(View)
add_subdirectory(Controller)

target_sources(neoimp PUBLIC
  EntryPoint.cpp
  getQtComponent.cpp
)
