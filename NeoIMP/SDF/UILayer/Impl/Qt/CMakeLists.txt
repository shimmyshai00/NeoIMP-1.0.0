target_include_directories(UILayer PRIVATE ".")

target_sources(UILayer PRIVATE
  CApplication.hpp
  CApplication.cpp
  CQtUILayer.hpp
  CQtUILayer.cpp
)

add_subdirectory(Resources)
add_subdirectory(Windows)
add_subdirectory(Dialogs)

target_link_libraries(UILayer PRIVATE Qt5::Widgets)
