target_include_directories(neoimp PUBLIC .)

add_subdirectory(View)
add_subdirectory(Controller)
add_subdirectory(PresentationModel)

target_sources(neoimp PUBLIC
  MainUI.cpp
)
