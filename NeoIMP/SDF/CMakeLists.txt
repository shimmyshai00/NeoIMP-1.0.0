add_library(SDF
  Exception.hpp
)

target_sources(SDF PRIVATE
  SafeString.hpp
)

add_subdirectory(Common)
add_subdirectory(ModelLayer)
add_subdirectory(UILayer)

target_link_libraries(SDF PUBLIC UILayer)
