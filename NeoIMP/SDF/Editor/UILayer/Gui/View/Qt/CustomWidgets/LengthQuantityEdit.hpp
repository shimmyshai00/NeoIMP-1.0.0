#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_LENGTHQUANTITYEDIT_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_LENGTHQUANTITYEDIT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthQuantityEdit.hpp
 * PURPOSE: Defines the LengthQuantityEdit class.
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

#include "../../../../AbstractModel/Defs/LengthUnit.hpp"
#include "../../../../AbstractModel/Defs/ResolutionUnit.hpp"
#include "../../../../AbstractModel/Defs/IUnitConvertible.hpp"
#include "../../../../AbstractModel/Metrics/IConvertLengthService.hpp"
#include "../../../../AbstractModel/Metrics/IConvertResolutionService.hpp"

#include "DimensionalQuantityEdit.hpp"

#include <QWidget>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  // Class:      LengthQuantityEdit
  // Purpose:    Defines a custom widget for entering resolution quantities.
  // Parameters: None.
  class LengthQuantityEdit
    : public DimensionalQuantityEdit<AbstractModel::Defs::LengthUnit>
  {
    Q_OBJECT
  public:
    LengthQuantityEdit(
      AbstractModel::Metrics::IConvertLengthService *convertLengthService,
      AbstractModel::Metrics::IConvertResolutionService *convertResolutionService,
      QWidget *parent = nullptr
    );

    LengthQuantityEdit(QWidget *parent = nullptr);

    void
    setConversionServices(
      AbstractModel::Metrics::IConvertLengthService *convertLengthService,
      AbstractModel::Metrics::IConvertResolutionService *convertResolutionService
    );

    std::pair<float, AbstractModel::Defs::LengthUnit>
    minLimit() const;

    std::pair<float, AbstractModel::Defs::LengthUnit>
    maxLimit() const;

    float
    quantity() const;

    AbstractModel::Defs::LengthUnit
    unit() const;

    void
    setMinLimit(float minLimit, AbstractModel::Defs::LengthUnit unit);

    void
    setMaxLimit(float maxLimit, AbstractModel::Defs::LengthUnit unit);

    void
    setQuantity(float quantity);

    void
    setUnit(AbstractModel::Defs::LengthUnit unit);
  public slots:
    void
    setReferenceResolution(float resolution);

    void
    setReferenceResolutionUnit(AbstractModel::Defs::ResolutionUnit unit);
  private:
    AbstractModel::Metrics::IConvertLengthService *m_convertLengthService;
    AbstractModel::Metrics::IConvertResolutionService *m_convertResolutionService;

    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::LengthUnit>>
      m_convertibleMinLimit;
    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::LengthUnit>>
      m_convertibleMaxLimit;
    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::LengthUnit>>
      m_convertibleQuantity;

    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::ResolutionUnit>>
      m_convertibleResolution;

    AbstractModel::Defs::LengthUnit m_currentUnit;
    AbstractModel::Defs::ResolutionUnit m_currentResolutionUnit;
  protected:
    void
    handleQuantityChangedByUser(float quantity);

    void
    handleUnitChangedByUser(AbstractModel::Defs::LengthUnit unit);
  };
}

#endif
