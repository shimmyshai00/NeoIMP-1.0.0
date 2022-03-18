add_subdirectory(Gil)

target_sources(neoimp PUBLIC
               UiStateManagerService.cpp
               MetricsService.cpp
               DocumentPrefabsService.cpp
               ViewCoordinatesService.cpp
               Component.cpp
              )
