/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialog.cpp
 * PURPOSE: Implementation of the NewDocumentDialog class.
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

#include <NewDocumentDialog.hpp>
#include "QtResources/ui_NewDocumentDialog.h"

#include <CustomWidgets/UnitQuantityInput.hpp>

#include <SDF/UILayer/Metrics/Dimensionless/Quantity.hpp>
#include <SDF/UILayer/Metrics/Dimensionless/Units/Units.hpp>

#include <SDF/UILayer/Metrics/Resolution/Quantity.hpp>
#include <SDF/UILayer/Metrics/Resolution/Units/Units.hpp>

namespace SDF::UILayer::Qt::View {
  NewDocumentDialog::NewDocumentDialog(QWidget *parent) :
  QDialog(parent),
  m_ui(new Ui::NewDocumentDialog) {
    using namespace SDF::UILayer::Qt::View::CustomWidgets;

    m_ui->setupUi(this);

    m_ui->imageWidthInput->setQuantityType(QUANTITY_PIXELS);
    m_ui->imageWidthInput->setPixelsQuantity(1280.0 * Metrics::Dimensionless::Units::One);
    m_ui->imageHeightInput->setQuantityType(QUANTITY_PIXELS);
    m_ui->imageHeightInput->setPixelsQuantity(720.0 * Metrics::Dimensionless::Units::One);
    m_ui->imageResolutionInput->setQuantityType(QUANTITY_RESOLUTION);
    m_ui->imageResolutionInput->setResolutionQuantity(120.0 * Metrics::Resolution::Units::PixelsPerInch);

    connect(
      m_ui->imageResolutionInput, &UnitQuantityInput::resolutionQuantityEdited,
      m_ui->imageWidthInput, &UnitQuantityInput::setResolutionSlot
    );

    connect(
      m_ui->imageResolutionInput, &UnitQuantityInput::resolutionQuantityEdited,
      m_ui->imageHeightInput, &UnitQuantityInput::setResolutionSlot
    );
  }

  NewDocumentDialog::~NewDocumentDialog() {
    delete m_ui;
  }
}
