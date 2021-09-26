#ifndef SDF_UILAYER_QTAPPLICATION_VIEW_CUSTOMWIDGETS_UNITQUANTITYEDIT_HPP
#define SDF_UILAYER_QTAPPLICATION_VIEW_CUSTOMWIDGETS_UNITQUANTITYEDIT_HPP

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

#include "../../../AbstractModel/Services/IMeasurementConversionService.hpp"
#include "../../../AbstractModel/Data/LengthUnit.hpp"
#include "../../../AbstractModel/Data/ResolutionUnit.hpp"

#include <QWidget>

namespace SDF::UILayer::QtApplication::View::CustomWidgets {
  // Class:      UnitQuantityEdit
  // Purpose:    Defines a custom widget for entering unitful physical quantities.
  // Parameters: None.
  class UnitQuantityEdit : public QWidget {
  public:
    enum QuantityMode {
      LENGTH,
      RESOLUTION
    };
  public:
    UnitQuantityEdit(AbstractModel::Services::IMeasurementConversionService *measurementConversionService,
                     QuantityMode quantityMode,
                     QWidget *parent = nullptr
                    );
    UnitQuantityEdit(QuantityMode quantityMode,
                     QWidget *parent = nullptr
                    );

    ~UnitQuantityEdit();

    void
    setMeasurementService(AbstractModel::Services::IMeasurementConversionService *measurementConversionService);

    void
    setQuantityMode(QuantityMode quantityMode);

    void
    setConvertResolution(float resolution, AbstractModel::Data::ResolutionUnit unit);

    void
    setEnteredQuantity(float quantity);

    void
    setLengthUnit(AbstractModel::Data::LengthUnit lengthUnit);

    void
    setResolutionUnit(AbstractModel::Data::ResolutionUnit resolutionUnit);

    QuantityMode
    quantityMode() const;

    float
    enteredQuantity() const;

    AbstractModel::Data::LengthUnit
    selectedLengthUnit() const;

    AbstractModel::Data::ResolutionUnit
    selectedResolutionUnit() const;

    float
    getEnteredQuantityInLengthUnit(AbstractModel::Data::LengthUnit unit) const;

    float
    getEnteredQuantityInResolutionUnit(AbstractModel::Data::ResolutionUnit unit) const;
  private:
    AbstractModel::Services::IMeasurementConversionService *m_measurementConversionService;
    QuantityMode m_quantityMode;

    float m_quantity;
    AbstractModel::Data::LengthUnit m_lengthUnit;
    AbstractModel::Data::ResolutionUnit m_resolutionUnit;

    float m_convResolution;
    AbstractModel::Data::ResolutionUnit m_convResolutionUnit;
  };
}

#endif
