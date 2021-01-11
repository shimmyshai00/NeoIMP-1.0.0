target_include_directories(neoimp PUBLIC .)

target_sources(neoimp PUBLIC
  MVCMessageDispatcher.cpp
  MVCViewUnit.cpp
  MVCMasterController.cpp
  MVCBaseController.cpp
  MVCMessageEncoder.cpp
)
