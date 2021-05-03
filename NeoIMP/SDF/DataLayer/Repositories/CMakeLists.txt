target_include_directories(neoimp PUBLIC
                           .
                          )

target_sources(neoimp PUBLIC
               ImageRepository.cpp
               RenderingRepository.cpp
               ToolRepository.cpp
               DeltaEditorRepository.cpp
               Component.cpp
              )
