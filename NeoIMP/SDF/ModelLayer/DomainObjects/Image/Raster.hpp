#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_RASTER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_RASTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Raster.hpp
 * PURPOSE: Definition of the image raster template.
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

#include <SDF/ModelLayer/DomainObjects/Image/Coord.hpp>
#include <cassert>

namespace SDF::ModelLayer::DomainObjects::Image {
  template<class T>
  class Raster {
  public:
    Raster(int width, int height) : m_width(width), m_height(height), m_data(new T[m_width*m_height]) {}

    ~Raster() {
      delete[] m_data;
    }

    // Size access.
    int getWidth() const {
      return m_width;
    }

    int getHeight() const {
      return m_height;
    }

    // Element access.
    T &operator()(int x, int y) {
      assert((0 <= x) && (x < m_width));
      assert((0 <= y) && (y < m_height));

      return m_data[y*m_width + x];
    }

    T operator()(int x, int y) const {
      assert((0 <= x) && (x < m_width));
      assert((0 <= y) && (y < m_height));

      return m_data[y*m_width + x];
    }

    T &operator()(Coord<int> pos) {
      return (*this)(pos.getX(), pos.getY());
    }

    T operator()(Coord<int> pos) const {
      return (*this)(pos.getX(), pos.getY());
    }
  private:
    int m_width;
    int m_height;

    T *m_data;
  };
}

#endif
