target_include_directories(neoimp PUBLIC .)

add_subdirectory(Application)
add_subdirectory(NewDocumentDlg)

target_sources(neoimp PUBLIC
  ControllerFactory.cpp
  MasterController.cpp
)
