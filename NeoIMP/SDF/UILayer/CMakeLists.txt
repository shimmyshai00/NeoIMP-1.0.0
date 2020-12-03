target_include_directories(neoimp PUBLIC .)

add_subdirectory(Controller)
add_subdirectory(View)

target_sources(neoimp PUBLIC
  UIComponent.cpp
)
