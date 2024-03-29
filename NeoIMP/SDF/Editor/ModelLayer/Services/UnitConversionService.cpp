/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitConversionService.cpp
 * PURPOSE: Implements the UnitConversionService class.
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

#include "UnitConversionService.hpp"

#include "../DomainObjects/Metrics/LengthConvertible.hpp"
#include "../DomainObjects/Metrics/ResolutionConvertible.hpp"

namespace SDF::Editor::ModelLayer::Services {
  UnitConversionService::UnitConversionService() {
  }

  std::shared_ptr<
    UILayer::AbstractModel::Defs::IUnitConvertible<UILayer::AbstractModel::Defs::LengthUnit>
  >
  UnitConversionService::createConvertibleLength(
    float a_length,
    UILayer::AbstractModel::Defs::LengthUnit a_lengthUnit,
    UILayer::AbstractModel::Defs::IUnitConvertible<UILayer::AbstractModel::Defs::ResolutionUnit> *
      a_resolution
  ) {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects::Metrics;

    return std::make_shared<LengthConvertible>(a_length, a_lengthUnit,
      a_resolution->in(RESOLUTION_UNIT_PPI), RESOLUTION_UNIT_PPI);
  }

  std::shared_ptr<
    UILayer::AbstractModel::Defs::IUnitConvertible<UILayer::AbstractModel::Defs::ResolutionUnit>
  >
  UnitConversionService::createConvertibleResolution(
    float a_resolution,
    UILayer::AbstractModel::Defs::ResolutionUnit a_resolutionUnit
  ) {
    using namespace UILayer::AbstractModel;
    using namespace DomainObjects::Metrics;

    return std::make_shared<ResolutionConvertible>(a_resolution, a_resolutionUnit);
  }
}
