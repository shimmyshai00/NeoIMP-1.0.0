target_include_directories(neoimp PUBLIC .)

add_subdirectory(Impl)

target_sources(neoimp PUBLIC
  ImageRepositoryComponent.cpp
)
