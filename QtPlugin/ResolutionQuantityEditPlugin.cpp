/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionQuantityEditPlugin.cpp
 * PURPOSE: A plugin for putting ResolutionQuantityEdit widgets into Qt Designer.
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

#include "ResolutionQuantityEditPlugin.hpp"

#include "../NeoIMP/SDF/UILayer/Gui/View/Qt/CustomWidgets/ResolutionQuantityEdit.hpp"

#include <QtPlugin>

ResolutionQuantityEditPlugin::ResolutionQuantityEditPlugin(QObject *parent)
  : QObject(parent),
    m_initialized(false)
{
}

void
ResolutionQuantityEditPlugin::initialize(QDesignerFormEditorInterface *core) {
  if(m_initialized) {
    return;
  }

  m_initialized = true;
}

bool
ResolutionQuantityEditPlugin::isInitialized() const {
  return m_initialized;
}

QString
ResolutionQuantityEditPlugin::name() const {
  return QStringLiteral("SDF::UILayer::Gui::View::Qt::CustomWidgets::ResolutionQuantityEdit");
}

QString
ResolutionQuantityEditPlugin::includeFile() const {
  return QStringLiteral("SDF/UILayer/Gui/View/Qt/CustomWidgets/ResolutionQuantityEdit.hpp");
}

QString
ResolutionQuantityEditPlugin::group() const {
  return tr("Input Widgets");
}

QIcon
ResolutionQuantityEditPlugin::icon() const {
  return QIcon("");
}

QString
ResolutionQuantityEditPlugin::toolTip() const {
  return tr("A widget for entering dimensionful resolution quantities");
}

QString
ResolutionQuantityEditPlugin::whatsThis() const {
  return tr("Provides a way to enter image resolution in real units such as pixels per inch while "
            "also allowing for the user to select the unit they want to use to enter it. Note "
            "that, in order to use it, it must be provided with a reference to the model layer's "
            "metrics service after declaring it in the GUI form."
           );
}

bool
ResolutionQuantityEditPlugin::isContainer() const {
  return false;
}

QString
ResolutionQuantityEditPlugin::domXml() const {
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
ResolutionQuantityEditPlugin::createWidget(QWidget *parent) {
  using SDF::UILayer::Gui::View::Qt::CustomWidgets::ResolutionQuantityEdit;

  return new ResolutionQuantityEdit(parent);
}
