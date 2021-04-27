target_include_directories(neoimp PUBLIC .)

add_subdirectory(QtResources)
add_subdirectory(CustomWidgets)

target_sources(neoimp PUBLIC
               Factory.cpp
               LengthSelector.cpp
               ResolutionSelector.cpp
               MainWindow.cpp
               NewDocumentDialog.cpp
               FileDialog.cpp
               DocumentView.cpp
               Toolbox.cpp
              )
