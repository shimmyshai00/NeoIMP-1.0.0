#ifndef SDF_LAYERS_UILAYER_METRICS_CONVERSIONFACTORS_HPP
#define SDF_LAYERS_UILAYER_METRICS_CONVERSIONFACTORS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ConversionFactors.hpp
 * PURPOSE: Definition of conversion factors between the various units.
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

#include <SDF/Layers/UILayer/Metrics/ELengthUnit.hpp>
#include <SDF/Layers/UILayer/Metrics/EResolutionUnit.hpp>

namespace SDF::Layers::UILayer::Metrics {
  // Length unit conversion factors. All factors are given in units per 100 inches.
  static float g_lengthConversionFactors[MAX_LENGTH_UNIT] = {
    0.0f,
    7200.0f,
    2540.0f,
    1200.0f,
    254.0f,
    100.0f
  };

  // Resolution unit conversion factors. All factors are given in ppi per 100 units.
  static float g_resolutionConversionFactors[MAX_RESOLUTION_UNIT] = {
    100.0f,
    254.0f,
    2540.0f
  };
}

#endif
