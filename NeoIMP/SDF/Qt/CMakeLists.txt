target_include_directories(neoimp PUBLIC .)

target_sources(neoimp PUBLIC
  QtApplication.cpp
)

target_link_libraries(neoimp Qt5::Widgets)
