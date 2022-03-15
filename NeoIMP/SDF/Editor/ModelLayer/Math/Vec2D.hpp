#ifndef SDF_EDITOR_MODELLAYER_MATH_VEC2D_HPP
#define SDF_EDITOR_MODELLAYER_MATH_VEC2D_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Vec2D.hpp
 * PURPOSE: Definition of a type representing a 2D vector. Note that, in line with mathematical
 *          principles, vectors are not the same as coordinates, and do not support the same
 *          operations.
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

namespace SDF::Editor::ModelLayer::Math {
  template<class T>
  class Vec2D {
  public:
    Vec2D(T x,
          T y
         )
      : m_x(x),
        m_y(y)
    {}

    ~Vec2D() {}

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

    // Vector operations.
    Vec2D<T> &
    operator+=(const Vec2D<T> &rhs) {
      m_x += rhs.m_x;
      m_y += rhs.m_y;

      return *this;
    }

    Vec2D<T> &
    operator-=(const Vec2D<T> &rhs) {
      m_x -= rhs.m_x;
      m_y -= rhs.m_y;

      return *this;
    }

    Vec2D<T> &
    operator*=(T s) {
      m_x *= s;
      m_y *= s;

      return *this;
    }
  private:
    T m_x;
    T m_y;
  };

  // Non-member operators.
  template<class T>
  static inline bool
  operator==(const Vec2D<T> &lhs,
             const Vec2D<T> &rhs
            )
  {
    return (lhs.x() == rhs.x()) && (lhs.y() == rhs.y());
  }

  template<class T>
  static inline bool
  operator!=(const Vec2D<T> &lhs,
             const Vec2D<T> &rhs
            )
  {
    return !(lhs == rhs);
  }

  template<class T>
  static inline Vec2D<T>
  operator+(const Vec2D<T> &lhs,
            const Vec2D<T> &rhs
           )
  {
    return Vec2D<T>(lhs) += rhs;
  }

  template<class T>
  static inline Vec2D<T>
  operator-(const Vec2D<T> &lhs,
            const Vec2D<T> &rhs
           )
  {
    return Vec2D<T>(lhs) -= rhs;
  }

  template<class T>
  static inline Vec2D<T>
  operator-(const Vec2D<T> &rhs) {
    return Vec2D<T>(-rhs.x(), -rhs.y());
  }

  template<class T>
  static inline Vec2D<T>
  operator*(double s,
            const Vec2D<T> &rhs
           )
  {
    return Vec2D<T>(rhs) *= s;
  }
}

#endif
