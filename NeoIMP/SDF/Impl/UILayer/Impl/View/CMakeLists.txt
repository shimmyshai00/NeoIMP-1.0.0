target_include_directories(neoimp PUBLIC .)

add_subdirectory(Observers)
add_subdirectory(Impl)

target_sources(neoimp PUBLIC
  QtViewComponent.cpp
)
