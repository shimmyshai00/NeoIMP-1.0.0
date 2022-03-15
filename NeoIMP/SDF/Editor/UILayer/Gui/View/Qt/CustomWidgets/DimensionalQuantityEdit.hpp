#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_DIMENSIONALQUANTITYEDIT_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_DIMENSIONALQUANTITYEDIT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DimensionalQuantityEdit.hpp
 * PURPOSE: Defines the DimensionalQuantityEdit template.
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

#include "../../../../AbstractModel/IMetricsService.hpp"

#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleValidator>

#include <memory>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  namespace Impl {
    // Class:      DQESignalsSlots
    // Purpose:    Defines the signals and slots for all dimensional quantity editors. This is to
    //             appease the Qt MOC which cannot compile templates. When adding a new dimensional
    //             unit type, one must duplicate the methods here for those types.
    // Parameters: None.
    class DQESignalsSlots : public QWidget {
      Q_OBJECT
    public:
      explicit DQESignalsSlots(QWidget *parent = 0)
        : QWidget(parent) {}

    public slots:
      virtual void
      setQuantity(float quantity) {}

      virtual void
      setUnit(AbstractModel::Defs::ELengthUnit unit) {}

      virtual void
      setUnit(AbstractModel::Defs::EResolutionUnit unit) {}
    signals:
      void
      quantityTouched();

      void
      quantityChanged(float quantity);

      void
      quantityChangedByUser(float quantity);

      void
      unitChanged(AbstractModel::Defs::ELengthUnit unit);

      void
      unitChanged(AbstractModel::Defs::EResolutionUnit unit);

      void
      unitChangedByUser(AbstractModel::Defs::ELengthUnit unit);

      void
      unitChangedByUser(AbstractModel::Defs::EResolutionUnit unit);
    };
  }

  // Class:      DimensionalQuantityEdit
  // Purpose:    Provides a base class (not interface) for creating edit widgets for entering
  //             numerical quantities with a physical dimension, or class of units associated with
  //             them.
  // Parameters: UnitEnumT - The enumeration type for the dimensional units used.
  template<class UnitEnumT>
  class DimensionalQuantityEdit : public Impl::DQESignalsSlots {
  public:
    DimensionalQuantityEdit(const char *unitNameStrings[],
                            std::size_t numUnitsToAdd,
                            AbstractModel::IMetricsService *metricsService = nullptr,
                            QWidget *parent = nullptr
                           );

    ~DimensionalQuantityEdit();

    virtual void
    setMetricsService(AbstractModel::IMetricsService *metricsService);

    virtual std::pair<float, UnitEnumT>
    minLimit() const = 0;

    virtual std::pair<float, UnitEnumT>
    maxLimit() const = 0;

    virtual float
    quantity() const = 0;

    virtual UnitEnumT
    unit() const = 0;

    virtual void
    setMinLimit(float minLimit, UnitEnumT unit) = 0;

    virtual void
    setMaxLimit(float maxLimit, UnitEnumT unit) = 0;

    virtual void
    setQuantity(float quantity) = 0;

    virtual void
    setUnit(UnitEnumT unit) = 0;
  private:
    QBoxLayout *m_layout;
    QLineEdit *m_quantityEdit;
    QComboBox *m_unitSelect;
    QDoubleValidator *m_rangeValidator;

    QString m_lastQuantityText;

    bool
    setDisplayText(QString text);
  protected:
    AbstractModel::IMetricsService *m_metricsService;

    void
    setDisplayValidatorMinLimit(float minLimit);

    void
    setDisplayValidatorMaxLimit(float maxLimit);

    void
    setDisplayQuantity(float quantity);

    void
    setDisplayUnit(UnitEnumT unit);

    virtual void
    handleQuantityChangedByUser(float quantity) = 0;

    virtual void
    handleUnitChangedByUser(UnitEnumT unit) = 0;
  };
}

#include "DimensionalQuantityEdit.tpp"

#endif
