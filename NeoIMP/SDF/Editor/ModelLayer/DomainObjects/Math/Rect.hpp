#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_RECT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_RECT_HPP

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

#include "Point2D.hpp"
#include "Vec2D.hpp"

#include <algorithm>

namespace SDF::Editor::ModelLayer::DomainObjects::Math {
  template<class T>
  class Rect {
  public:
    // Defines a rectangle from (x1, y1) to (x2, y2). Note: similarly to STL iterators, the (x2, y2)
    // point and associated edges are notionally NOT part of the rectangle. That is, rectangles are
    // "half-open" in a sense. This is not so important when the rectangle is approximately real
    // (i.e. floating point coordinates), but is quite important when it is integer coordinates.
    // This also allows empty rectangles to be expressed by taking (x1, y1) == (x2, y2).
    Rect()
      : m_upperLeft(0, 0), // the "standard null rectangle"
        m_lowerRight(0, 0)
    {
    }

    Rect(T a_x1, T a_y1, T a_x2, T a_y2)
      : m_upperLeft(a_x1, a_y1),
        m_lowerRight(a_x2, a_y2)
    {
      if(m_upperLeft.x() > m_lowerRight.x()) {
        std::swap(m_upperLeft.x(), m_lowerRight.x());
      }

      if(m_upperLeft.y() > m_lowerRight.y()) {
        std::swap(m_upperLeft.y(), m_lowerRight.y());
      }
    }

    Rect(Point2D<T> a_upperLeft, Point2D<T> a_lowerRight)
      : m_upperLeft(a_upperLeft),
        m_lowerRight(a_lowerRight)
    {}

    template<class U>
    Rect(Point2D<U> a_upperLeft, Point2D<U> a_lowerRight)
      : m_upperLeft(a_upperLeft),
        m_lowerRight(a_lowerRight)
    {}

    template<class U>
    Rect(Rect<U> a_rect)
      : Rect(a_rect.upperLeft, a_rect.lowerRight)
    {}

    ~Rect() {}

    // Size access.
    T
    getWidth() const {
      return m_lowerRight.x() - m_upperLeft.x();
    }

    T
    getHeight() const {
      return m_lowerRight.y() - m_upperLeft.y();
    }

    // Element access.
    T &
    x1() {
      return m_upperLeft.x();
    }

    T &
    y1() {
      return m_upperLeft.y();
    }

    T &
    x2() {
      return m_lowerRight.x();
    }

    T &
    y2() {
      return m_lowerRight.y();
    }

    const T &
    x1() const {
      return m_upperLeft.x();
    }

    const T &
    y1() const {
      return m_upperLeft.y();
    }

    const T &
    x2() const {
      return m_lowerRight.x();
    }

    const T &
    y2() const {
      return m_lowerRight.y();
    }

    Point2D<T>
    getUpperLeft() const {
      return m_upperLeft;
    }

    Point2D<T>
    getUpperRight() const {
      return Point2D<T>(m_lowerRight.x(), m_upperLeft.y());
    }

    Point2D<T>
    getLowerLeft() const {
      return Point2D<T>(m_upperLeft.x(), m_lowerRight.y());
    }

    Point2D<T>
    getLowerRight() const {
      return m_lowerRight;
    }

    bool
    isInside(Point2D<T> a_point) {
      return ((x1() <= a_point.x()) && (a_point.x() < x2())) &&
             ((y1() <= a_point.x()) && (a_point.x() < y2()));
    }

    bool
    intersectsWith(Rect<T> a_rhs) const {
      return (std::max(x1(), a_rhs.x1()) < std::min(x2(), a_rhs.x2())) &&
             (std::max(y1(), a_rhs.y1()) < std::min(y2(), a_rhs.y2()));
    }

    Rect<T>
    intersect(Rect<T> a_rhs) const {
      if(intersectsWith(a_rhs)) {
        return Rect<T>(Point2D<T>(std::max(x1(), a_rhs.x1()), std::max(y1(), a_rhs.y1())),
                       Point2D<T>(std::min(x2(), a_rhs.x2()), std::min(y2(), a_rhs.y2()))
                      );
      } else {
        return Rect<T>(); // empty intersection
      }
    }

    // Affine operators.
    Point2D<T> &
    operator+=(const Vec2D<T> &a_rhs) {
      m_upperLeft += a_rhs;
      m_lowerRight += a_rhs;
    }

    Point2D<T> &
    operator-=(const Vec2D<T> &a_rhs) {
      m_upperLeft -= a_rhs;
      m_lowerRight -= a_rhs;
    }
  private:
    Point2D<T> m_upperLeft;
    Point2D<T> m_lowerRight;
  };

  // Non-member operators.
  template<class T>
  static inline bool
  operator==(const Rect<T> &a_lhs, const Rect<T> &a_rhs) {
    return ((a_lhs.getUpperLeft() == a_rhs.getUpperLeft()) &&
      (a_lhs.getLowerRight() == a_rhs.getLowerRight()));
  }

  template<class T>
  static inline bool
  operator!=(const Rect<T> &a_lhs, const Rect<T> &a_rhs) {
    return !(a_lhs == a_rhs);
  }

  template<class T>
  static inline Rect<T>
  operator+(const Rect<T> &a_lhs, const Vec2D<T> &a_rhs) {
    return Rect<T>(a_lhs) += a_rhs;
  }

  template<class T>
  static inline Rect<T>
  operator-(const Rect<T> &a_lhs, const Vec2D<T> &a_rhs) {
    return Rect<T>(a_lhs) -= a_rhs;
  }
}

#endif
