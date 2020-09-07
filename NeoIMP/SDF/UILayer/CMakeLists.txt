add_library(UILayer STATIC
  Impl/Qt/CustomWidgets/CViewport1D.cpp
  Impl/Qt/CustomWidgets/CViewport2D.cpp
  Impl/Qt/CustomWidgets/CRuler.cpp
  Impl/Qt/CustomWidgets/CImageDisplay.cpp
  Impl/Qt/CustomWidgets/CImageEditor.cpp
  Impl/Qt/Dialogs/CNewDocumentDimensionCalc.cpp
  Impl/Qt/Dialogs/CNewDocumentDialog.cpp
  Impl/Qt/Dialogs/NewDocumentDialog.ui
  Impl/Qt/Windows/CDocument.cpp
  Impl/Qt/Windows/CMainWindow.cpp
  Impl/Qt/Windows/MainWindow.ui
  Impl/Qt/Error/CErrorReporter.cpp
  Impl/Qt/CApplication.cpp
  Impl/Qt/CQtUILayer.cpp
  Impl/Qt/IUILayer.cpp)

target_sources(UILayer PUBLIC
  Impl/Qt/Resources/Icons.qrc
  Impl/Qt/Windows/MainWindow.qrc)

target_include_directories(UILayer PRIVATE ${CMAKE_SOURCE_DIR} .)
target_include_directories(UILayer PUBLIC include)
target_link_libraries(UILayer ModelLayer Qt5::Widgets)
