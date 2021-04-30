target_include_directories(neoimp PUBLIC .)

target_sources(neoimp PUBLIC
               Factory.cpp
               GuiController.cpp
               MainWindowController.cpp
               NewDocumentDialogController.cpp
               SaveAsDialogController.cpp
               OpenDialogController.cpp
               ToolboxController.cpp
              )
