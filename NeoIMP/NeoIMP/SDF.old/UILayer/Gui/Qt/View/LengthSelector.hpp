#ifndef SDF_UILAYER_GUI_QT_VIEW_LENGTHSELECTOR_HPP
#define SDF_UILAYER_GUI_QT_VIEW_LENGTHSELECTOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthSelector.hpp
 * PURPOSE: Defines the LengthSelector class.
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

#include <SDF/UILayer/Gui/Qt/View/IQuantitySelector.hpp>

#include <SDF/UILayer/Metrics/DimensionlessQuantity.hpp>
#include <SDF/UILayer/Metrics/LengthQuantity.hpp>
#include <SDF/UILayer/Metrics/LengthUnit.hpp>
#include <SDF/UILayer/Metrics/ResolutionQuantity.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  // Class:      LengthSelector
  // Purpose:    Provides logic for selecting a length quantity in different units, including pixels.
  // Parameters: None.
  class LengthSelector : public IQuantitySelector<Metrics::LengthUnit> {
  public:
    LengthSelector(float length, Metrics::LengthUnit unit, float resolutionPpi);

    float
    getQuantity() const;

    Metrics::LengthUnit
    getUnit() const;

    float
    getQuantityIn(Metrics::LengthUnit unit) const;

    // Function:   getResolutionPpi
    // Purpose:    Gets the currently used resolution (pixels-to-length conversion factor), in PPI.
    // Parameters: None.
    // Returns:    The resolution used in PPI.
    float
    getResolutionPpi() const;

    void
    setQuantity(float quantity);

    void
    setUnit(Metrics::LengthUnit unit);

    // Function:   setResolutionPpi
    // Purpose:    Sets the currently used resolution in PPI.
    // Parameters: resolutionPpi - The new resolution to set.
    // Returns:    None.
    void
    setResolutionPpi(float resolutionPpi);
  private:
    Metrics::dimensionless_quantity m_lengthInPixels;
    Metrics::length_quantity m_lengthInPhysUnits;
    Metrics::LengthUnit m_lengthUnit;

    Metrics::resolution_quantity m_resolution;
  };
}

#endif
