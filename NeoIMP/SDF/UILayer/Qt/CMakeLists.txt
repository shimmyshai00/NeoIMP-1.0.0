add_subdirectory(View)
add_subdirectory(Controller)

target_sources(neoimp PUBLIC
               Application.cpp
               Component.cpp
              )

target_link_libraries(neoimp Qt5::Widgets)
