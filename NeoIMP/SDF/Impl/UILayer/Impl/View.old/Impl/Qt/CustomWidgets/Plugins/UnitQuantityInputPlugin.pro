HEADERS = ../UnitQuantityInput.hpp UnitQuantityInputPlugin.hpp
SOURCES = ../UnitQuantityInput.cpp UnitQuantityInputPlugin.cpp

CONFIG += plugin
TEMPLATE = lib
QT += widgets uiplugin

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
INCLUDEPATH += ../ ../../../../../../
