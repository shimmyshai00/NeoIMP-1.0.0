target_include_directories(neoimp PUBLIC
                           .
                          )

add_subdirectory(Tools)
add_subdirectory(Decals)

target_sources(neoimp PUBLIC
               DeltaEditor.cpp
               Factories.cpp
               Component.cpp
              )
