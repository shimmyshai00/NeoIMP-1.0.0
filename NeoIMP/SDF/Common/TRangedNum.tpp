/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRangedNum.tpp
 * PURPOSE: Implementation of the TRangedNum template.
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

#include <TRangedNum.hpp>
#include <cassert>

namespace SDF::Common {
  template<class T, T lowerBound, T upperBound>
  TRangedNum<T, lowerBound, upperBound>::TRangedNum(T initialValue)
  : m_storedValue(std::clamp(initialValue, lowerBound, upperBound)) {

  }

  template<class T, T lowerBound, T upperBound>
  void TRangedNum<T, lowerBound, upperBound>::setValue(T newValue) {
    m_storedValue = std::clamp(newValue, lowerBound, upperBound);
  }

  template<class T, T lowerBound, T upperBound>
  T TRangedNum<T, lowerBound, upperBound>::getValue() const {
    return m_storedValue;
  }


  template<class T, T lowerBound, T upperBound>
  bool operator==(const TRangedNum<T, lowerBound, upperBound> &lhs, const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return lhs.m_storedValue == rhs.m_storedValue;
  }


  template<class T, T lowerBound, T upperBound>
  bool operator==(const TRangedNum<T, lowerBound, upperBound> &lhs, const T rhs) {
    return lhs.m_storedValue == rhs;
  }


  template<class T, T lowerBound, T upperBound>
  bool operator==(const T lhs, const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return lhs == rhs.m_storedValue;
  }


  template<class T, T lowerBound, T upperBound>
  bool operator!=(const TRangedNum<T, lowerBound, upperBound> &lhs, const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return !(lhs == rhs);
  }


  template<class T, T lowerBound, T upperBound>
  bool operator!=(const TRangedNum<T, lowerBound, upperBound> &lhs, const T rhs) {
    return !(lhs == rhs);
  }

  template<class T, T lowerBound, T upperBound>
  bool operator!=(const T lhs, const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return !(lhs == rhs);
  }

  template<class T, T lowerBound, T upperBound>
  TRangedNum<T, lowerBound, upperBound> &operator+=(const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return (*this) += rhs.m_storedValue;
  }

  template<class T, T lowerBound, T upperBound>
  TRangedNum<T, lowerBound, upperBound> &operator+=(T rhs) {
    // Overflow-safe addition.
    if((rhs > 0) && (upperBound - m_storedValue < rhs)) { // distance from stored to upper bound
      m_storedValue = upperBound;
    } else {
      // for negative values
      if((rhs < 0) && (m_storedValue - lowerBound < -rhs)) { // distance from stored to lower bound
        m_storedValue = lowerBound;
      } else {
        m_storedValue += rhs;
      }
    }
  }

  template<class T, T lowerBound, T upperBound>
  TRangedNum<T, lowerBound, upperBound> &operator-=(const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return (*this) -= rhs.m_storedValue;
  }

  template<class T, T lowerBound, T upperBound>
  TRangedNum<T, lowerBound, upperBound> &operator-=(T rhs) {
    // Overflow-safe subtraction.
    if((rhs > 0) && (m_storedValue - lowerBound < rhs)) { // distance from stored to lower bound
      m_storedValue = lowerBound;
    } else {
      // for negative values
      if((rhs < 0) && (upperBound - m_storedValue < -rhs)) { // distance from stored to upper bound
        m_storedValue = upperBound;
      } else {
        m_storedValue -= rhs;
      }
    }
  }

  template<class T, T lowerBound, T upperBound>
  friend TRangedNum<T, lowerBound, upperBound> operator+(const TRangedNum<T, lowerBound, upperBound> &lhs,
    const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return TRangedNum<T, lowerBound, upperBound>(lhs) += rhs;
  }

  template<class T, T lowerBound, T upperBound>
  friend TRangedNum<T, lowerBound, upperBound> operator+(const TRangedNum<T, lowerBound, upperBound> &lhs,
    const T rhs) {
    return TRangedNum<T, lowerBound, upperBound>(lhs) += rhs;
  }

  template<class T, T lowerBound, T upperBound>
  friend TRangedNum<T, lowerBound, upperBound> operator+(const T lhs,
    const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return TRangedNum<T, lowerBound, upperBound>(lhs) += rhs;
  }

  template<class T, T lowerBound, T upperBound>
  friend TRangedNum<T, lowerBound, upperBound> operator-(const TRangedNum<T, lowerBound, upperBound> &lhs,
    const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return TRangedNum<T, lowerBound, upperBound>(lhs) += rhs;
  }

  template<class T, T lowerBound, T upperBound>
  friend TRangedNum<T, lowerBound, upperBound> operator-(const TRangedNum<T, lowerBound, upperBound> &lhs,
    const T rhs) {
    return TRangedNum<T, lowerBound, upperBound>(lhs) -= rhs;
  }

  template<class T, T lowerBound, T upperBound>
  friend TRangedNum<T, lowerBound, upperBound> operator-(const T lhs,
    const TRangedNum<T, lowerBound, upperBound> &rhs) {
    return TRangedNum<T, lowerBound, upperBound>(lhs) -= rhs;
  }
}
