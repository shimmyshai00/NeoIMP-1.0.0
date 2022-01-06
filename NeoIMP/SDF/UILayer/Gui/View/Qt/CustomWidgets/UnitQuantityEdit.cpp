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

#include "../../../../AbstractModel/Defs/LengthUnitLabels.hpp"
#include "../../../../AbstractModel/Defs/ResolutionUnitLabels.hpp"

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets {
  UnitQuantityEdit::UnitQuantityEdit(AbstractModel::IMetricsService *metricsService,
                                     QuantityMode quantityMode,
                                     QWidget *parent
                                    )
    : QWidget(parent),
      m_layout(new QBoxLayout(QBoxLayout::LeftToRight, this)),
      m_quantityEdit(new QLineEdit("0.0")),
      m_unitSelect(new QComboBox),
      m_metricsService(nullptr),
      m_quantityMode(quantityMode),
      m_lengthUnit(AbstractModel::Defs::LENGTH_UNIT_PIXEL),
      m_resolutionUnit(AbstractModel::Defs::RESOLUTION_UNIT_PPI),
      m_convResolutionUnit(AbstractModel::Defs::RESOLUTION_UNIT_PPI)
  {
    using namespace AbstractModel;

    // Create the layout for this widget, which consists of a line edit to enter the quantity, with a combo box to the
    // right for selecting the unit.
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_quantityEdit);
    m_layout->addWidget(m_unitSelect);

    setMetricsService(metricsService);
    setQuantityMode(m_quantityMode);

    // Hook the text field itself.
    QObject::connect(m_quantityEdit, &QLineEdit::textEdited, [=](const QString &newText) {
      bool ok(false);
      float conv(newText.toFloat(&ok));
      if(ok) {
        internalSetQuantity(conv, false, true);
      }
    });

    // Hook the combo box to the text field.
    QObject::connect(m_unitSelect, QOverload<int>::of(&QComboBox::activated), [=](int index) {
      switch(m_quantityMode) {
        case LENGTH:
          internalSetLengthUnit(static_cast<Defs::ELengthUnit>(index), false, true);
          syncQuantityDisplay();
          break;
        case RESOLUTION:
          internalSetResolutionUnit(static_cast<Defs::EResolutionUnit>(index), false, true);
          syncQuantityDisplay();
          break;
      }
    });
  }

  UnitQuantityEdit::UnitQuantityEdit(QuantityMode quantityMode,
                                     QWidget *parent
                                    )
    : UnitQuantityEdit(nullptr, quantityMode, parent)
  {
  }

  UnitQuantityEdit::UnitQuantityEdit(QWidget *parent)
    : UnitQuantityEdit(nullptr, LENGTH, parent)
  {
  }


  UnitQuantityEdit::~UnitQuantityEdit() {
  }

  void
  UnitQuantityEdit::setMetricsService(AbstractModel::IMetricsService *metricsService) {
    using namespace AbstractModel;

    m_metricsService = metricsService;

    if(m_metricsService != nullptr) {
      m_convResolution = m_metricsService->createConvertibleResolution(120.0f, Defs::RESOLUTION_UNIT_PPI);
    }
  }

  void
  UnitQuantityEdit::setQuantityMode(QuantityMode quantityMode) {
    using namespace AbstractModel;

    m_quantityMode = quantityMode;

    // Populate the unit list box according to this mode.
    m_unitSelect->clear();
    switch(quantityMode) {
      case LENGTH:
        for(std::size_t i(0); i < Defs::LENGTH_UNIT_MAX; ++i) {
          m_unitSelect->addItem(Defs::g_lengthUnitSymbols[i], static_cast<uint>(i));
        }
        break;
      case RESOLUTION:
        for(std::size_t i(0); i < Defs::RESOLUTION_UNIT_MAX; ++i) {
          m_unitSelect->addItem(Defs::g_resolutionUnitSymbols[i], static_cast<uint>(i));
        }
        break;
    }
  }

  void
  UnitQuantityEdit::setConvertResolution(float resolution) {
    internalSetConvRes(resolution, true);
  }

  void
  UnitQuantityEdit::setConvertResolutionUnit(AbstractModel::Defs::EResolutionUnit unit) {
    internalSetConvResUnit(unit, true);
  }

  void
  UnitQuantityEdit::setEnteredQuantity(float quantity) {
    internalSetQuantity(quantity, true, true);
  }

  void
  UnitQuantityEdit::setLengthUnit(AbstractModel::Defs::ELengthUnit lengthUnit) {
    internalSetLengthUnit(lengthUnit, true, true);
  }

  void
  UnitQuantityEdit::setResolutionUnit(AbstractModel::Defs::EResolutionUnit resolutionUnit) {
    internalSetResolutionUnit(resolutionUnit, true, true);
  }

  UnitQuantityEdit::QuantityMode
  UnitQuantityEdit::quantityMode() const {
    return m_quantityMode;
  }

  float
  UnitQuantityEdit::enteredQuantity() const {
    switch(m_quantityMode) {
      case LENGTH:
        return getEnteredQuantityInLengthUnit(m_lengthUnit);
        break;
      case RESOLUTION:
        return getEnteredQuantityInResolutionUnit(m_resolutionUnit);
        break;
    }
  }

  AbstractModel::Defs::ELengthUnit
  UnitQuantityEdit::selectedLengthUnit() const {
    return m_lengthUnit;
  }

  AbstractModel::Defs::EResolutionUnit
  UnitQuantityEdit::selectedResolutionUnit() const {
    return m_resolutionUnit;
  }

  float
  UnitQuantityEdit::getEnteredQuantityInLengthUnit(AbstractModel::Defs::ELengthUnit unit) const {
    switch(m_quantityMode) {
      case LENGTH:
        if(m_lengthQuantity) {
          return m_lengthQuantity->in(unit);
        } else {
          return 0.0f;
        }
        break;
      default:
        return 0.0f;
    }
  }

  float
  UnitQuantityEdit::getEnteredQuantityInResolutionUnit(AbstractModel::Defs::EResolutionUnit unit) const {
    switch(m_quantityMode) {
      case RESOLUTION:
        if(m_resolutionQuantity) {
          return m_resolutionQuantity->in(unit);
        } else {
          return 0.0f;
        }
        break;
      default:
        return 0.0f;
    }
  }
}

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets {
  // Private members.
  void
  UnitQuantityEdit::syncQuantityDisplay() {
    float quantityInDispUnit;

    switch(m_quantityMode) {
      case LENGTH:
        quantityInDispUnit = m_lengthQuantity->in(m_lengthUnit);
        break;
      case RESOLUTION:
        quantityInDispUnit = m_resolutionQuantity->in(m_resolutionUnit);
        break;
    }

    m_quantityEdit->setText(QString::number(quantityInDispUnit, 'g', 7));
  }

  void
  UnitQuantityEdit::syncUnitSelector() {
    switch(m_quantityMode) {
      case LENGTH:
        m_unitSelect->setCurrentIndex(m_lengthUnit);
        break;
      case RESOLUTION:
        m_unitSelect->setCurrentIndex(m_resolutionUnit);
        break;
    }
  }

  void
  UnitQuantityEdit::internalSetQuantity(float quantity,
                                        bool updateGui,
                                        bool signal
                                       )
  {
    using namespace AbstractModel;

    if(m_metricsService != nullptr) {
      float dispQuantity(0.0f);

      switch(m_quantityMode) {
        case LENGTH:
          m_lengthQuantity = m_metricsService->createConvertibleLength(quantity, m_lengthUnit, m_convResolution.get());
          break;
        case RESOLUTION:
          m_resolutionQuantity = m_metricsService->createConvertibleResolution(quantity, m_resolutionUnit);
          break;
      }

      if(updateGui) {
        syncQuantityDisplay();
      }

      if(signal) {
        quantityChanged(quantity);
      }
    }
  }

  void
  UnitQuantityEdit::internalSetLengthUnit(AbstractModel::Defs::ELengthUnit lengthUnit,
                                          bool updateGui,
                                          bool signal
                                         )
  {
    m_lengthUnit = lengthUnit;

    if(updateGui) {
      syncUnitSelector();
      syncQuantityDisplay();
    }

    if(signal) {
      lengthUnitChanged(lengthUnit);
    }
  }

  void
  UnitQuantityEdit::internalSetResolutionUnit(AbstractModel::Defs::EResolutionUnit resolutionUnit,
                                              bool updateGui,
                                              bool signal
                                             )
  {
    m_resolutionUnit = resolutionUnit;

    if(updateGui) {
      syncUnitSelector();
      syncQuantityDisplay();
    }

    if(signal) {
      resolutionUnitChanged(resolutionUnit);
    }
  }

  void
  UnitQuantityEdit::internalSetConvRes(float convRes,
                                       bool updateGui
                                      )
  {
    if(m_metricsService != nullptr) {
      m_convResolution = m_metricsService->createConvertibleResolution(convRes, m_convResolutionUnit);
      if(m_quantityMode == LENGTH) {
        m_lengthQuantity = m_metricsService->createConvertibleLength(m_lengthQuantity->in(m_lengthUnit),
                                                                     m_lengthUnit,
                                                                     m_convResolution.get()
                                                                    );
      }

      if(updateGui) {
        syncQuantityDisplay();
      }
    }
  }

  void
  UnitQuantityEdit::internalSetConvResUnit(AbstractModel::Defs::EResolutionUnit convResUnit,
                                           bool updateGui
                                          )
  {
    m_convResolutionUnit = convResUnit;

    if(updateGui) {
      syncQuantityDisplay();
    }
  }
}
