#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_LENGTHCONVERSIONS_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_LENGTHCONVERSIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthConversions.hpp
 * PURPOSE: Defines a table of conversion factors for the various length units.
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

#include "../../../UILayer/AbstractModel/Defs/ELengthUnit.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
  // Gives the sizes of the various units in inches.
  static const double g_lengthUnitSizes[UILayer::AbstractModel::Defs::LENGTH_UNIT_MAX] = {
    -1.0,         // pixel (no definite conversion factor)
    1.0 / 72.0,   // point (PostScript convention)
    1.0 / 25.4,   // millimeter
    1.0 / 6.0,    // pica
    1.0 / 2.54,   // centimeter
    1.0           // inch
  };
}

#endif
