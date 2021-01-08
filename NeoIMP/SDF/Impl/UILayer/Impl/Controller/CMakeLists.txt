target_include_directories(neoimp PUBLIC .)

target_sources(neoimp PUBLIC
  ApplicationController.cpp
  FileCommandsController.cpp
  NewDocumentController.cpp
  ControllerFactory.cpp
)
