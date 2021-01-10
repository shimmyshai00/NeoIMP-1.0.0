target_include_directories(neoimp PUBLIC .)

add_subdirectory(Application)

target_sources(neoimp PUBLIC
  ControllerFactory.cpp
  MasterController.cpp
)
