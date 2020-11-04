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

class QHBoxLayout;
class QLineEdit;
class QComboBox;

namespace SDF::UILayer::Qt::View::CustomWidgets {
  enum QuantityType {
    QUANTITY_LENGTH,
    QUANTITY_RESOLUTION
  };

  class UnitQuantityInput : public QWidget {
    Q_OBJECT
  public:
    UnitQuantityInput(QWidget *parent = nullptr, ::Qt::WindowFlags f = ::Qt::WindowFlags());
    ~UnitQuantityInput() {}

    QuantityType quantityType();
    void setQuantityType(QuantityType quantityType);

    float resolutionPpi();
    void setResolutionPpi(float ppi);
  signals:
  private:
    // The sub-widgets comprising this widget.
    QHBoxLayout *m_layout;
    QLineEdit *m_numberInput;
    QComboBox *m_unitSelection;

    // The type of quantity we want to permit entry of.
    QuantityType m_quantityType;

    // The resolution used to convert between length and pixels, in pixels-per-inch (PPI).
    float m_resolutionPpi;
  };
}

#endif
