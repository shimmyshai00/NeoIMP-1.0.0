/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionConvertible.cpp
 * PURPOSE: Implements the ResolutionConvertible class.
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

#include "ResolutionConvertible.hpp"

#include "Exceptions.hpp"

#include "ResolutionConversions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
  ResolutionConvertible::ResolutionConvertible(
    float a_quantity,
    UILayer::AbstractModel::Defs::ResolutionUnit a_unit
  )
    : m_quantity(a_quantity),
      m_unit(a_unit)
  {
  }

  float
  ResolutionConvertible::in(UILayer::AbstractModel::Defs::ResolutionUnit a_unit) {
    if(a_unit >= UILayer::AbstractModel::Defs::RESOLUTION_UNIT_MAX) {
      throw InvalidLengthUnitException(a_unit);
    }

    return (m_quantity * g_resolutionUnitSizes[m_unit]) / g_resolutionUnitSizes[a_unit];
  }
}
