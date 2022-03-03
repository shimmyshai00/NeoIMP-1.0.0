#ifndef LENGTHQUANTITYEDITPLUGIN_HPP
#define LENGTHQUANTITYEDITPLUGIN_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthQuantityEditPlugin.hpp
 * PURPOSE: Header for the plugin for putting LengthQuantityEdit widgets into Qt Designer.
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

#include <QDesignerCustomWidgetInterface>

#include <QIcon>
#include <QString>
#include <QWidget>

class LengthQuantityEditPlugin : public QObject,
                                 public QDesignerCustomWidgetInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "com.shiningdestiny.neoimp.CustomWidgets.LengthQuantityEditPlugin")
  Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
  explicit LengthQuantityEditPlugin(QObject *parent = nullptr);

  void initialize(QDesignerFormEditorInterface *core) override;
  bool isInitialized() const override;

  QString name() const override;
  QString includeFile() const override;
  QString group() const override;
  QIcon icon() const override;
  QString toolTip() const override;
  QString whatsThis() const override;
  bool isContainer() const override;
  QString domXml() const override;
  QWidget *createWidget(QWidget *parent) override;
private:
  bool m_initialized = false;
};

#endif
