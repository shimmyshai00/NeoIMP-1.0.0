add_subdirectory(Validators)
add_subdirectory(Color)
add_subdirectory(Gil)

target_sources(neoimp PUBLIC
               DocumentPrefabsService.cpp
               EditorStateModelService.cpp
               DocumentViewStateService.cpp
               DocumentNotificationService.cpp
               UnitConversionService.cpp
               getMessageComponent.cpp
               getComponent.cpp
              )
