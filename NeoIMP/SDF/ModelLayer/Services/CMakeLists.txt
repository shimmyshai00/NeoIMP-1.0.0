target_include_directories(neoimp PUBLIC
                           .
                          )

target_sources(neoimp PUBLIC
               DocumentCreationService.cpp
               DocumentAccessService.cpp
               DocumentRenderService.cpp
               DocumentStorageService.cpp
               Component.cpp
              )
