add_library(Qt)
target_include_directories(Qt PUBLIC .)

add_subdirectory(Controller)
add_subdirectory(View)

target_sources(Qt PUBLIC
  QtApplication.cpp
  QtApplicationComponent.cpp
)

target_link_libraries(Qt Qt5::Widgets)
