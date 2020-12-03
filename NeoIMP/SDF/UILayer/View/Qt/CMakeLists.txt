target_include_directories(neoimp PUBLIC .)

add_subdirectory(QtResources)
add_subdirectory(Windows)

target_sources(neoimp PUBLIC
  ApplicationView.cpp
  ViewManager.cpp
  ViewComponent.cpp
)
