#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_COLORCHOOSERADVANCEDDIALOG_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_COLORCHOOSERADVANCEDDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorChooserAdvancedDialog.hpp
 * PURPOSE: Defines the ColorChooserAdvancedDialog class.
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

#include "../../../../../../Common/Model/ServicePack.hpp"

#include <QDialog>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ColorChooserAdvancedDialog; }
QT_END_NAMESPACE

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  // Class:      ColorChooserAdvancedDialog
  // Purpose:    Provides a dialog that lets the user select advanced color options for color
  //             choosing.
  // Parameters: None.
  class ColorChooserAdvancedDialog : public QDialog {
    Q_OBJECT
  public:
    typedef Common::Model::ServicePack<> deps_t;
  public:
    ColorChooserAdvancedDialog(QWidget *a_parent = nullptr);
    ~ColorChooserAdvancedDialog();
  private:
    Ui::ColorChooserAdvancedDialog *m_ui;
  };
}

#endif
