target_include_directories(neoimp PUBLIC .)

add_subdirectory(Qt)

target_sources(neoimp PUBLIC
               Gui.cpp
               Component.cpp
              )
