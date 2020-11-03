#ifndef SDF_UILAYER_METRICS_UNIT_HPP
#define SDF_UILAYER_METRICS_UNIT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Unit.hpp
 * PURPOSE: A template for defining units of a quantity of some dimension.
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

namespace SDF::UILayer::Metrics {
  template<class D>
  class Unit {
  public:
    Unit(float numBaseUnits) :
    m_numBaseUnits(numBaseUnits) {}

    ~Unit() {}

    // Synthesize a multiplicative conversion factor for this unit and another unit of this same dimensional quantity.
    float getConversionTo(const Unit<D> toUnit) const {
      return(toUnit.m_numBaseUnits / m_numBaseUnits);
    }
  private:
    // The size of this unit as a number of arbitrary base units for this quantity.
    float m_numBaseUnits;
  };

  template<class D>
  class BaseUnit : public Unit<D> {
  public:
    BaseUnit() :
    Unit(1.0f) {}

    ~BaseUnit() {}
  };
}

#endif
