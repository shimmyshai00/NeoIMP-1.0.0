target_include_directories(neoimp PUBLIC .)

add_subdirectory(Algorithms)

target_sources(neoimp PUBLIC
  PNGRepository.cpp
)
