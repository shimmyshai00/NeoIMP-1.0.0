#ifndef SDF_UILAYER_GUI_VIEW_IQUANTITYSELECTOR_HPP
#define SDF_UILAYER_GUI_VIEW_IQUANTITYSELECTOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IQuantitySelector.hpp
 * PURPOSE: Defines the IQuantitySelector class.
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

namespace SDF::UILayer::Gui::Qt::View {
  // Class:      IQuantitySelector
  // Purpose:    Provides an interface for selectors for different kinds of unitful quantities.
  // Parameters: UnitEnumT - the enumeration of quantity units.
  template<class UnitEnumT>
  class IQuantitySelector {
  public:
    virtual ~IQuantitySelector() = default;

    // Function:   getQuantity
    // Purpose:    Get the value of the quantity in the currently-selected units.
    // Parameters: None.
    // Returns:    The quantity in the currently-selected units.
    virtual float
    getQuantity() const = 0;

    // Function:   getUnit
    // Purpose:    Get the unit used for reporting and setting the quantity.
    // Parameters: None.
    // Returns:    The unit selected for reporting and setting the quantity's value.
    virtual UnitEnumT
    getUnit() const = 0;

    // Function:   getQuantityIn
    // Purpose:    Get this resolution quantity in a different unit.
    // Parameters: unit - The unit to get in.
    // Returns:    The quantity in the indicated unit.
    virtual float
    getQuantityIn(UnitEnumT unit) const = 0;

    // Function:   setQuantity
    // Purpose:    Set the value of the quantity in the currently-selected units.
    // Parameters: quantity - The new quantity value to set.
    // Returns:    None.
    virtual void
    setQuantity(float quantity) = 0;

    // Function:   setUnit
    // Purpose:    Set the units used for reporting and setting the quantity.
    // Parameters: unit - The new unit to use.
    // Returns:    None.
    virtual void
    setUnit(UnitEnumT unit) = 0;
  };
}

#endif
