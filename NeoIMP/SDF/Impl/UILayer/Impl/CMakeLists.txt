target_include_directories(neoimp PUBLIC .)

add_subdirectory(View)
add_subdirectory(Controller)

target_sources(neoimp PUBLIC
  UIManager.cpp
  MainUI.cpp
)
