#ifndef SDF_MODELLAYER_DOMAINOBJECTS_VIEWPOINT_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_VIEWPOINT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Viewpoint.hpp
 * PURPOSE: Defines the Viewpoint struct.
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

#include "../../Math/Coord.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  struct Viewpoint {
    Math::Coord<float> m_position;
    float m_magnification;

    Viewpoint()
      : m_position(0.0f, 0.0f),
        m_magnification(1.0f)
    {
    }

    Viewpoint(float x, float y)
      : m_position(x, y),
        m_magnification(1.0f)
    {
    }

    Viewpoint(float x, float y, float mag)
      : m_position(x, y),
        m_magnification(mag)
    {
    }
  };
}

#endif
