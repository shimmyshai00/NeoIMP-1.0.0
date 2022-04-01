#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IRENDERREGION_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IRENDERREGION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRenderRegion.hpp
 * PURPOSE: Defines the IRenderRegion interface.
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

#include <cstddef>
#include <functional>

namespace SDF::Editor::UILayer::AbstractModel::Defs {
  // Class:      IRenderRegion
  // Purpose:    Defines an interface for references into rendering data as tiled regions.
  // Parameters: None.
  class IRenderRegion {
  public:
    struct TileElement {
      std::size_t xOrigin, yOrigin;
      std::size_t width, height;

      unsigned char *originPtr;
      std::ptrdiff_t rowStride;
    };
  public:
    virtual ~IRenderRegion() = default;

    // Function:   getRegionX1
    // Purpose:    Gets the upper-left X coordinate of the region rectangle.
    // Parameters: None.
    // Returns:    The upper-left X coordinate of the rectangle.
    virtual std::size_t
    getRegionX1() const = 0;

    // Function:   getRegionY1
    // Purpose:    Gets the upper-left Y coordinate of the region rectangle.
    // Parameters: None.
    // Returns:    The upper-left Y coordinate of the rectangle.
    virtual std::size_t
    getRegionY1() const = 0;

    // Function:   getRegionX2
    // Purpose:    Gets the lower-right X coordinate of the region rectangle.
    // Parameters: None.
    // Returns:    The lower-right X coordinate of the rectangle.
    virtual std::size_t
    getRegionX2() const = 0;

    // Function:   getRegionY2
    // Purpose:    Gets the lower-right Y coordinate of the region rectangle.
    // Parameters: None.
    // Returns:    The lower-right Y coordinate of the rectangle.
    virtual std::size_t
    getRegionY2() const = 0;

    // Function:   getElementContaining
    // Purpose:    Gets the tile element containing a given point.
    // Parameters: x, y - The coordinates of the point.
    // Returns:    The containing tile element.
    virtual TileElement
    getElementContaining(std::size_t a_x, std::size_t a_y) = 0;

    // Function:   traverse
    // Purpose:    Traverses each tile element making up the region in turn, performing an
    //             operation on them.
    // Parameters: op - The function to apply to each tile.
    // Returns:    None.
    virtual void
    traverse(std::function<void (TileElement el)> a_op) = 0;
  };
}

#endif
