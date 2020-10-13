#ifndef SDF_LAYERS_UILAYER_METRICS_ELENGTHUNIT_HPP
#define SDF_LAYERS_UILAYER_METRICS_ELENGTHUNIT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ELengthUnit.hpp
 * PURPOSE: Enumeration of the length units that are used in the UI for displaying the size of an image in physical
 *          units according to its resolution.
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

namespace SDF::Layers::UILayer::Metrics {
  enum ELengthUnit {
    UNIT_PIXEL,
    UNIT_POINT,
    UNIT_MILLIMETER,
    UNIT_PICA,
    UNIT_CENTIMETER,
    UNIT_INCH,
    MAX_LENGTH_UNIT
  };
}

#endif
