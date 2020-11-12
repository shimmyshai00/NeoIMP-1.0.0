add_library(SDF)
target_include_directories(SDF PUBLIC .)

add_subdirectory(DataLayer)
add_subdirectory(ModelLayer)
add_subdirectory(UILayer)

target_sources(SDF PUBLIC
  ApplicationComponent.cpp
)

target_link_libraries(SDF DataLayer ModelLayer UILayer)
