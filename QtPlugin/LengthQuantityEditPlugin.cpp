/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthQuantityEditPlugin.cpp
 * PURPOSE: A plugin for putting LengthQuantityEdit widgets into Qt Designer.
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

#include "LengthQuantityEditPlugin.hpp"

#include "../NeoIMP/SDF/UILayer/Gui/View/Qt/CustomWidgets/LengthQuantityEdit.hpp"

#include <QtPlugin>

LengthQuantityEditPlugin::LengthQuantityEditPlugin(QObject *parent)
  : QObject(parent),
    m_initialized(false)
{
}

void
LengthQuantityEditPlugin::initialize(QDesignerFormEditorInterface *core) {
  if(m_initialized) {
    return;
  }

  m_initialized = true;
}

bool
LengthQuantityEditPlugin::isInitialized() const {
  return m_initialized;
}

QString
LengthQuantityEditPlugin::name() const {
  return QStringLiteral("SDF::UILayer::Gui::View::Qt::CustomWidgets::LengthQuantityEdit");
}

QString
LengthQuantityEditPlugin::includeFile() const {
  return QStringLiteral("SDF/UILayer/Gui/View/Qt/CustomWidgets/LengthQuantityEdit.hpp");
}

QString
LengthQuantityEditPlugin::group() const {
  return tr("Input Widgets");
}

QIcon
LengthQuantityEditPlugin::icon() const {
  return QIcon("");
}

QString
LengthQuantityEditPlugin::toolTip() const {
  return tr("A widget for entering dimensionful length quantities");
}

QString
LengthQuantityEditPlugin::whatsThis() const {
  return tr("Provides a way to enter length quantities in real units such as millimeters and "
            "inches while also allowing for the user to select the unit they want to use to enter "
            "it. Note that, in order to use it, it must be provided with a reference to the model "
            "layer's metrics service after declaring it in the GUI form."
           );
}

bool
LengthQuantityEditPlugin::isContainer() const {
  return false;
}

QString
LengthQuantityEditPlugin::domXml() const {
  /*
  return "<ui language=\"c++\" displayname=\"UnitQuantityEdit\">\n"
         "  <widget class=\"widgets::UnitQuantityEdit\" name="\unitquantityedit\">\n"
         "  <customwidgets>\n"
         "    <customwidget>\n"
         "      <class>widgets::UnitQuantityEdit</class>\n"
         "      <propertyspecifications>\n"
         "        <stringpropertyspecification name="
         */

/*
  return "<ui language=\"c++\" displayname=\"UnitQuantityEdit\">\n"
         "  <widget class=\"widgets::UnitQuantityEdit\" name=\"unitquantityedit\"/>\n"
         "  <customwidgets>\n"
         "    <customwidget>\n"
         "      <class>widgets::UnitQuantityEdit</class>\n"
         "    </customwidget>\n"
         "  </customwidgets>\n"
         "</ui>\n";
         */

  return QDesignerCustomWidgetInterface::domXml();
}

QWidget *
LengthQuantityEditPlugin::createWidget(QWidget *parent) {
  using SDF::UILayer::Gui::View::Qt::CustomWidgets::LengthQuantityEdit;

  return new LengthQuantityEdit(parent);
}
