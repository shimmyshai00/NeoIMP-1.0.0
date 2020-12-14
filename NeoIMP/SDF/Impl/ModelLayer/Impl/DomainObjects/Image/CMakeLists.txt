target_include_directories(neoimp PUBLIC .)

add_subdirectory(Gil)

target_sources(neoimp PUBLIC
  ImageDataVisitor.cpp
)
