target_include_directories(neoimp PUBLIC .)

add_subdirectory(Repositories)

target_sources(neoimp PUBLIC
  ImageRepositoryProvider.cpp
)
