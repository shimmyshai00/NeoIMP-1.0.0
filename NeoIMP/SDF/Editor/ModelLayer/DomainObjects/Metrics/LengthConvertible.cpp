/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthConvertible.cpp
 * PURPOSE: Implements the LengthConvertible class.
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

#include "LengthConvertible.hpp"

#include "Exceptions.hpp"

#include "LengthConversions.hpp"
#include "ResolutionConversions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
  LengthConvertible::LengthConvertible(
    float a_quantity,
    UILayer::AbstractModel::Defs::LengthUnit a_unit,
    float a_resolution,
    UILayer::AbstractModel::Defs::ResolutionUnit a_resUnit
  )
    : m_quantityPixels(a_quantity),
      m_resolutionPpi(a_resolution * g_resolutionUnitSizes[a_resUnit])
  {
    using namespace UILayer::AbstractModel;
    if(a_unit >= Defs::LENGTH_UNIT_MAX) {
      throw InvalidLengthUnitException(a_unit);
    }

    if(a_resUnit >= Defs::RESOLUTION_UNIT_MAX) {
      throw InvalidResolutionUnitException(a_resUnit);
    }

    if(a_unit != Defs::LENGTH_UNIT_PIXEL) {
      m_quantityPixels = a_quantity * g_lengthUnitSizes[a_unit] * m_resolutionPpi;
    }
  }

  float
  LengthConvertible::in(UILayer::AbstractModel::Defs::LengthUnit a_unit) {
    using namespace UILayer::AbstractModel;
    if(a_unit >= Defs::LENGTH_UNIT_MAX) {
      throw InvalidLengthUnitException(a_unit);
    }

    if(a_unit == Defs::LENGTH_UNIT_PIXEL) {
      return m_quantityPixels;
    } else {
      return (m_quantityPixels / m_resolutionPpi) / g_lengthUnitSizes[a_unit];
    }
  }
}
