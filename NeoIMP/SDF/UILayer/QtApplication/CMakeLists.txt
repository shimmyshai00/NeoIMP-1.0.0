add_subdirectory(View)

target_sources(neoimp PUBLIC
               Application.cpp
               Component.cpp
              )

target_link_libraries(neoimp Qt5::Widgets)
