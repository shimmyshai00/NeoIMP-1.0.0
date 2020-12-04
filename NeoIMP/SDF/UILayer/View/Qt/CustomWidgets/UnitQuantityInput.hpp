#ifndef SDF_UILAYER_QT_VIEW_WIDGETS_UNITQUANTITYINPUT_HPP
#define SDF_UILAYER_QT_VIEW_WIDGETS_UNITQUANTITYINPUT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitQuantityInput.hpp
 * PURPOSE: Implementation of a custom Qt UI widget for inputting unitful quantities (like lengths).
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

#include <QWidget>

#include <SDF/UILayer/Metrics/Dimensionless/Quantity.hpp>
#include <SDF/UILayer/Metrics/Length/Quantity.hpp>
#include <SDF/UILayer/Metrics/Resolution/Quantity.hpp>

class QHBoxLayout;
class QLineEdit;
class QComboBox;

namespace SDF::UILayer::View::Qt::CustomWidgets {
  enum QuantityType {
    QUANTITY_PIXELS,
    QUANTITY_LENGTH,
    QUANTITY_RESOLUTION
  };

  class UnitQuantityInput : public QWidget {
    Q_OBJECT
  public:
    UnitQuantityInput(QWidget *parent = nullptr, ::Qt::WindowFlags f = ::Qt::WindowFlags());
    ~UnitQuantityInput() {}

    QuantityType quantityType() const;
    void setQuantityType(QuantityType quantityType);

    Metrics::Resolution::Quantity resolution() const;
    void setResolution(Metrics::Resolution::Quantity resolution);

    Metrics::Dimensionless::Quantity pixelsQuantity() const;
    void setPixelsQuantity(Metrics::Dimensionless::Quantity pixels);

    Metrics::Length::Quantity lengthQuantity() const;
    void setLengthQuantity(Metrics::Length::Quantity length);

    Metrics::Resolution::Quantity resolutionQuantity() const;
    void setResolutionQuantity(Metrics::Resolution::Quantity resolution);
  signals:
    void pixelsQuantityEdited(Metrics::Dimensionless::Quantity newPixels);
    void lengthQuantityEdited(Metrics::Length::Quantity newLength);
    void resolutionQuantityEdited(Metrics::Resolution::Quantity newResolution);
  public slots:
    void setResolutionSlot(Metrics::Resolution::Quantity resolution);
  private:
    // The sub-widgets comprising this widget.
    QHBoxLayout *m_layout;
    QLineEdit *m_numberInput;
    QComboBox *m_unitSelection;

    // The type of quantity we want to permit entry of.
    QuantityType m_quantityType;

    // The resolution used to convert between length and pixels.
    Metrics::Resolution::Quantity m_resolution;

    // The entered quantity.
    Metrics::Dimensionless::Quantity m_pixelsQuantity;
    Metrics::Length::Quantity m_lengthQuantity;
    Metrics::Resolution::Quantity m_resolutionQuantity;

    // Private member functions.
    void updateUnitSelectionBox();
    void updateQuantityAfterAmountChange();
    void updateDisplayedAmountAfterUnitChange();
  };
}

#endif
