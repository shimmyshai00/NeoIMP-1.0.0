target_include_directories(neoimp PUBLIC .)

add_subdirectory(CustomWidgets)

target_sources(neoimp PUBLIC
               Factory.cpp
               LengthSelector.cpp
               ResolutionSelector.cpp
               MainWindow.cpp
               NewDocumentDialog.cpp
               DocumentView.cpp
              )
