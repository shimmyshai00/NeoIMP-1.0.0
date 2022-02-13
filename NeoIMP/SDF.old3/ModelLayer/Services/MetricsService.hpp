#ifndef SDF_MODELLAYER_SERVICES_METRICSSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_METRICSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MetricsService.hpp
 * PURPOSE: Defines the MetricsService class.
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

#include "../../UILayer/AbstractModel/Defs/ELengthUnit.hpp"
#include "../../UILayer/AbstractModel/Defs/EResolutionUnit.hpp"
#include "../../UILayer/AbstractModel/Defs/IUnitConvertible.hpp"
#include "../../UILayer/AbstractModel/IMetricsService.hpp"

#include <fruit/fruit.h>
#include <memory>

namespace SDF::ModelLayer::Services {
  // Class:      MetricsService
  // Purpose:    Implements the IMetricsService interface.
  // Parameters: None.
  class MetricsService : public UILayer::AbstractModel::IMetricsService {
  public:
    INJECT(MetricsService());

    std::shared_ptr<
      UILayer::AbstractModel::Defs::IUnitConvertible<UILayer::AbstractModel::Defs::ELengthUnit>
    >
    createConvertibleLength(float length,
                            UILayer::AbstractModel::Defs::ELengthUnit lengthUnit,
                            UILayer::AbstractModel::Defs::IUnitConvertible<
                              UILayer::AbstractModel::Defs::EResolutionUnit
                            > *resolution
                           );

    std::shared_ptr<
      UILayer::AbstractModel::Defs::IUnitConvertible<UILayer::AbstractModel::Defs::EResolutionUnit>
    >
    createConvertibleResolution(float resolution,
                                UILayer::AbstractModel::Defs::EResolutionUnit resolutionUnit
                               );
  };
}

#endif
