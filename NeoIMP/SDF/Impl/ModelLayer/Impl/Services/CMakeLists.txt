target_include_directories(neoimp PUBLIC .)

target_sources(neoimp PUBLIC
  DocumentCreationService.cpp
  DocumentStorageService.cpp
  ImageInformationService.cpp
  ImageRenderingService.cpp
)
