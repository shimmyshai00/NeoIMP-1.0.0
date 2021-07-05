target_include_directories(neoimp PUBLIC
                           .
                          )

add_subdirectory(Renderer)

target_sources(neoimp PUBLIC
               Factories.cpp
               Component.cpp
              )
