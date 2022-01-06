/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialog.cpp
 * PURPOSE: Implements the NewDocumentDialog class.
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

#include "NewDocumentDialog.hpp"

#include "Resources/ui_NewDocumentDialog.h"

namespace SDF::UILayer::Gui::View::Qt {
  NewDocumentDialog::NewDocumentDialog(AbstractModel::IMetricsService *metricsService,
                                       IQtView *parent
                                      )
    : QtView(parent),
      m_ui(new Ui::NewDocumentDialog)
  {
    using namespace CustomWidgets;

    m_ui->setupUi(this);

    // Inject service into widgets.
    m_ui->widthUnitQuantityEdit->setMetricsService(metricsService);
    m_ui->heightUnitQuantityEdit->setMetricsService(metricsService);
    m_ui->resolutionUnitQuantityEdit->setMetricsService(metricsService);

    // Set defaults.
    m_ui->widthUnitQuantityEdit->setQuantityMode(UnitQuantityEdit::LENGTH);
    m_ui->heightUnitQuantityEdit->setQuantityMode(UnitQuantityEdit::LENGTH);
    m_ui->resolutionUnitQuantityEdit->setQuantityMode(UnitQuantityEdit::RESOLUTION);

    m_ui->widthUnitQuantityEdit->setEnteredQuantity(1280.0f);
    m_ui->heightUnitQuantityEdit->setEnteredQuantity(720.0f);
    m_ui->resolutionUnitQuantityEdit->setEnteredQuantity(120.0f);

    // Connect resolution widget to width/height widgets.
    connect(m_ui->resolutionUnitQuantityEdit, &UnitQuantityEdit::quantityChanged, m_ui->widthUnitQuantityEdit,
      &UnitQuantityEdit::setConvertResolution);
    connect(m_ui->resolutionUnitQuantityEdit, &UnitQuantityEdit::resolutionUnitChanged, m_ui->widthUnitQuantityEdit,
      &UnitQuantityEdit::setConvertResolutionUnit);
    connect(m_ui->resolutionUnitQuantityEdit, &UnitQuantityEdit::quantityChanged, m_ui->heightUnitQuantityEdit,
      &UnitQuantityEdit::setConvertResolution);
    connect(m_ui->resolutionUnitQuantityEdit, &UnitQuantityEdit::resolutionUnitChanged, m_ui->heightUnitQuantityEdit,
      &UnitQuantityEdit::setConvertResolutionUnit);
  }

  NewDocumentDialog::~NewDocumentDialog() {
    delete m_ui;
  }

  Patterns::PIConnection
  NewDocumentDialog::hookOnAccept(
    std::unique_ptr<Mvc::IController<AbstractModel::Defs::ImageSpec>>
      controller
  ) {
    return m_onAcceptEvent.hook(std::move(controller));
  }

  Patterns::PIConnection
  NewDocumentDialog::hookOnReject(
    std::unique_ptr<Mvc::IController<>> controller
  ) {
    return m_onRejectEvent.hook(std::move(controller));
  }
}
