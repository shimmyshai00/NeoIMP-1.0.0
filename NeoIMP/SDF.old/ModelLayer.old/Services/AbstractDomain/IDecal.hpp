#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IDECAL_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IDECAL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDecal.hpp
 * PURPOSE: Defines the IDecal interface.
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

#include <SDF/ModelLayer/Services/AbstractDomain/Defs/DecalType.hpp>

#include <SDF/ModelLayer/Math/Coord.hpp>
#include <SDF/ModelLayer/Math/Rect.hpp>

#include <cstddef>
#include <list>

namespace SDF::ModelLayer::Services::AbstractDomain {
  // Class:      IDecal
  // Purpose:    Defines an interface for image decals (i.e. items like a selection box to perform copy/paste
  //             operations.)
  // Parameters: None.
  class IDecal {
  public:
    virtual ~IDecal() = default;

    // Function:   getType
    // Purpose:    Get the type of this decal.
    // Parameters: None.
    // Returns:    The decal type.
    virtual Defs::DecalType
    getType() const = 0;

    // Function:   getRect
    // Purpose:    Get the bounding rectangle of this decal.
    // Parameters: None.
    // Returns:    The bounding rectangle for the decal.
    virtual Math::Rect<std::size_t>
    getRect() const = 0;

    // Function:   getVertices
    // Purpose:    Obtain the vertices of the polygon defining the decal.
    // Parameters: None.
    // Returns:    The list of vertices.
    virtual std::list<Math::Coord<std::size_t>>
    getVertices() const = 0;

    // Function:   getContour
    // Purpose:    Gets the contour, i.e. the pixels on the edge of the region bounded by the decal, of the decal.
    // Parameters: None.
    // Returns:    The contour as a list of points.
    virtual std::list<Math::Coord<std::size_t>>
    getContour() const = 0;
  };
}

#endif
