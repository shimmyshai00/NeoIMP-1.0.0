target_include_directories(neoimp PUBLIC .)

add_subdirectory(Messaging)

target_sources(neoimp PUBLIC
  MVCMessageDispatcher.cpp
  MVCViewUnit.cpp
  MVCMasterController.cpp
  MVCBaseController.cpp
  MVCMessageEncoder.cpp
)
