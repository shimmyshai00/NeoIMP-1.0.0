target_include_directories(neoimp PUBLIC
                           .
                          )

add_subdirectory(Tools)

target_sources(neoimp PUBLIC
               DeltaEditor.cpp
               Factories.cpp
               Component.cpp
              )
