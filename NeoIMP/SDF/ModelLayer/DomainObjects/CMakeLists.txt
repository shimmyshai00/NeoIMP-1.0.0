target_include_directories(neoimp PUBLIC
                           .
                          )

add_subdirectory(Image)
add_subdirectory(Algorithms)
add_subdirectory(RenderParam)

target_sources(neoimp PUBLIC
               Component.cpp
              )
