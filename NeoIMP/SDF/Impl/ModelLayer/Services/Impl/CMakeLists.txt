target_include_directories(neoimp PUBLIC .)

add_subdirectory(DomainObjects)

target_sources(neoimp PUBLIC
  DocumentManagementService.cpp
  ImageRenderingService.cpp
)
