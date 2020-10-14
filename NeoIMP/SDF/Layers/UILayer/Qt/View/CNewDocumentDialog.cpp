/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CNewDocumentDialog.cpp
 * PURPOSE: Implementation of the CNewDocumentDialog class.
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

#include <CNewDocumentDialog.hpp>

#include <QtResources/ui_NewDocumentDialog.h>
#include <INewDocumentController.hpp>

#include <SDF/Layers/UILayer/Metrics/UnitSymbols.hpp>
#include <SDF/Layers/UILayer/Color/ColorModelNames.hpp>

namespace SDF::Layers::UILayer::Qt::View {
  // Helper functions.
  Metrics::ELengthUnit getLengthUnitFromUnitComboBox(QComboBox *comboBox) {
    switch(comboBox->currentData().toInt()) {
      case Metrics::UNIT_PIXEL: return Metrics::UNIT_PIXEL;
      case Metrics::UNIT_POINT: return Metrics::UNIT_POINT;
      case Metrics::UNIT_MILLIMETER: return Metrics::UNIT_MILLIMETER;
      case Metrics::UNIT_PICA: return Metrics::UNIT_PICA;
      case Metrics::UNIT_CENTIMETER: return Metrics::UNIT_CENTIMETER;
      case Metrics::UNIT_INCH: return Metrics::UNIT_INCH;
      default: return Metrics::MAX_LENGTH_UNIT;
    }
  }

  Metrics::EResolutionUnit getResolutionUnitFromUnitComboBox(QComboBox *comboBox) {
    switch(comboBox->currentData().toInt()) {
      case Metrics::UNIT_PIXELS_PER_INCH: return Metrics::UNIT_PIXELS_PER_INCH;
      case Metrics::UNIT_PIXELS_PER_CENTIMETER: return Metrics::UNIT_PIXELS_PER_CENTIMETER;
      case Metrics::UNIT_PIXELS_PER_MILLIMETER: return Metrics::UNIT_PIXELS_PER_MILLIMETER;
      default: return Metrics::MAX_RESOLUTION_UNIT;
    }
  }

  Color::EColorModel getColorModelFromComboBox(QComboBox *comboBox) {
    switch(comboBox->currentData().toInt()) {
      case Color::COLOR_MODEL_RGB: return Color::COLOR_MODEL_RGB;
      case Color::COLOR_MODEL_CMYK: return Color::COLOR_MODEL_CMYK;
      default: return Color::COLOR_MODEL_RGB;
    }
  }

  Color::EBitDepth getBitDepthFromComboBox(QComboBox *comboBox) {
    switch(comboBox->currentData().toInt()) {
      case Color::BIT_DEPTH_8: return Color::BIT_DEPTH_8;
      case Color::BIT_DEPTH_10: return Color::BIT_DEPTH_10;
      case Color::BIT_DEPTH_12: return Color::BIT_DEPTH_12;
      case Color::BIT_DEPTH_16: return Color::BIT_DEPTH_16;
      default: return Color::BIT_DEPTH_8;
    }
  }
}

namespace SDF::Layers::UILayer::Qt::View {
  CNewDocumentDialog::CNewDocumentDialog(QWidget *parent, INewDocumentController *controller) :
  QDialog(parent),
  m_ui(new Ui::NewDocumentDialog),
  m_controller(controller),
  m_widthDimension(1280, 120),
  m_heightDimension(720, 120),
  m_colorModel(Color::COLOR_MODEL_RGB),
  m_bitDepth(Color::BIT_DEPTH_8)
  {
    m_ui->setupUi(this);
    populateOptions();
  }

  CNewDocumentDialog::~CNewDocumentDialog() {
    delete m_ui;
  }

  // Private members.
  void CNewDocumentDialog::widthChanged() {
    bool convertOk(false);

    float newWidth(m_ui->imageWidthEdit->text().toFloat(&convertOk));
    Metrics::ELengthUnit newLengthUnit(getLengthUnitFromUnitComboBox(m_ui->imageWidthUnitBox));

    if(convertOk) {
      m_widthDimension.setLength(newWidth, newLengthUnit);
    }
  }

  void CNewDocumentDialog::heightChanged() {
    bool convertOk(false);

    float newHeight(m_ui->imageHeightEdit->text().toFloat(&convertOk));
    Metrics::ELengthUnit newLengthUnit(getLengthUnitFromUnitComboBox(m_ui->imageHeightUnitBox));

    if(convertOk) {
      m_heightDimension.setLength(newHeight, newLengthUnit);
    }
  }

  void CNewDocumentDialog::widthUnitChanged() {
    Metrics::ELengthUnit newLengthUnit(getLengthUnitFromUnitComboBox(m_ui->imageWidthUnitBox));
    float widthInNewUnits(m_widthDimension.getLengthInUnits(newLengthUnit));
    m_ui->imageWidthEdit->setText(QString::number(widthInNewUnits));
  }

  void CNewDocumentDialog::heightUnitChanged() {
    Metrics::ELengthUnit newLengthUnit(getLengthUnitFromUnitComboBox(m_ui->imageHeightUnitBox));
    float heightInNewUnits(m_heightDimension.getLengthInUnits(newLengthUnit));
    m_ui->imageHeightEdit->setText(QString::number(heightInNewUnits));
  }

  void CNewDocumentDialog::resolutionChanged() {
    bool convertOk(false);

    float newResolution(m_ui->imageResolutionEdit->text().toFloat(&convertOk));
    Metrics::EResolutionUnit newResolutionUnit(getResolutionUnitFromUnitComboBox(m_ui->imageResolutionUnitBox));

    if(convertOk) {
      m_widthDimension.setResolution(newResolution, newResolutionUnit);
      m_heightDimension.setResolution(newResolution, newResolutionUnit);
    }
  }

  void CNewDocumentDialog::resolutionUnitChanged() {
    Metrics::EResolutionUnit newResolutionUnit(getResolutionUnitFromUnitComboBox(m_ui->imageResolutionUnitBox));
    float resolutionInNewUnits(m_widthDimension.getResolutionInUnits(newResolutionUnit));
    m_ui->imageResolutionEdit->setText(QString::number(resolutionInNewUnits));
  }

  void CNewDocumentDialog::colorModelChanged() {
    m_colorModel = getColorModelFromComboBox(m_ui->colorModelBox);
  }

  void CNewDocumentDialog::bitDepthChanged() {
    m_bitDepth = getBitDepthFromComboBox(m_ui->bitDepthBox);
  }

  void CNewDocumentDialog::populateOptions() {
    // Populate the list boxes with unit options.
    // Length units.
    for(int i(0); i < Metrics::MAX_LENGTH_UNIT; ++i) {
      m_ui->imageWidthUnitBox->addItem(Metrics::g_lengthUnitSymbols[i], QVariant(i));
      m_ui->imageHeightUnitBox->addItem(Metrics::g_lengthUnitSymbols[i], QVariant(i));
    }

    // Resolution units.
    for(int i(0); i < Metrics::MAX_RESOLUTION_UNIT; ++i) {
      m_ui->imageResolutionUnitBox->addItem(Metrics::g_resolutionUnitSymbols[i], QVariant(i));
    }

    // Color models.
    for(int i(0); i < Color::MAX_COLOR_MODEL; ++i) {
      m_ui->colorModelBox->addItem(Color::g_colorModelNames[i], QVariant(i));
    }

    // Bit depths.
    m_ui->bitDepthBox->addItem("8", QVariant(Color::BIT_DEPTH_8));
    m_ui->bitDepthBox->addItem("10", QVariant(Color::BIT_DEPTH_10));
    m_ui->bitDepthBox->addItem("12", QVariant(Color::BIT_DEPTH_12));
    m_ui->bitDepthBox->addItem("16", QVariant(Color::BIT_DEPTH_16));
  }
}
