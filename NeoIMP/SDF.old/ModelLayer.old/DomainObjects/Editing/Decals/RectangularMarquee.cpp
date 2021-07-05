/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RectangularMarquee.cpp
 * PURPOSE: Implements the RectangularMarquee class.
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

#include "RectangularMarquee.hpp"

namespace SDF::ModelLayer::DomainObjects::Editing::Decals {
  RectangularMarquee::RectangularMarquee(Math::Rect<std::size_t> rect)
    : m_rect(rect)
  {
  }

  Services::AbstractDomain::Defs::DecalType
  RectangularMarquee::getType() const {
    return Services::AbstractDomain::Defs::DECAL_SELECTION;
  }

  Math::Rect<std::size_t>
  RectangularMarquee::getRect() const {
    return m_rect;
  }

  std::list<Math::Coord<std::size_t>>
  RectangularMarquee::getVertices() const {
    std::list<Math::Coord<std::size_t>> vertices;

    // output the verts in counterclockwise order
    vertices.push_back(m_rect.getUpperLeft());
    vertices.push_back(m_rect.getLowerLeft());
    vertices.push_back(m_rect.getLowerRight());
    vertices.push_back(m_rect.getUpperRight());

    return vertices;
  }

  std::list<Math::Coord<std::size_t>>
  RectangularMarquee::getContour() const {
    // Trace the rectangle to pixels.
    std::list<Math::Coord<std::size_t>> contour;

    // Left edge
    for(std::size_t y(m_rect.getUpperLeft().getY()); y < m_rect.getLowerLeft().getY(); ++y) {
      contour.push_back(Math::Coord<std::size_t>(m_rect.getUpperLeft().getX(), y));
    }

    // Bottom edge
    for(std::size_t x(m_rect.getLowerLeft().getX()); x < m_rect.getLowerRight().getX(); ++x) {
      contour.push_back(Math::Coord<std::size_t>(x, m_rect.getLowerLeft().getY()));
    }

    // Right edge
    for(std::size_t y(m_rect.getLowerRight().getY()); y > m_rect.getUpperRight().getY(); --y) {
      contour.push_back(Math::Coord<std::size_t>(m_rect.getLowerRight().getX(), y));
    }

    // Top edge
    for(std::size_t x(m_rect.getUpperRight().getX()); x > m_rect.getUpperLeft().getX(); --x) {
      contour.push_back(Math::Coord<std::size_t>(x, m_rect.getLowerLeft().getY()));
    }

    return contour;
  }
}
