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
#include "../QtResources/ui_NewDocumentDialog.h"
#include <QString>

#include <CustomWidgets/UnitQuantityInput.hpp>

#include <Metrics/Dimensionless/Quantity.hpp>
#include <Metrics/Dimensionless/Units/Units.hpp>
#include <Metrics/Resolution/Quantity.hpp>
#include <Metrics/Resolution/Units/Units.hpp>

#include <Strings/ColorModels.hpp>
#include <Strings/BitDepths.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::Dialogs {
  NewDocumentDialog::NewDocumentDialog(QWidget *parent)
    : QDialog(parent),
      m_ui(new Ui::NewDocumentDialog)
  {
    using namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::CustomWidgets;

    m_ui->setupUi(this);

    m_ui->imageWidthInput->setQuantityType(QUANTITY_PIXELS);
    m_ui->imageWidthInput->setPixelsQuantity(1280.0 * Metrics::Dimensionless::Units::One);
    m_ui->imageHeightInput->setQuantityType(QUANTITY_PIXELS);
    m_ui->imageHeightInput->setPixelsQuantity(720.0 * Metrics::Dimensionless::Units::One);
    m_ui->imageResolutionInput->setQuantityType(QUANTITY_RESOLUTION);
    m_ui->imageResolutionInput->setResolutionQuantity(120.0 * Metrics::Resolution::Units::PixelsPerInch);

    for(int i(0); i < ModelLayer::Properties::COLOR_MODEL_MAX; ++i) {
      m_ui->colorModelComboBox->addItem(QString(Strings::colorModelNames[i].c_str()), i);
    }

    for(int i(0); i < ModelLayer::Properties::BIT_DEPTH_MAX; ++i) {
      m_ui->bitsPerChannelComboBox->addItem(QString(Strings::bitDepthNames[i].c_str()), i);
    }

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

  int
  NewDocumentDialog::getDocumentWidthPx() {
    return m_ui->imageWidthInput->pixelsQuantity().inUnitsOf(Metrics::Dimensionless::Units::One);
  }

  int
  NewDocumentDialog::getDocumentHeightPx() {
    return m_ui->imageHeightInput->pixelsQuantity().inUnitsOf(Metrics::Dimensionless::Units::One);
  }

  float
  NewDocumentDialog::getDocumentResolutionPpi() {
    return m_ui->imageResolutionInput->resolutionQuantity().inUnitsOf(Metrics::Resolution::Units::PixelsPerInch);
  }

  ModelLayer::Properties::ColorModel
  NewDocumentDialog::getDocumentColorModel() {
    return static_cast<ModelLayer::Properties::ColorModel>(m_ui->colorModelComboBox->currentData().toInt());
  }

  ModelLayer::Properties::BitDepth
  NewDocumentDialog::getDocumentBitDepth() {
    return static_cast<ModelLayer::Properties::BitDepth>(m_ui->bitsPerChannelComboBox->currentData().toInt());
  }
}
