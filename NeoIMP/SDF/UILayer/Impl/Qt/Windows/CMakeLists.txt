target_include_directories(UILayer PRIVATE ".")

target_sources(UILayer PUBLIC
  MainWindow.qrc
  MainWindow.ui
)

target_sources(UILayer PRIVATE
  CMainWindow.hpp
  CMainWindow.cpp
)
