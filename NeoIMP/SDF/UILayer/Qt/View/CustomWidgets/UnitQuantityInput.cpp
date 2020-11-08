/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitQuantityInput.cpp
 * PURPOSE: Implementation of the UnitQuantityInput class.
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

#include <UnitQuantityInput.hpp>

#include <SDF/UILayer/Metrics/Dimensionless/Quantity.hpp>
#include <SDF/UILayer/Metrics/Length/Quantity.hpp>
#include <SDF/UILayer/Metrics/Resolution/Quantity.hpp>

#include <SDF/UILayer/Metrics/Dimensionless/Units/Units.hpp>
#include <SDF/UILayer/Metrics/Length/Units/Units.hpp>
#include <SDF/UILayer/Metrics/Resolution/Units/Units.hpp>

#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QString>

namespace SDF::UILayer::Qt::View::CustomWidgets {
  UnitQuantityInput::UnitQuantityInput(QWidget *parent, ::Qt::WindowFlags f) :
  QWidget(parent, f),
  m_layout(new QHBoxLayout(this)),
  m_numberInput(new QLineEdit(this)),
  m_unitSelection(new QComboBox(this)),
  m_quantityType(QUANTITY_LENGTH),
  m_resolution(120.0f, Metrics::Resolution::Units::PixelsPerInch) {
    m_layout->setMargin(0);

    m_layout->addWidget(m_numberInput);
    m_layout->addWidget(m_unitSelection);

    updateUnitSelectionBox();
  }

  QuantityType UnitQuantityInput::quantityType() const {
    return m_quantityType;
  }

  void UnitQuantityInput::setQuantityType(QuantityType quantityType) {
    m_quantityType = quantityType;

    updateUnitSelectionBox();
  }

  Metrics::Resolution::Quantity UnitQuantityInput::resolution() const {
    return m_resolution;
  }

  void UnitQuantityInput::setResolution(Metrics::Resolution::Quantity resolution) {
    m_resolution = resolution;
    m_lengthQuantity = m_pixelsQuantity * m_resolution;

    updateDisplayedAmountAfterUnitChange();
  }

  // Private members.
  void UnitQuantityInput::updateUnitSelectionBox() {
    m_unitSelection->clear();

    switch(m_quantityType) {
      case QUANTITY_PIXELS:
        m_unitSelection->addItem(QString("px"), -1); // with pixels, we want to also allow for the inclusion of length
                                                     // units to be convertible by the widget's set resolution.
        // "fall thru" to add the remaining length units.
      case QUANTITY_LENGTH:
        for(int i(0); i < Metrics::Length::Units::LENGTH_UNIT_MAX;++i) {
          m_unitSelection->addItem(QString(Metrics::Length::Units::symbols[i].c_str()), i+1);
        }

        break;
      case QUANTITY_RESOLUTION:
        for(int i(0); i < Metrics::Resolution::Units::RESOLUTION_UNIT_MAX;++i) {
          m_unitSelection->addItem(QString(Metrics::Resolution::Units::symbols[i].c_str()), i);
        }

        break;
    }
  }

  void UnitQuantityInput::updateQuantityAfterAmountChange() {
    bool ok(false);
    float inputVal(m_numberInput->text().toFloat(&ok));
    int unitSelIndex(m_unitSelection->currentIndex());
    int unitIndex(m_unitSelection->itemData(unitSelIdx).toInt());

    if(ok) {
      switch(m_quantityType) {
        case QUANTITY_PIXELS:
          if(unitIndex == -1) { // Length units need separate treatment
            m_pixelsQuantity = Metrics::Dimensionless::Quantity(inputVal, Metrics::Dimensionless::One);
          } else {
            m_lengthQuantity = Metrics::Length::Quantity(inputVal, Metrics::Length::Units::units[unitSel-1]);
            m_pixelsQuantity = m_lengthQuantity * m_resolution;
          }
          break;
        case QUANTITY_LENGTH:
          m_lengthQuantity = Metrics::Length::Quantity(inputVal, Metrics::Length::Units::units[unitSel-1]);
          break;
        case QUANTITY_RESOLUTION:
          m_resolutionQuantity = Metrics::Resolution::Quantity(inputVal, Metrics::Resolution::Units[unitSel]);
          break;
      }
    }
  }

  void UnitQuantityInput::updateDisplayedAmountAfterUnitChange() {
    int unitSelIndex(m_unitSelection->currentIndex());
    int unitIndex(m_unitSelection->itemData(unitSelIdx).toInt());

    switch(m_quantityType) {
      case QUANTITY_PIXELS:
        if(unitIndex == -1) {
          m_numberInput->setText(
            QString::number(0.0 + m_pixelsQuantity->inUnitsOf(Metrics::Dimensionless::Units::One))
          );
        } else {
          m_numberInput->setText(
            QString::number(0.0 + m_lengthQuantity->inUnitsOf(Metrics::Length::Units::units[unitIndex]))
          );
        }

        break;
      case QUANTITY_LENGTH:
        m_numberInput->setText(
          QString::number(0.0 + m_lengthQuantity->inUnitsOf(Metrics::Length::Units::units[unitIndex]))
        );
        break;
      case QUANTITY_RESOLUTION:
        m_numberInput->setText(
          QString::number(0.0 + m_resolutionQuantity->inUnitsOf(Metrics::Resolution::Units::units[unitIndex]))
        );
        break;
      default:
        break;
    }
  }
}
