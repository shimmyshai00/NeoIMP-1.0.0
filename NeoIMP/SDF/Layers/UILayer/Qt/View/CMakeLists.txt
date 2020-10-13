add_library(View CMainWindow.cpp CNewDocumentDialog.cpp)
add_subdirectory(QtResources)

target_link_libraries(View QtResources Controller Metrics Qt5::Widgets)
