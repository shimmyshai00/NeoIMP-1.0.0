target_include_directories(neoimp PUBLIC .)

add_subdirectory(View)
add_subdirectory(Controller)
add_subdirectory(ViewModel)

target_sources(neoimp PUBLIC
  MainUI.cpp
)
