#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_EDITABLESLIDER_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_EDITABLESLIDER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditableSlider.hpp
 * PURPOSE: Defines the EditableSlider class.
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
#include <QAbstractSlider>
#include <QBoxLayout>
#include <QSlider>
#include <QLineEdit>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  // Class:      EditableSlider
  // Purpose:    Provides a custom widget that allows the user to select a quantity using both a slider as well as
  //             typing it in via an edit box.
  // Parameters: None.
  class EditableSlider : public QWidget {
    Q_OBJECT
  public:
    EditableSlider(int min, int max, int val, ::Qt::Orientation orientation, QWidget *parent = nullptr);
    EditableSlider(::Qt::Orientation orientation, QWidget *parent = nullptr);
    EditableSlider(QWidget *parent = nullptr);

    int
    minimum() const;

    int
    maximum() const;

    int
    denom() const;

    int
    value() const;

    float
    valueF() const;

    const QString &
    unitSymbol() const;

    void
    setMinimum(int minimum);

    void
    setMaximum(int maximum);

    void
    setDenom(int denom);

    void
    setValue(int value);

    void
    setValueF(float value);

    void
    setUnitSymbol(const QString &unitSymbol);
  signals:
    void
    valueChanged(int value);

    void
    denomValueChanged(float denomValue);
  private:
    QBoxLayout *m_boxLayout;
    QSlider *m_slider;
    QLineEdit *m_editBox;

    int m_minimum;
    int m_maximum;
    int m_denom;

    QString m_unitSymbol;

    bool m_inhibitSync;

    void
    syncTextField();
  };
}

#endif
