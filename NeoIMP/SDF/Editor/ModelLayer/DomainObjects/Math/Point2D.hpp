#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_POINT2D_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_POINT2D_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Point2D.hpp
 * PURPOSE: Definition of a type holding a pair of 2D coordinates, representing a point or location
 *          in 2D space.
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

#include "Vec2D.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Math {
  template<class T>
  class Point2D {
  public:
    Point2D()
      : m_x(0),
        m_y(0)
    {}

    Point2D(T a_x, T a_y)
      : m_x(a_x),
        m_y(a_y)
    {}

    template<class U>
    Point2D(Point2D<U> a_otherPoint)
      : m_x(a_otherPoint.x()),
        m_y(a_otherPoint.y())
    {}

    ~Point2D() {}

    // Element access.
    T &
    x() {
      return m_x;
    }

    T &
    y() {
      return m_y;
    }

    const T &
    x() const {
      return m_x;
    }

    const T &
    y() const {
      return m_y;
    }

    // Affine operators.
    Point2D<T> &
    operator+=(const Vec2D<T> &a_rhs) {
      m_x += a_rhs.x();
      m_y += a_rhs.y();
      return *this;
    }

    Point2D<T> &
    operator-=(const Vec2D<T> &a_rhs) {
      m_x -= a_rhs.x();
      m_y -= a_rhs.y();
      return *this;
    }
  private:
    T m_x;
    T m_y;
  };

  // Non-member operators.
  template<class T>
  static inline bool
  operator==(const Point2D<T> &a_lhs, const Point2D<T> &a_rhs) {
    return (a_lhs.x() == a_rhs.x()) && (a_lhs.y() == a_rhs.y());
  }

  template<class T>
  static inline bool
  operator!=(const Point2D<T> &a_lhs, const Point2D<T> &a_rhs) {
    return !(a_lhs == a_rhs);
  }

  template<class T>
  static inline Point2D<T>
  operator+(const Point2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
    return Point2D<T>(a_lhs) += a_rhs;
  }

  template<class T>
  static inline Point2D<T>
  operator-(const Point2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
    return Point2D<T>(a_lhs) -= a_rhs;
  }

  template<class T>
  static inline Vec2D<T>
  operator-(const Point2D<T> &a_lhs, const Point2D<T> &a_rhs) {
    return Vec2D<T>(a_lhs.x() - a_rhs.x(), a_lhs.y() - a_rhs.y());
  }
}

#endif
