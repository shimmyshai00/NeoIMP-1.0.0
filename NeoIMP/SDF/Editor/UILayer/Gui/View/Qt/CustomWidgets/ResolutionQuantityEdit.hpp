#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_RESOLUTIONQUANTITYEDIT_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_RESOLUTIONQUANTITYEDIT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionQuantityEdit.hpp
 * PURPOSE: Defines the ResolutionQuantityEdit class.
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

#include "../../../../AbstractModel/Defs/EResolutionUnit.hpp"
#include "../../../../AbstractModel/Defs/IUnitConvertible.hpp"
#include "../../../../AbstractModel/Metrics/IConvertResolutionService.hpp"

#include "DimensionalQuantityEdit.hpp"

#include <QWidget>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  // Class:      ResolutionQuantityEdit
  // Purpose:    Defines a custom widget for entering resolution quantities.
  // Parameters: None.
  class ResolutionQuantityEdit
    : public DimensionalQuantityEdit<AbstractModel::Defs::EResolutionUnit>
  {
    Q_OBJECT
  public:
    ResolutionQuantityEdit(
      AbstractModel::Metrics::IConvertResolutionService *convertResolutionService = nullptr,
      QWidget *parent = nullptr
    );
    ResolutionQuantityEdit(QWidget *parent = nullptr);

    void
    setConversionService(
      AbstractModel::Metrics::IConvertResolutionService *convertResolutionService
    );

    std::pair<float, AbstractModel::Defs::EResolutionUnit>
    minLimit() const;

    std::pair<float, AbstractModel::Defs::EResolutionUnit>
    maxLimit() const;

    float
    quantity() const;

    AbstractModel::Defs::EResolutionUnit
    unit() const;

    void
    setMinLimit(float minLimit, AbstractModel::Defs::EResolutionUnit unit);

    void
    setMaxLimit(float maxLimit, AbstractModel::Defs::EResolutionUnit unit);
  public slots:
    void
    setQuantity(float quantity);

    void
    setUnit(AbstractModel::Defs::EResolutionUnit unit);
  private:
    AbstractModel::Metrics::IConvertResolutionService *m_convertResolutionService;

    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::EResolutionUnit>>
      m_convertibleMinLimit;
    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::EResolutionUnit>>
      m_convertibleMaxLimit;
    std::shared_ptr<AbstractModel::Defs::IUnitConvertible<AbstractModel::Defs::EResolutionUnit>>
      m_convertibleQuantity;

    AbstractModel::Defs::EResolutionUnit m_currentUnit;
  protected:
    void
    handleQuantityChangedByUser(float quantity);

    void
    handleUnitChangedByUser(AbstractModel::Defs::EResolutionUnit unit);
  };
}

#endif
