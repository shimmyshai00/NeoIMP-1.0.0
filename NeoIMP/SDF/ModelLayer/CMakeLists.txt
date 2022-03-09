add_subdirectory(Metrics)
add_subdirectory(DomainObjects)
add_subdirectory(Repositories)
add_subdirectory(MessageSystem)
add_subdirectory(Services)

target_sources(neoimp PUBLIC
  Component.cpp
)
