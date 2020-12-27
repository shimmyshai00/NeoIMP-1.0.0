/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitQuantityInputPlugin.cpp
 * PURPOSE: A Qt Designer plugin for the unit quantity input custom widget.
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <UnitQuantityInputPlugin.hpp>
#include <../UnitQuantityInput.hpp>

UnitQuantityInputPlugin::UnitQuantityInputPlugin(QObject *parent) :
QObject(parent) {}

bool UnitQuantityInputPlugin::isContainer() const {
  return false;
}

bool UnitQuantityInputPlugin::isInitialized() const {
  return initialized;
}

QIcon UnitQuantityInputPlugin::icon() const {
  return QIcon();
}

QString UnitQuantityInputPlugin::domXml() const {
  return "<ui language=\"c++\">\n"
         " <widget class=\"SDF::UILayer::Qt::View::CustomWidgets::UnitQuantityInput\" name=\"unitQuantityInput\">\n"
         " </widget>\n"
         "</ui>\n";
}

QString UnitQuantityInputPlugin::group() const {
  return QStringLiteral("Input Widgets");
}

QString UnitQuantityInputPlugin::includeFile() const {
  return QStringLiteral("SDF/UILayer/Qt/View/CustomWidgets/UnitQuantityInput.hpp");
}

QString UnitQuantityInputPlugin::name() const {
  return QStringLiteral("SDF::UILayer::Qt::View::CustomWidgets::UnitQuantityInput");
}

QString UnitQuantityInputPlugin::toolTip() const {
  return QStringLiteral("Unit Quantity Input");
}

QString UnitQuantityInputPlugin::whatsThis() const {
  return QStringLiteral("A custom widget to faciltate inputting, with conversion, of unitful measurement quantities");
}

QWidget *UnitQuantityInputPlugin::createWidget(QWidget *parent) {
  return new SDF::UILayer::Qt::View::CustomWidgets::UnitQuantityInput(parent);
}

void UnitQuantityInputPlugin::initialize(QDesignerFormEditorInterface * /* core */) {
  if(initialized)
    return;

  initialized = true;
}
