/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditableSlider.hpp
 * PURPOSE: Implements the EditableSlider class.
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

#include "EditableSlider.hpp"

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  EditableSlider::EditableSlider(int min, int max, int val, ::Qt::Orientation orientation, QWidget *parent)
    : m_boxLayout(new QBoxLayout(orientation == ::Qt::Horizontal ? QBoxLayout::LeftToRight : QBoxLayout::TopToBottom,
                                 this
                                )
                 ),
      m_slider(new QSlider(orientation, nullptr)),
      m_editBox(new QLineEdit),
      m_minimum(min),
      m_maximum(max),
      m_denom(1),
      m_unitSymbol("")
  {
    m_slider->setMinimum(m_minimum);
    m_slider->setMaximum(m_maximum);
    m_slider->setValue(val);

    m_boxLayout->addWidget(m_slider, 0);
    m_boxLayout->addWidget(m_editBox, 1);

    connect(m_slider, &QSlider::valueChanged, this, &EditableSlider::valueChanged);
    connect(m_slider, &QSlider::valueChanged, [=](int value) {
      denomValueChanged((0.0 + value) / m_denom);
      syncTextField();
    });

    connect(m_editBox, &QLineEdit::textEdited, [=](const QString &text) {
      QString unitSymbolClipped(text);
      unitSymbolClipped.remove(m_unitSymbol); // let the user enter a unit symbol optionally

      bool ok(false);
      int newValue(unitSymbolClipped.toInt(&ok, 10));
      if(ok) {
        m_slider->setValue(newValue);
      }
    });

    syncTextField();
  }

  EditableSlider::EditableSlider(::Qt::Orientation orientation, QWidget *parent)
    : EditableSlider(1, 100, 1, orientation, parent)
  {
  }

  EditableSlider::EditableSlider(QWidget *parent)
    : EditableSlider(::Qt::Horizontal, parent)
  {
  }

  int
  EditableSlider::minimum() const {
    return m_minimum;
  }

  int
  EditableSlider::maximum() const {
    return m_maximum;
  }

  int
  EditableSlider::denom() const {
    return m_denom;
  }

  int
  EditableSlider::value() const {
    return m_slider->value();
  }

  float
  EditableSlider::valueF() const {
    return (0.0 + m_slider->value()) / m_denom;
  }

  const QString &
  EditableSlider::unitSymbol() const {
    return m_unitSymbol;
  }

  void
  EditableSlider::setMinimum(int minimum) {
    m_minimum = minimum;

    m_slider->setMinimum(minimum);
    syncTextField();
  }

  void
  EditableSlider::setMaximum(int maximum) {
    m_maximum = maximum;

    m_slider->setMaximum(maximum);
    syncTextField();
  }

  void
  EditableSlider::setDenom(int denom) {
    m_denom = denom;
    syncTextField();
  }

  void
  EditableSlider::setUnitSymbol(const QString &unitSymbol) {
    m_unitSymbol = unitSymbol;
    syncTextField();
  }

  // Private members.
  void
  EditableSlider::syncTextField() {
    m_editBox->setText(QString::number(m_slider->value()) + " " + m_unitSymbol);
  }
}
