cmake_minimum_required(VERSION 3.13)

project(NeoIMP LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5UiPlugin REQUIRED)

add_library(ResolutionQuantityEditPlugin SHARED
  ../NeoIMP/SDF/UILayer/Gui/View/Qt/CustomWidgets/DimensionalQuantityEdit.hpp
  ../NeoIMP/SDF/UILayer/Gui/View/Qt/CustomWidgets/ResolutionQuantityEdit.cpp
  ResolutionQuantityEditPlugin.cpp
)

target_link_libraries(ResolutionQuantityEditPlugin PRIVATE Qt5::Widgets Qt5::UiPlugin)

add_library(LengthQuantityEditPlugin SHARED
  ../NeoIMP/SDF/UILayer/Gui/View/Qt/CustomWidgets/DimensionalQuantityEdit.hpp
  ../NeoIMP/SDF/UILayer/Gui/View/Qt/CustomWidgets/LengthQuantityEdit.cpp
  LengthQuantityEditPlugin.cpp
)

target_link_libraries(LengthQuantityEditPlugin PRIVATE Qt5::Widgets Qt5::UiPlugin)
