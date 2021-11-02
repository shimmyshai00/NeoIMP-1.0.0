/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitQuantityEditPlugin.cpp
 * PURPOSE: A plugin for putting UnitQuantityEdit widgets into Qt Designer.
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

#include "UnitQuantityEditPlugin.hpp"

#include "../NeoIMP/SDF/UILayer/Qt/View/CustomWidgets/UnitQuantityEdit.hpp"

#include <QtPlugin>

UnitQuantityEditPlugin::UnitQuantityEditPlugin(QObject *parent)
  : QObject(parent),
    m_initialized(false)
{
}

void
UnitQuantityEditPlugin::initialize(QDesignerFormEditorInterface *core) {
  if(m_initialized) {
    return;
  }

  m_initialized = true;
}

bool
UnitQuantityEditPlugin::isInitialized() const {
  return m_initialized;
}

QString
UnitQuantityEditPlugin::name() const {
  return QStringLiteral("SDF::UILayer::Qt::View::CustomWidgets::UnitQuantityEdit");
}

QString
UnitQuantityEditPlugin::includeFile() const {
  return QStringLiteral("SDF/UILayer/Qt/View/CustomWidgets/UnitQuantityEdit.hpp");
}

QString
UnitQuantityEditPlugin::group() const {
  return tr("Input Widgets");
}

QIcon
UnitQuantityEditPlugin::icon() const {
  return QIcon("");
}

QString
UnitQuantityEditPlugin::toolTip() const {
  return tr("A widget for entering dimensionful quantities");
}

QString
UnitQuantityEditPlugin::whatsThis() const {
  return tr("Provides a way to enter dimensionful physical quantities like image size and resolution in real units "
            "such as inches, allowing the user both to enter the quantity and select the appropriate unit."
           );
}

bool
UnitQuantityEditPlugin::isContainer() const {
  return false;
}

QString
UnitQuantityEditPlugin::domXml() const {
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
UnitQuantityEditPlugin::createWidget(QWidget *parent) {
  using SDF::UILayer::Qt::View::CustomWidgets::UnitQuantityEdit;

  return new UnitQuantityEdit(UnitQuantityEdit::LENGTH, parent);
}
