#ifndef SDF_UILAYER_QT_VIEW_CUSTOMWIDGETS_UNITQUANTITYEDIT_HPP
#define SDF_UILAYER_QT_VIEW_CUSTOMWIDGETS_UNITQUANTITYEDIT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitQuantityEdit.hpp
 * PURPOSE: Defines the UnitQuantityEdit class.
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

#include "../../../AbstractModel/Defs/ELengthUnit.hpp"
#include "../../../AbstractModel/Defs/EResolutionUnit.hpp"
#include "../../../AbstractModel/IMetricsService.hpp"

#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QComboBox>

#include <memory>

namespace SDF::UILayer::Qt::View::CustomWidgets {
  // Class:      UnitQuantityEdit
  // Purpose:    Defines a custom widget for entering unitful physical quantities.
  // Parameters: None.
  class UnitQuantityEdit : public QWidget {
    Q_OBJECT
    Q_PROPERTY(float m_quantity READ enteredQuantity WRITE setEnteredQuantity)
  public:
    enum QuantityMode {
      LENGTH,
      RESOLUTION
    };
  public:
    UnitQuantityEdit(AbstractModel::IMetricsService *metricsService,
                     QuantityMode quantityMode,
                     QWidget *parent = nullptr
                    );
    UnitQuantityEdit(QuantityMode quantityMode,
                     QWidget *parent = nullptr
                    );
    UnitQuantityEdit(QWidget *parent = nullptr);

    ~UnitQuantityEdit();

    void
    setMetricsService(AbstractModel::IMetricsService *metricsService);

    QuantityMode
    quantityMode() const;

    float
    enteredQuantity() const;

    AbstractModel::Defs::ELengthUnit
    selectedLengthUnit() const;

    AbstractModel::Defs::EResolutionUnit
    selectedResolutionUnit() const;

    float
    getEnteredQuantityInLengthUnit(AbstractModel::Defs::ELengthUnit unit) const;

    float
    getEnteredQuantityInResolutionUnit(AbstractModel::Defs::EResolutionUnit unit) const;
  signals:
    void
    quantityChanged(float quantity);

    void
    lengthUnitChanged(AbstractModel::Defs::ELengthUnit unit);

    void
    resolutionUnitChanged(AbstractModel::Defs::EResolutionUnit unit);
  public slots:
    void
    setQuantityMode(QuantityMode quantityMode);

    void
    setConvertResolution(float resolution);

    void
    setConvertResolutionUnit(AbstractModel::Defs::EResolutionUnit unit);

    void
    setEnteredQuantity(float quantity);

    void
    setLengthUnit(AbstractModel::Defs::ELengthUnit lengthUnit);

    void
    setResolutionUnit(AbstractModel::Defs::EResolutionUnit resolutionUnit);
  private:
    QBoxLayout *m_layout;
    QLineEdit *m_quantityEdit;
    QComboBox *m_unitSelect;

    AbstractModel::IMetricsService *m_metricsService;
    QuantityMode m_quantityMode;

    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::ELengthUnit>> m_lengthQuantity;
    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::EResolutionUnit>> m_resolutionQuantity;
    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::EResolutionUnit>> m_convResolution;

    AbstractModel::Defs::ELengthUnit m_lengthUnit;
    AbstractModel::Defs::EResolutionUnit m_resolutionUnit;
    AbstractModel::Defs::EResolutionUnit m_convResolutionUnit;

    void
    syncQuantityDisplay();

    void
    syncUnitSelector();

    void
    internalSetQuantity(float quantity,
                        bool updateGui,
                        bool signal
                       );

    void
    internalSetLengthUnit(AbstractModel::Defs::ELengthUnit lengthUnit,
                          bool updateGui,
                          bool signal
                         );

    void
    internalSetResolutionUnit(AbstractModel::Defs::EResolutionUnit resolutionUnit,
                              bool updateGui,
                              bool signal
                             );

    void
    internalSetConvRes(float convRes,
                       bool updateGui
                      );

    void
    internalSetConvResUnit(AbstractModel::Defs::EResolutionUnit convResUnit,
                           bool updateGui
                          );
  };
}

#endif
