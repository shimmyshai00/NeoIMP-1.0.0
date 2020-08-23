/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CNewDocumentDialog.cpp
 * PURPOSE: The Qt document creation dialog implementation.
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

#include <Impl/Qt/Dialogs/CNewDocumentDialog.hpp>
#include <ui_NewDocumentDialog.h>

#include <SDF/ModelLayer/Iface/Param/SDocumentSpec.hpp>
#include <cassert>
#include <iostream>

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt::Dialogs {
      CNewDocumentDialog::CNewDocumentDialog(QWidget *parent)
        : QDialog(parent),
          m_ui(new Ui::NewDocumentDialog),
          m_colorModel(SDF::ModelLayer::Iface::Param::COLOR_MODEL_RGB),
          m_bitDepth(SDF::ModelLayer::Iface::Param::BIT_DEPTH_8)
        {
          m_ui->setupUi(this);
        }

      CNewDocumentDialog::~CNewDocumentDialog() {
        delete m_ui;
      }

      void CNewDocumentDialog::injectWith(SDF::ModelLayer::Iface::IDocumentMeasurementsService *measurementsService) {
        assert(measurementsService != nullptr);

        m_newDocumentDimensionCalc.injectWith(measurementsService);

        // Technically, the construction was not yet complete before this point; now it is.
        // Populate the list boxes with the available units.
        populateComboBoxWithDimensionUnits(m_ui->imageWidthUnitBox);
        populateComboBoxWithDimensionUnits(m_ui->imageHeightUnitBox);
        populateComboBoxWithResolutionUnits(m_ui->imageResolutionUnitBox);

        populateComboBoxWithColorModels(m_ui->colorModelBox);
        populateComboBoxWithBitDepths(m_ui->bitDepthBox);

        syncToInternalState(true);
      }

      SDF::ModelLayer::Iface::Param::SDocumentSpec CNewDocumentDialog::getDocumentSpec() const {
        using namespace SDF::ModelLayer::Iface::Param;

        // Fill out a document spec with the gathered information for this document.
        SDocumentSpec documentSpec;
        documentSpec.documentWidthPx = m_newDocumentDimensionCalc.getCurrentPixelWidth();
        documentSpec.documentWidth = m_newDocumentDimensionCalc.getWidthInCurrentUnits();
        documentSpec.widthUnit = m_newDocumentDimensionCalc.getWidthUnit();

        documentSpec.documentHeightPx = m_newDocumentDimensionCalc.getCurrentPixelHeight();
        documentSpec.documentHeight = m_newDocumentDimensionCalc.getHeightInCurrentUnits();
        documentSpec.heightUnit = m_newDocumentDimensionCalc.getHeightUnit();

        documentSpec.documentResolution = m_newDocumentDimensionCalc.getResolutionInCurrentUnits();
        documentSpec.resolutionUnit = m_newDocumentDimensionCalc.getResolutionUnit();

        documentSpec.colorModel = m_colorModel;
        documentSpec.bitDepth = m_bitDepth;

        return documentSpec;
      }

      // Private methods.
      void CNewDocumentDialog::widthChanged() {
        m_newDocumentDimensionCalc.updateWidthInCurrentUnits(m_ui->imageWidthEdit->text().toFloat());
      }

      void CNewDocumentDialog::heightChanged() {
        m_newDocumentDimensionCalc.updateHeightInCurrentUnits(m_ui->imageHeightEdit->text().toFloat());
      }

      void CNewDocumentDialog::widthUnitChanged() {
        using namespace SDF::ModelLayer::Iface::Param;

        m_newDocumentDimensionCalc.updateWidthUnit(
          static_cast<EDimensionUnit>(m_ui->imageWidthUnitBox->currentData().toInt()));
        syncToInternalState();
      }

      void CNewDocumentDialog::heightUnitChanged() {
        using namespace SDF::ModelLayer::Iface::Param;

        m_newDocumentDimensionCalc.updateHeightUnit(
          static_cast<EDimensionUnit>(m_ui->imageHeightUnitBox->currentData().toInt()));
        syncToInternalState();
      }

      void CNewDocumentDialog::resolutionChanged() {
        m_newDocumentDimensionCalc.updateResolutionInCurrentUnits(m_ui->imageResolutionEdit->text().toFloat());
      }

      void CNewDocumentDialog::resolutionUnitChanged() {
        using namespace SDF::ModelLayer::Iface::Param;

        m_newDocumentDimensionCalc.updateResolutionUnit(
          static_cast<EResolutionUnit>(m_ui->imageResolutionUnitBox->currentData().toInt()));
        syncToInternalState();
      }

      void CNewDocumentDialog::colorModelChanged() {
        using namespace SDF::ModelLayer::Iface::Param;

        m_colorModel = static_cast<EColorModel>(m_ui->colorModelBox->currentData().toInt());
      }

      void CNewDocumentDialog::bitDepthChanged() {
        using namespace SDF::ModelLayer::Iface::Param;

        m_bitDepth = static_cast<EBitDepth>(m_ui->bitDepthBox->currentData().toInt());
      }

      void CNewDocumentDialog::populateComboBoxWithDimensionUnits(QComboBox *comboBox) {
        using namespace SDF::ModelLayer::Iface::Param;
        assert(comboBox != nullptr);

        // Note: items should be in the same order as they appear in the EDimensionUnit enum.
        comboBox->addItem("pixels", QVariant(UNIT_PIXEL));
        comboBox->addItem("millimeters", QVariant(UNIT_MILLIMETER));
        comboBox->addItem("points", QVariant(UNIT_POINT));
        comboBox->addItem("picas", QVariant(UNIT_PICA));
        comboBox->addItem("centimeters", QVariant(UNIT_CENTIMETER));
        comboBox->addItem("inches", QVariant(UNIT_INCH));
      }

      void CNewDocumentDialog::populateComboBoxWithResolutionUnits(QComboBox *comboBox) {
        using namespace SDF::ModelLayer::Iface::Param;
        assert(comboBox != nullptr);

        comboBox->addItem("per in", QVariant(UNIT_PIXELS_PER_INCH));
        comboBox->addItem("per cm", QVariant(UNIT_PIXELS_PER_CENTIMETER));
        comboBox->addItem("per mm", QVariant(UNIT_PIXELS_PER_MILLIMETER));
      }

      void CNewDocumentDialog::populateComboBoxWithColorModels(QComboBox *comboBox) {
        using namespace SDF::ModelLayer::Iface::Param;
        assert(comboBox != nullptr);

        comboBox->addItem("RGB", QVariant(COLOR_MODEL_RGB));
        comboBox->addItem("CMYK", QVariant(COLOR_MODEL_CMYK));
      }

      void CNewDocumentDialog::populateComboBoxWithBitDepths(QComboBox *comboBox) {
        using namespace SDF::ModelLayer::Iface::Param;
        assert(comboBox != nullptr);

        comboBox->addItem("8", QVariant(BIT_DEPTH_8));
        comboBox->addItem("10", QVariant(BIT_DEPTH_10));
        comboBox->addItem("12", QVariant(BIT_DEPTH_12));
        comboBox->addItem("16", QVariant(BIT_DEPTH_16));
      }

      void CNewDocumentDialog::syncToInternalState(bool syncComboBoxes) {
        using namespace SDF::ModelLayer::Iface::Param;

        if(m_newDocumentDimensionCalc.getWidthUnit() == UNIT_PIXEL) {
          m_ui->imageWidthEdit->setText(QString::number(m_newDocumentDimensionCalc.getCurrentPixelWidth()));
        } else {
          m_ui->imageWidthEdit->setText(QString::number(m_newDocumentDimensionCalc.getWidthInCurrentUnits(), 'f', 2));
        }

        if(m_newDocumentDimensionCalc.getHeightUnit() == UNIT_PIXEL) {
          m_ui->imageHeightEdit->setText(QString::number(m_newDocumentDimensionCalc.getCurrentPixelHeight()));
        } else {
          m_ui->imageHeightEdit->setText(QString::number(m_newDocumentDimensionCalc.getHeightInCurrentUnits(), 'f', 2));
        }

        m_ui->imageResolutionEdit->setText(QString::number(m_newDocumentDimensionCalc.getResolutionInCurrentUnits()));

        if(syncComboBoxes) {
          m_ui->imageWidthUnitBox->setCurrentIndex(m_newDocumentDimensionCalc.getWidthUnit());
          m_ui->imageHeightUnitBox->setCurrentIndex(m_newDocumentDimensionCalc.getHeightUnit());
          m_ui->imageResolutionUnitBox->setCurrentIndex(m_newDocumentDimensionCalc.getResolutionUnit());
          m_ui->colorModelBox->setCurrentIndex(m_colorModel);
          m_ui->bitDepthBox->setCurrentIndex(m_bitDepth);
        }
      }
    }
  }
}
