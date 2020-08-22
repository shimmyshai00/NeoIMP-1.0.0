add_library(DocumentModel "")
target_include_directories(DocumentModel PUBLIC Iface)
target_include_directories(DocumentModel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

add_subdirectory(Iface)
add_subdirectory(Impl)
