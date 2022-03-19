add_subdirectory(Gil)

target_sources(neoimp PUBLIC
               MetricsService.cpp
               DocumentPrefabsService.cpp
               EditorStateService.cpp
               ViewCoordinatesService.cpp
               Component.cpp
              )
