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
#include "QtResources/ui_NewDocumentDialog.h"

namespace SDF::Layers::UILayer::Qt::View {
  CNewDocumentDialog::CNewDocumentDialog(QWidget *parent, INewDocumentController *controller) :
  QDialog(parent),
  m_ui(new Ui::NewDocumentDialog),
  m_controller(controller),
  m_widthDimension(1280, 120),
  m_heightDimension(720, 120),
  m_colorModel(COLOR_MODEL_RGB),
  m_bitDepth(BIT_DEPTH_8)
  {
    m_ui->setupUi(this);
    populateOptions();
  }

  CNewDocumentDialog::~CNewDocumentDialog() {
    delete m_ui;
  }

  // Private members.
  void CNewDocumentDialog::widthChanged() {

  }

  void CNewDocumentDialog::heightChanged() {

  }

  void CNewDocumentDialog::widthUnitChanged() {

  }

  void CNewDocumentDialog::heightUnitChanged() {

  }

  void CNewDocumentDialog::resolutionChanged() {

  }

  void CNewDocumentDialog::resolutionUnitChanged() {

  }

  void CNewDocumentDialog::colorModelChanged() {

  }

  void CNewDocumentDialog::bitDepthChanged() {

  }

  void CNewDocumentDialog::populateOptions() {
    // Populate the list boxes with unit options.
    // Length units.
    for(int i(0); i < MAX_LENGTH_UNIT; ++i) {
      m_ui->imageWidthUnitBox->addItem(g_lengthUnitSymbols[i], QVariant(i));
      m_ui->imageHeightUnitBox->addItem(g_lengthUnitSymbols[i], QVariant(i));
    }

    // Resolution units.
    for(int i(0); i < MAX_RESOLUTION_UNIT; ++i) {
      m_ui->imageResolutionUnitBox->addItem(g_resolutionUnitSymbols[i], QVariant(i));
    }

    // Color models.
    for(int i(0); i < MAX_COLOR_MODEL; ++i) {
      m_ui->colorModelBox->addItem(g_colorModelNames[i], QVariant(i));
    }

    // Bit depths.
    m_ui->bitDepthBox->addItem("8", QVariant(BIT_DEPTH_8));
    m_ui->bitDepthBox->addItem("10", QVariant(BIT_DEPTH_10));
    m_ui->bitDepthBox->addItem("12", QVariant(BIT_DEPTH_12));
    m_ui->bitDepthBox->addItem("16", QVariant(BIT_DEPTH_16));
  }
}
