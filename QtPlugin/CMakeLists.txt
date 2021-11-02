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

add_library(UnitQuantityEditPlugin SHARED
  ../NeoIMP/SDF/UILayer/Qt/View/CustomWidgets/UnitQuantityEdit.cpp
  UnitQuantityEditPlugin.cpp
)
target_link_libraries(UnitQuantityEditPlugin PRIVATE Qt5::Widgets Qt5::UiPlugin)
