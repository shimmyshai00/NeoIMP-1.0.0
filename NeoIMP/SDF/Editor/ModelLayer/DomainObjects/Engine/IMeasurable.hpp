#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMEASURABLE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMEASURABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMeasurable.hpp
 * PURPOSE: Defines the IMeasurable interface.
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

#include "Dimensions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Class:      IMeasurable
  // Purpose:    Provides an interface for objects that have measurable physical dimensions.
  // Parameters: None.
  class IMeasurable {
  public:
    virtual ~IMeasurable() = default;

    // Function:   getWidthPx
    // Purpose:    Gets the width of the measurable in pixels.
    // Parameters: None.
    // Returns:    The width of the object in pixels.
    virtual ImageMeasure
    getWidthPx() const = 0;

    // Function:   getHeightPx
    // Purpose:    Gets the height of the measurable in pixels.
    // Parameters: None.
    // Returns:    The height of the object in pixels.
    virtual ImageMeasure
    getHeightPx() const = 0;

    // Function:   getDimensionsRect
    // Purpose:    Gets the dimensions of the object as a rectangle.
    // Parameters: None.
    // Returns:    The dimensions bounding rectangle.
    virtual ImageRect
    getDimensionsRect() const = 0;
  };
}

#endif
