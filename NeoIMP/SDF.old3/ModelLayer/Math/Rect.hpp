#ifndef SDF_MODELLAYER_MATH_RECT_HPP
#define SDF_MODELLAYER_MATH_RECT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Rect.hpp
 * PURPOSE: Definition of a type describing a rectangular region.
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

#include <SDF/ModelLayer/Math/Coord.hpp>
#include <SDF/ModelLayer/Math/Vec2D.hpp>

#include <algorithm>

namespace SDF::ModelLayer::Math {
  template<class T>
  class Rect {
  public:
    Rect(T x1,
         T y1,
         T x2,
         T y2
        )
      : m_x1(x1),
        m_y1(y1),
        m_x2(x2),
        m_y2(y2)
    {
      if(m_x1 > m_x2) {
        std::swap(m_x1, m_x2);
      }

      if(m_y1 > m_y2) {
        std::swap(m_y1, m_y2);
      }
    }

    Rect(Coord<T> upperLeft,
         Coord<T> lowerRight
        )
      : Rect(upperLeft.getX(), upperLeft.getY(), lowerRight.getX(), lowerRight.getY())
    {}

    template<class U>
    Rect(Coord<U> upperLeft,
         Coord<U> lowerRight
        )
      : Rect(upperLeft.getX(), upperLeft.getY(), lowerRight.getX(), lowerRight.getY())
    {}

    template<class U>
    Rect(Rect<U> rect)
      : Rect(rect.getX1(), rect.getY1(), rect.getX2(), rect.getY2())
    {}

    ~Rect() {}

    // Size access.
    T
    getWidth() const {
      return (m_x2 - m_x1) + 1;
    }

    T
    getHeight() const {
      return (m_y2 - m_y1) + 1;
    }

    // Element access.
    T
    getX1() const {
      return m_x1;
    }

    T
    getY1() const {
      return m_y1;
    }

    T
    getX2() const {
      return m_x2;
    }

    T
    getY2() const {
      return m_y2;
    }

    Coord<T>
    getUpperLeft() const {
      return Coord<T>(m_x1, m_y1);
    }

    Coord<T>
    getUpperRight() const {
      return Coord<T>(m_x2, m_y1);
    }

    Coord<T>
    getLowerLeft() const {
      return Coord<T>(m_x1, m_y2);
    }

    Coord<T>
    getLowerRight() const {
      return Coord<T>(m_x2, m_y2);
    }

    Rect<T>
    intersect(Rect<T> rhs) const {
      return Rect<T>(Coord<T>(std::max(m_x1, rhs.m_x1), std::max(m_y1, rhs.m_y1)),
                     Coord<T>(std::min(m_x2, rhs.m_x2), std::min(m_y2, rhs.m_y2))
                   );
    }

    // Affine operators.
    Coord<T> &
    operator+=(const Vec2D<T> &rhs) {
      m_x1 += rhs.getX();
      m_y1 += rhs.getY();
      m_x2 += rhs.getX();
      m_y2 += rhs.getY();
    }

    Coord<T> &
    operator-=(const Vec2D<T> &rhs) {
      m_x1 -= rhs.getX();
      m_y1 -= rhs.getY();
      m_x2 += rhs.getX();
      m_y2 += rhs.getY();
    }
  private:
    T m_x1;
    T m_y1;
    T m_x2;
    T m_y2;
  };

  // Non-member operators.
  template<class T>
  static inline bool
  operator==(const Rect<T> &lhs,
             const Rect<T> &rhs
            )
  {
    return ((lhs.getUpperLeft() == rhs.getUpperLeft()) &&
      (lhs.getLowerRight() == rhs.getLowerRight()));
  }

  template<class T>
  static inline bool
  operator!=(const Rect<T> &lhs,
             const Rect<T> &rhs
            )
  {
    return !(lhs == rhs);
  }

  template<class T>
  static inline Rect<T>
  operator+(const Rect<T> &lhs,
            const Vec2D<T> &rhs
           )
  {
    return Rect<T>(lhs) += rhs;
  }

  template<class T>
  static inline Rect<T>
  operator-(const Rect<T> &lhs,
            const Vec2D<T> &rhs
           )
  {
    return Rect<T>(lhs) -= rhs;
  }
}

#endif
