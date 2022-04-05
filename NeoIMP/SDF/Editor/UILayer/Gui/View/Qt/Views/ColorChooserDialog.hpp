#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_COLORCHOOSERDIALOG_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_COLORCHOOSERDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorChooserDialog.hpp
 * PURPOSE: Defines the ColorChooserDialog class.
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
#include "../../../../../../Common/IConnection.hpp"

#include "../../../../AbstractModel/Defs/Color/ColorFormat.hpp"

#include "../QtEvent.hpp"

#include <QDialog>
#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class ColorChooserDialog; }
QT_END_NAMESPACE

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  // Class:      ColorChooserDialog
  // Purpose:    Provides a dialog that lets the user select colors.
  // Parameters: None.
  class ColorChooserDialog : public QDialog {
    Q_OBJECT
  public:
    typedef Common::Model::ServicePack<> deps_t;
  public:
    ColorChooserDialog(QWidget *a_parent = nullptr);
    ColorChooserDialog(
      AbstractModel::Defs::Color::ColorModel a_colorModel,
      QWidget *a_parent = nullptr
    );

    ~ColorChooserDialog();

    Common::PIConnection
    hookOnAdvancedOptionsRequest(std::unique_ptr<IController<>> controller);
  private:
    Ui::ColorChooserDialog *m_ui;

    AbstractModel::Defs::Color::ColorModel m_colorModel;

    QPushButton *m_advancedButton;

    QtEvent<> m_onAdvancedOptionsRequestEvent;
  };
}

#endif
