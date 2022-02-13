add_subdirectory(Resources)
add_subdirectory(CustomWidgets)

target_sources(neoimp PUBLIC
               MainWindow.cpp
               NewDocumentDialog.cpp
               Factory.cpp
               Component.cpp
              )
