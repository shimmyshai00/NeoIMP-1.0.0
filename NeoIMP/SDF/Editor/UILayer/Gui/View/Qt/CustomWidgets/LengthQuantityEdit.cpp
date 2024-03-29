/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthQuantityEdit.cpp
 * PURPOSE: Implements the LengthQuantityEdit class.
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

#include "LengthQuantityEdit.hpp"

#include "../../../../AbstractModel/Defs/length_unit_labels.hpp"

#include <iostream>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  LengthQuantityEdit::LengthQuantityEdit(
    AbstractModel::Metrics::IConvertLengthService *convertLengthService,
    AbstractModel::Metrics::IConvertResolutionService *convertResolutionService,
    QWidget *parent
  )
    : DimensionalQuantityEdit(AbstractModel::Defs::g_lengthUnitSymbols,
                              AbstractModel::Defs::LENGTH_UNIT_MAX,
                              parent
                             ),
      m_convertLengthService(convertLengthService),
      m_convertResolutionService(convertResolutionService),
      m_currentUnit(AbstractModel::Defs::LENGTH_UNIT_PIXEL),
      m_currentResolutionUnit(AbstractModel::Defs::RESOLUTION_UNIT_PPI)
  {
  }

  LengthQuantityEdit::LengthQuantityEdit(QWidget *parent)
    : DimensionalQuantityEdit(AbstractModel::Defs::g_lengthUnitSymbols,
                              AbstractModel::Defs::LENGTH_UNIT_MAX,
                              parent
                             ),
      m_convertLengthService(nullptr),
      m_convertResolutionService(nullptr),
      m_currentUnit(AbstractModel::Defs::LENGTH_UNIT_PIXEL),
      m_currentResolutionUnit(AbstractModel::Defs::RESOLUTION_UNIT_PPI)
  {
  }

  void
  LengthQuantityEdit::setConversionServices(
    AbstractModel::Metrics::IConvertLengthService *convertLengthService,
    AbstractModel::Metrics::IConvertResolutionService *convertResolutionService
  ) {
    m_convertLengthService = convertLengthService;
    m_convertResolutionService = convertResolutionService;

    if((m_convertLengthService != nullptr) && (m_convertResolutionService != nullptr)) {
      // defaults we could not specify elsewhere
      m_convertibleResolution = m_convertResolutionService->createConvertibleResolution(300.0f,
        AbstractModel::Defs::RESOLUTION_UNIT_PPI);
      m_convertibleMinLimit = m_convertLengthService->createConvertibleLength(1.0f,
        AbstractModel::Defs::LENGTH_UNIT_PIXEL, m_convertibleResolution.get());
      m_convertibleMaxLimit = m_convertLengthService->createConvertibleLength(1000.0f,
        AbstractModel::Defs::LENGTH_UNIT_PIXEL, m_convertibleResolution.get());
      m_convertibleQuantity = m_convertLengthService->createConvertibleLength(120.0f,
        AbstractModel::Defs::LENGTH_UNIT_PIXEL, m_convertibleResolution.get());

      notifyModelConnected();
    }
  }

  std::pair<float, AbstractModel::Defs::LengthUnit>
  LengthQuantityEdit::minLimit() const {
    if(m_convertibleMinLimit) {
      return std::make_pair(m_convertibleMinLimit->in(m_currentUnit), m_currentUnit);
    } else {
      return std::make_pair(0.0f, m_currentUnit);
    }
  }

  std::pair<float, AbstractModel::Defs::LengthUnit>
  LengthQuantityEdit::maxLimit() const {
    if(m_convertibleMaxLimit) {
      return std::make_pair(m_convertibleMaxLimit->in(m_currentUnit), m_currentUnit);
    } else {
      return std::make_pair(0.0f, m_currentUnit);
    }
  }

  float
  LengthQuantityEdit::quantity() const {
    if(m_convertibleQuantity) {
      return m_convertibleQuantity->in(m_currentUnit);
    } else {
      return 0.0f;
    }
  }

  AbstractModel::Defs::LengthUnit
  LengthQuantityEdit::unit() const {
    return m_currentUnit;
  }

  void
  LengthQuantityEdit::setMinLimit(float minLimit, AbstractModel::Defs::LengthUnit unit) {
    if(m_convertLengthService != nullptr) {
      m_convertibleMinLimit = m_convertLengthService->createConvertibleLength(minLimit, unit,
        m_convertibleResolution.get());
      setDisplayValidatorMinLimit(m_convertibleMinLimit->in(m_currentUnit));
    }
  }

  void
  LengthQuantityEdit::setMaxLimit(float maxLimit, AbstractModel::Defs::LengthUnit unit) {
    if(m_convertLengthService != nullptr) {
      m_convertibleMaxLimit = m_convertLengthService->createConvertibleLength(maxLimit, unit,
        m_convertibleResolution.get());
      setDisplayValidatorMaxLimit(m_convertibleMaxLimit->in(m_currentUnit));
    }
  }

  void
  LengthQuantityEdit::setQuantity(float quantity) {
    if(m_convertLengthService != nullptr) {
      m_convertibleQuantity = m_convertLengthService->createConvertibleLength(quantity,
        m_currentUnit, m_convertibleResolution.get());
      setDisplayQuantity(m_convertibleQuantity->in(m_currentUnit));
      quantityChanged(quantity);
    }
  }

  void
  LengthQuantityEdit::setUnit(AbstractModel::Defs::LengthUnit unit) {
    m_currentUnit = unit;
    setDisplayValidatorMinLimit(m_convertibleMinLimit->in(m_currentUnit));
    setDisplayValidatorMaxLimit(m_convertibleMaxLimit->in(m_currentUnit));
    setDisplayQuantity(m_convertibleQuantity->in(m_currentUnit));
    setDisplayUnit(unit);
    unitChanged(unit);
  }

  void
  LengthQuantityEdit::setReferenceResolution(float resolution) {
    if(m_convertResolutionService != nullptr) {
      m_convertibleResolution = m_convertResolutionService->createConvertibleResolution(resolution,
        m_currentResolutionUnit);

      float minLimit = m_convertibleMinLimit->in(m_currentUnit);
      float maxLimit = m_convertibleMaxLimit->in(m_currentUnit);
      float quantity = m_convertibleQuantity->in(m_currentUnit);

      m_convertibleMinLimit = m_convertLengthService->createConvertibleLength(minLimit,
        m_currentUnit, m_convertibleResolution.get());
      m_convertibleMaxLimit = m_convertLengthService->createConvertibleLength(maxLimit,
        m_currentUnit, m_convertibleResolution.get());
      m_convertibleQuantity = m_convertLengthService->createConvertibleLength(quantity,
        m_currentUnit, m_convertibleResolution.get());

      setDisplayValidatorMinLimit(m_convertibleMinLimit->in(m_currentUnit));
      setDisplayValidatorMaxLimit(m_convertibleMaxLimit->in(m_currentUnit));
      //setDisplayQuantity(m_convertibleQuantity->in(m_currentUnit));
    }
  }

  void
  LengthQuantityEdit::setReferenceResolutionUnit(AbstractModel::Defs::ResolutionUnit unit) {
    m_currentResolutionUnit = unit;
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets {
  // Protected members.
  void
  LengthQuantityEdit::handleQuantityChangedByUser(float quantity) {
    if(m_convertLengthService != nullptr) {
      m_convertibleQuantity =
        m_convertLengthService->createConvertibleLength(quantity, m_currentUnit,
          m_convertibleResolution.get());

      quantityChanged(quantity);
      quantityChangedByUser(quantity);
    }
  }

  void
  LengthQuantityEdit::handleUnitChangedByUser(AbstractModel::Defs::LengthUnit unit) {
    setUnit(unit);
    unitChanged(unit);
    unitChangedByUser(unit);
  }
}
