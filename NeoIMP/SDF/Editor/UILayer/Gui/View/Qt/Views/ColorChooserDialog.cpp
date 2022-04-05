/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorChooserDialog.cpp
 * PURPOSE: Implements the ColorChooserDialog class.
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

#include "ColorChooserDialog.hpp"

#include "../Resources/ui_ColorChooserDialog.h"

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  ColorChooserDialog::ColorChooserDialog(QWidget *a_parent)
    : ColorChooserDialog(AbstractModel::Defs::Color::COLOR_MODEL_RGB, a_parent)
  {
  }

  ColorChooserDialog::ColorChooserDialog(
    AbstractModel::Defs::Color::ColorModel a_colorModel,
    QWidget *a_parent
  )
    : QDialog(a_parent),
      m_ui(new Ui::ColorChooserDialog),
      m_colorModel(a_colorModel),
      m_advancedButton(nullptr)
  {
    m_ui->setupUi(this);

    m_advancedButton = m_ui->buttonBox->addButton("Advanced...",
      QDialogButtonBox::ActionRole);

    connect(m_advancedButton, &QPushButton::clicked, [&]() {
      m_onAdvancedOptionsRequestEvent.trigger(); });
  }

  ColorChooserDialog::~ColorChooserDialog() {
    delete m_ui;
  }

  Common::PIConnection
  ColorChooserDialog::hookOnAdvancedOptionsRequest(std::unique_ptr<IController<>> controller) {
    return m_onAdvancedOptionsRequestEvent.hook(std::move(controller));
  }
}
