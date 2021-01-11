target_include_directories(neoimp PUBLIC .)

add_subdirectory(Application)
add_subdirectory(NewDocumentDlg)
add_subdirectory(SaveDocumentDlg)

target_sources(neoimp PUBLIC
  ControllerFactory.cpp
  MasterController.cpp
)
