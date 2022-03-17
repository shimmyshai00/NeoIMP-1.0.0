/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionQuantityEdit.cpp
 * PURPOSE: Implements the ResolutionQuantityEdit class.
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

#include "ResolutionQuantityEdit.hpp"

#include "../../../../AbstractModel/Defs/ResolutionUnitLabels.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  ResolutionQuantityEdit::ResolutionQuantityEdit(
    AbstractModel::IMetricsService *metricsService,
    QWidget *parent
  )
    : DimensionalQuantityEdit(AbstractModel::Defs::g_resolutionUnitSymbols,
                              AbstractModel::Defs::RESOLUTION_UNIT_MAX,
                              metricsService,
                              parent
                             ),
      m_currentUnit(AbstractModel::Defs::RESOLUTION_UNIT_PPI)
  {
  }

  ResolutionQuantityEdit::ResolutionQuantityEdit(QWidget *parent)
    : DimensionalQuantityEdit(AbstractModel::Defs::g_resolutionUnitSymbols,
                              AbstractModel::Defs::RESOLUTION_UNIT_MAX,
                              nullptr,
                              parent
                             ),
      m_currentUnit(AbstractModel::Defs::RESOLUTION_UNIT_PPI)
  {
  }

  void
  ResolutionQuantityEdit::setMetricsService(AbstractModel::IMetricsService *metricsService) {
    DimensionalQuantityEdit::setMetricsService(metricsService);

    if(metricsService != nullptr) {
      // defaults we could not specify elsewhere
      m_convertibleMinLimit = m_metricsService->createConvertibleResolution(1.0f,
        AbstractModel::Defs::RESOLUTION_UNIT_PPI);
      m_convertibleMaxLimit = m_metricsService->createConvertibleResolution(1000.0f,
        AbstractModel::Defs::RESOLUTION_UNIT_PPI);
      m_convertibleQuantity = m_metricsService->createConvertibleResolution(300.0f,
        AbstractModel::Defs::RESOLUTION_UNIT_PPI);
    }
  }

  std::pair<float, AbstractModel::Defs::EResolutionUnit>
  ResolutionQuantityEdit::minLimit() const {
    if(m_convertibleMinLimit) {
      return std::make_pair(m_convertibleMinLimit->in(m_currentUnit), m_currentUnit);
    } else {
      return std::make_pair(0.0f, m_currentUnit);
    }
  }

  std::pair<float, AbstractModel::Defs::EResolutionUnit>
  ResolutionQuantityEdit::maxLimit() const {
    if(m_convertibleMaxLimit) {
      return std::make_pair(m_convertibleMaxLimit->in(m_currentUnit), m_currentUnit);
    } else {
      return std::make_pair(0.0f, m_currentUnit);
    }
  }

  float
  ResolutionQuantityEdit::quantity() const {
    if(m_convertibleQuantity) {
      return m_convertibleQuantity->in(m_currentUnit);
    } else {
      return 0.0f;
    }
  }

  AbstractModel::Defs::EResolutionUnit
  ResolutionQuantityEdit::unit() const {
    return m_currentUnit;
  }

  void
  ResolutionQuantityEdit::setMinLimit(float minLimit, AbstractModel::Defs::EResolutionUnit unit) {
    if(m_metricsService != nullptr) {
      m_convertibleMinLimit = m_metricsService->createConvertibleResolution(minLimit, unit);
      setDisplayValidatorMinLimit(m_convertibleMinLimit->in(m_currentUnit));
    }
  }

  void
  ResolutionQuantityEdit::setMaxLimit(float maxLimit, AbstractModel::Defs::EResolutionUnit unit) {
    if(m_metricsService != nullptr) {
      m_convertibleMaxLimit = m_metricsService->createConvertibleResolution(maxLimit, unit);
      setDisplayValidatorMaxLimit(m_convertibleMaxLimit->in(m_currentUnit));
    }
  }

  void
  ResolutionQuantityEdit::setQuantity(float quantity) {
    if(m_metricsService != nullptr) {
      m_convertibleQuantity =
        m_metricsService->createConvertibleResolution(quantity, m_currentUnit);
      setDisplayQuantity(m_convertibleQuantity->in(m_currentUnit));
      quantityChanged(quantity);
    }
  }

  void
  ResolutionQuantityEdit::setUnit(AbstractModel::Defs::EResolutionUnit unit) {
    m_currentUnit = unit;
    setDisplayValidatorMinLimit(m_convertibleMinLimit->in(m_currentUnit));
    setDisplayValidatorMaxLimit(m_convertibleMaxLimit->in(m_currentUnit));
    setDisplayQuantity(m_convertibleQuantity->in(m_currentUnit));
    setDisplayUnit(unit);
    unitChanged(unit);
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  // Protected members.
  void
  ResolutionQuantityEdit::handleQuantityChangedByUser(float quantity) {
    if(m_metricsService != nullptr) {
      m_convertibleQuantity =
        m_metricsService->createConvertibleResolution(quantity, m_currentUnit);

      quantityChanged(quantity);
      quantityChangedByUser(quantity);
    }
  }

  void
  ResolutionQuantityEdit::handleUnitChangedByUser(AbstractModel::Defs::EResolutionUnit unit) {
    setUnit(unit);
    unitChanged(unit);
    unitChangedByUser(unit);
  }
}
