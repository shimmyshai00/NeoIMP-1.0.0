add_subdirectory(Validators)
add_subdirectory(ColorModels)
add_subdirectory(Gil)

target_sources(neoimp PUBLIC
               DocumentPrefabsService.cpp
               EditorStateModelService.cpp
               DocumentViewStateService.cpp
               UnitConversionService.cpp
               MessageComponent.cpp
               Component.cpp
              )
