#ifndef SDF_EDITOR_MODELLAYER_METRICS_LENGTHCONVERTIBLE_HPP
#define SDF_EDITOR_MODELLAYER_METRICS_LENGTHCONVERTIBLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthConvertible.hpp
 * PURPOSE: Defines the LengthConvertible class.
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

#include "../../UILayer/AbstractModel/Defs/IUnitConvertible.hpp"
#include "../../UILayer/AbstractModel/Defs/ELengthUnit.hpp"
#include "../../UILayer/AbstractModel/Defs/EResolutionUnit.hpp"

namespace SDF::Editor::ModelLayer::Metrics {
  // Class:      LengthConvertible
  // Purpose:    Defines a convertible length quantity.
  // Parameters: None.
  class LengthConvertible : public UILayer::AbstractModel::Defs::IUnitConvertible
                              <UILayer::AbstractModel::Defs::ELengthUnit>
  {
  public:
    LengthConvertible(float quantity,
                      UILayer::AbstractModel::Defs::ELengthUnit unit,
                      float resolution,
                      UILayer::AbstractModel::Defs::EResolutionUnit resUnit
                    );

    float
    in(UILayer::AbstractModel::Defs::ELengthUnit unit);
  private:
    float m_quantityPixels;
    float m_resolutionPpi;
  };
}

#endif
