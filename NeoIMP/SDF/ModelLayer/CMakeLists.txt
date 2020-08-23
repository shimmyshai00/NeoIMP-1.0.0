add_library(ModelLayer "")
target_include_directories(ModelLayer PUBLIC Iface)
target_include_directories(ModelLayer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

add_subdirectory(Iface)
add_subdirectory(Impl)
