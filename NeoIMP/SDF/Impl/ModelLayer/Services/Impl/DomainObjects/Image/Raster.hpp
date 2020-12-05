#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_RASTER_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_RASTER_HPP

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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Math/Coord.hpp>
#include <cassert>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image {
  template<class T>
  class Raster {
  public:
    Raster(int width, int height) : m_width(width), m_height(height), m_data(new T[m_width*m_height]) {}

    ~Raster() {
      delete[] m_data;
    }

    Raster(const Raster<T> &obj) : m_width(obj.m_width), m_height(obj.m_height), m_data(new T[m_width*m_height]) {
      for(int i(0); i < m_width*m_height; ++i) {
        m_data[i] = obj.m_data[i];
      }
    }

    Raster(Raster<T> &&obj) :
    m_width(std::exchange(obj.m_width, 0)),
    m_height(std::exchange(obj.m_height, 0)),
    m_data(std::exchange(obj.m_data, nullptr)) {}

    Raster<T> &operator=(const Raster<T> &rhs) {
      return *this = Raster<T>(rhs);
    }

    Raster<T> &operator=(Raster<T> &&rhs) noexcept {
      std::swap(m_width, rhs.m_width);
      std::swap(m_height, rhs.m_height);
      std::swap(m_data, rhs.m_data);

      return *this;
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

    T &operator()(Math::Coord<int> pos) {
      return (*this)(pos.getX(), pos.getY());
    }

    T operator()(Math::Coord<int> pos) const {
      return (*this)(pos.getX(), pos.getY());
    }
  private:
    int m_width;
    int m_height;

    T *m_data;
  };
}

#endif
