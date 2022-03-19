#ifndef SDF_UILAYER_GUI_QT_VIEW_RESOLUTIONSELECTOR_HPP
#define SDF_UILAYER_GUI_QT_VIEW_RESOLUTIONSELECTOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionSelector.hpp
 * PURPOSE: Defines the ResolutionSelector class.
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

#include <SDF/UILayer/Metrics/ResolutionQuantity.hpp>
#include <SDF/UILayer/Metrics/ResolutionUnit.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  // Class:      ResolutionSelector
  // Purpose:    Provides logic for selecting a resolution quantity in different units.
  // Parameters: None.
  class ResolutionSelector : public IQuantitySelector<Metrics::ResolutionUnit> {
  public:
    ResolutionSelector(float resolution, Metrics::ResolutionUnit unit);

    float
    getQuantity() const;

    Metrics::ResolutionUnit
    getUnit() const;

    float
    getQuantityIn(Metrics::ResolutionUnit unit) const;

    void
    setQuantity(float quantity);

    void
    setUnit(Metrics::ResolutionUnit unit);
  private:
    Metrics::resolution_quantity m_resolution;
    Metrics::ResolutionUnit m_resolutionUnit;
  };
}

#endif
