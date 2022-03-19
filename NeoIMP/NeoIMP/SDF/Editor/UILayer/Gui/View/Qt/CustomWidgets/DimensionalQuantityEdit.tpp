#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_DIMENSIONALQUANTITYEDIT_TPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_DIMENSIONALQUANTITYEDIT_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DimensionalQuantityEdit.tpp
 * PURPOSE: Implements the DimensionalQuantityEdit template.
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
#include <QString>

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  // Class:      DQEValidator
  // Purpose:    Provides a custom validator to properly validate the floating-point ranges on
  //             the entered input.
  // Parameters: None.
  class DQEValidator : public QDoubleValidator {
  public:
    explicit DQEValidator(QObject *parent = nullptr)
      : QDoubleValidator(parent)
    {}

    DQEValidator(double bottom, double top, int decimals, QObject *parent = nullptr)
      : QDoubleValidator(bottom, top, decimals, parent)
    {}

    virtual void fixup(QString &input) const override {
      bool ok(false);
      double attemptConv(input.toDouble(&ok));
      if(ok) {
        // valid number, just out of range
        input = QString::number(std::clamp(attemptConv, bottom(), top()), 'f', decimals());
      } else {
        // not a valid number; can't do nothing, sorry :(
      }
    }
  };
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  template<class UnitEnumT>
  DimensionalQuantityEdit<UnitEnumT>::DimensionalQuantityEdit(
    const char *unitNameStrings[],
    std::size_t numUnitsToAdd,
    QWidget *parent
  )
    : DQESignalsSlots(parent),
      m_layout(new QBoxLayout(QBoxLayout::LeftToRight, this)),
      m_quantityEdit(new QLineEdit("0.0")),
      m_unitSelect(new QComboBox),
      m_rangeValidator(new View::Qt::Impl::DQEValidator(0.0, 1.0, 2))
  {
    using namespace AbstractModel;

    // Create the layout for this widget, which consists of a line edit to enter the quantity, with
    // a combo box to the right for selecting the unit.
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_quantityEdit);
    m_layout->addWidget(m_unitSelect);

    m_rangeValidator->setNotation(QDoubleValidator::StandardNotation);
    m_quantityEdit->setValidator(m_rangeValidator);

    // Disable the widget until primed with model services.
    m_quantityEdit->setEnabled(false);
    m_unitSelect->setEnabled(false);

    // Populate the list box with the unit names given.
    for(std::size_t i(0); i < numUnitsToAdd; ++i) {
      m_unitSelect->addItem(unitNameStrings[i], static_cast<uint>(i));
    }

    // Hook signals.
    connect(m_quantityEdit, &QLineEdit::textEdited, this,
      &DimensionalQuantityEdit::quantityTouched);

    connect(m_quantityEdit, &QLineEdit::editingFinished, [=]() {
      bool ok(false);
      double enteredValue(m_quantityEdit->text().toDouble(&ok));
      if(ok) {
        if(m_quantityEdit->text() != m_lastQuantityText) {
          m_lastQuantityText = m_quantityEdit->text();
          handleQuantityChangedByUser(enteredValue);
        }
      }
    });

    connect(m_unitSelect, QOverload<int>::of(&QComboBox::activated), [&](int index) {
      handleUnitChangedByUser(static_cast<UnitEnumT>(index));
    });
  }

  template<class UnitEnumT>
  DimensionalQuantityEdit<UnitEnumT>::~DimensionalQuantityEdit() {
    m_quantityEdit->setValidator(nullptr);
    delete m_rangeValidator;
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  // Private members.
  template<class UnitEnumT>
  bool
  DimensionalQuantityEdit<UnitEnumT>::setDisplayText(QString text) {
    bool didChange(m_lastQuantityText != text);

    m_quantityEdit->setText(text);
    m_lastQuantityText = text;

    return didChange;
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  template<class UnitEnumT>
  void
  DimensionalQuantityEdit<UnitEnumT>::notifyModelConnected() {
    m_quantityEdit->setEnabled(true);
    m_unitSelect->setEnabled(true);
  }

  template<class UnitEnumT>
  void
  DimensionalQuantityEdit<UnitEnumT>::notifyModelDisconnected() {
    m_quantityEdit->setEnabled(false);
    m_unitSelect->setEnabled(false);
  }

  template<class UnitEnumT>
  void
  DimensionalQuantityEdit<UnitEnumT>::setDisplayValidatorMinLimit(float minLimit) {
    m_rangeValidator->setBottom(minLimit);
  }

  template<class UnitEnumT>
  void
  DimensionalQuantityEdit<UnitEnumT>::setDisplayValidatorMaxLimit(float maxLimit) {
    m_rangeValidator->setTop(maxLimit);
  }

  template<class UnitEnumT>
  void
  DimensionalQuantityEdit<UnitEnumT>::setDisplayQuantity(float quantity) {
    setDisplayText(QString::number(quantity, 'f', 2));
  }

  template<class UnitEnumT>
  void
  DimensionalQuantityEdit<UnitEnumT>::setDisplayUnit(UnitEnumT unit) {
    m_unitSelect->setCurrentIndex(unit);
  }
}

#endif
