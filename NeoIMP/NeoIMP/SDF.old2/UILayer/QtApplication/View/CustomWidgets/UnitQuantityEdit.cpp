/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitQuantityEdit.cpp
 * PURPOSE: Implements the UnitQuantityEdit class.
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

#include "UnitQuantityEdit.hpp"

#include <QBoxLayout>
#include <QLineEdit>
#include <QComboBox>

namespace SDF::UILayer::QtApplication::View::CustomWidgets {
  UnitQuantityEdit::UnitQuantityEdit(AbstractModel::Services::IMeasurementConversionService *
                                      measurementConversionService,
                                     QuantityMode quantityMode,
                                     QWidget *parent
                                    )
    : QWidget(parent),
      m_measurementConversionService(measurementConversionService),
      m_quantityMode(quantityMode),
      m_quantity(0.0f),
      m_lengthUnit(AbstractModel::Data::UNIT_PIXEL),
      m_resolutionUnit(AbstractModel::Data::UNIT_PIXELS_PER_INCH),
      m_convResolution(120.0f),
      m_convResolutionUnit(AbstractModel::Data::UNIT_PIXELS_PER_INCH)
  {
    // Create the layout for this widget, which consists of a line edit to enter the quantity, with a combo box to the
    // right for selecting the unit.
    QBoxLayout *layout(new QBoxLayout(QBoxLayout::LeftToRight, this));
    QLineEdit *quantityEdit(new QLineEdit("0.0"));
    QComboBox *unitSelect(new QComboBox);

    layout->addWidget(quantityEdit);
    layout->addWidget(unitSelect);
  }

  UnitQuantityEdit::UnitQuantityEdit(QuantityMode quantityMode,
                                     QWidget *parent
                                    )
    : UnitQuantityEdit(nullptr, quantityMode, parent)
  {
  }

  UnitQuantityEdit::~UnitQuantityEdit() {
  }

  void
  UnitQuantityEdit::setMeasurementService(AbstractModel::Services::IMeasurementConversionService *
                                            measurementConversionService
                                         )
  {
    m_measurementConversionService = measurementConversionService;
  }

  void
  UnitQuantityEdit::setQuantityMode(QuantityMode quantityMode) {
    m_quantityMode = quantityMode;
  }

  void
  UnitQuantityEdit::setConvertResolution(float resolution, AbstractModel::Data::ResolutionUnit unit) {
    m_convResolution = resolution;
    m_convResolutionUnit = unit;
  }

  void
  UnitQuantityEdit::setEnteredQuantity(float quantity) {
    m_quantity = quantity;
  }

  void
  UnitQuantityEdit::setLengthUnit(AbstractModel::Data::LengthUnit lengthUnit) {
    m_lengthUnit = lengthUnit;
  }

  void
  UnitQuantityEdit::setResolutionUnit(AbstractModel::Data::ResolutionUnit resolutionUnit) {
    m_resolutionUnit = resolutionUnit;
  }

  UnitQuantityEdit::QuantityMode
  UnitQuantityEdit::quantityMode() const {
    return m_quantityMode;
  }

  float
  UnitQuantityEdit::enteredQuantity() const {
    return m_quantity;
  }

  AbstractModel::Data::LengthUnit
  UnitQuantityEdit::selectedLengthUnit() const {
    return m_lengthUnit;
  }

  AbstractModel::Data::ResolutionUnit
  UnitQuantityEdit::selectedResolutionUnit() const {
    return m_resolutionUnit;
  }

  float
  UnitQuantityEdit::getEnteredQuantityInLengthUnit(AbstractModel::Data::LengthUnit unit) const {
    if(m_measurementConversionService != nullptr) {
      return m_measurementConversionService->convertLength(m_quantity,
                                                           m_lengthUnit,
                                                           m_convResolution,
                                                           m_convResolutionUnit,
                                                           unit
                                                          );
    } else {
      // TBA
      return m_quantity;
    }
  }

  float
  UnitQuantityEdit::getEnteredQuantityInResolutionUnit(AbstractModel::Data::ResolutionUnit unit) const {
    if(m_measurementConversionService != nullptr) {
      return m_measurementConversionService->convertResolution(m_quantity,
                                                               m_resolutionUnit,
                                                               unit
                                                              );
    } else {
      // TBA
      return m_quantity;
    }
  }
}
