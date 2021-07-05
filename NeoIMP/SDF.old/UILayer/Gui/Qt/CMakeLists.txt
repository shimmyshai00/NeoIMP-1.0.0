target_include_directories(neoimp PUBLIC .)

add_subdirectory(Controller)
add_subdirectory(View)

target_sources(neoimp PUBLIC
               Component.cpp
              )

target_link_libraries(neoimp Qt5::Widgets)
