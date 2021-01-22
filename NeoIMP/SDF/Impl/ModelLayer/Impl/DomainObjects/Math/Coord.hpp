#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_MATH_COORD_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_MATH_COORD_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Coord.hpp
 * PURPOSE: Definition of a type holding a pair of 2D coordinates, representing a point or location in 2D space.
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Math/Vec2D.hpp>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Math {
  template<class T>
  class Coord {
  public:
    Coord(T x, T y) : m_x(x), m_y(y) {}
    ~Coord() {}

    // Element access.
    T getX() const {
      return m_x;
    }

    T getY() const {
      return m_y;
    }

    // Affine operators.
    Coord<T> &operator+=(const Vec2D<T> &rhs) {
      m_x += rhs.getX();
      m_y += rhs.getY();
      return *this;
    }

    Coord<T> &operator-=(const Vec2D<T> &rhs) {
      m_x -= rhs.getX();
      m_y -= rhs.getY();
      return *this;
    }
  private:
    T m_x;
    T m_y;
  };

  // Non-member operators.
  template<class T>
  static inline bool operator==(const Coord<T> &lhs, const Coord<T> &rhs) {
    return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
  }

  template<class T>
  static inline bool operator!=(const Coord<T> &lhs, const Coord<T> &rhs) {
    return !(lhs == rhs);
  }

  template<class T>
  static inline Coord<T> operator+(const Coord<T> &lhs, const Vec2D<T> &rhs) {
    return Coord<T>(lhs) += rhs;
  }

  template<class T>
  static inline Coord<T> operator-(const Coord<T> &lhs, const Vec2D<T> &rhs) {
    return Coord<T>(lhs) -= rhs;
  }

  template<class T>
  static inline Vec2D<T> operator-(const Coord<T> &lhs, const Coord<T> &rhs) {
    return Vec2D<T>(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY());
  }
}

#endif
