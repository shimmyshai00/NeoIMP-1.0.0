add_library(UILayer "")
target_include_directories(UILayer PUBLIC Iface)
target_include_directories(UILayer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

add_subdirectory(Iface)
add_subdirectory(Impl)

target_link_libraries(UILayer PRIVATE ModelLayer)
