#ifndef SDF_COMMON_TRANGEDNUM_HPP
#define SDF_COMMON_TRANGEDNUM_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRangedNum.hpp
 * PURPOSE: Template declaration for a number which lies in a set range and which saturates on overflow (i.e. is
 *          clamped thereto).
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

namespace SDF::Common {
  template<class T, T lowerBound, T upperBound>
  class TRangedNum {
  public:
    TRangedNum(T initialValue);

    void setValue(T newValue);
    T getValue() const;

    // Comparison operators.
    friend bool operator==(const TRangedNum<T, lowerBound, upperBound> &lhs,
      const TRangedNum<T, lowerBound, upperBound> &rhs);
    friend bool operator==(const TRangedNum<T, lowerBound, upperBound> &lhs, const T rhs);
    friend bool operator==(const T lhs, const TRangedNum<T, lowerBound, upperBound> &rhs);
    friend bool operator!=(const TRangedNum<T, lowerBound, upperBound> &lhs,
      const TRangedNum<T, lowerBound, upperBound> &rhs);
    friend bool operator!=(const TRangedNum<T, lowerBound, upperBound> &lhs, const T rhs);
    friend bool operator!=(const T lhs, const TRangedNum<T, lowerBound, upperBound> &rhs);

    // Arithmetic operators.
    TRangedNum<T, lowerBound, upperBound> &operator+=(const TRangedNum<T, lowerBound, upperBound> &rhs);
    TRangedNum<T, lowerBound, upperBound> &operator+=(T rhs);
    TRangedNum<T, lowerBound, upperBound> &operator-=(const TRangedNum<T, lowerBound, upperBound> &rhs);
    TRangedNum<T, lowerBound, upperBound> &operator-=(T rhs);

    friend TRangedNum<T, lowerBound, upperBound> operator+(const TRangedNum<T, lowerBound, upperBound> &lhs,
      const TRangedNum<T, lowerBound, upperBound> &rhs);
    friend TRangedNum<T, lowerBound, upperBound> operator+(const TRangedNum<T, lowerBound, upperBound> &lhs,
      const T rhs);
    friend TRangedNum<T, lowerBound, upperBound> operator+(const T lhs,
      const TRangedNum<T, lowerBound, upperBound> &rhs);
    friend TRangedNum<T, lowerBound, upperBound> operator-(const TRangedNum<T, lowerBound, upperBound> &lhs,
      const TRangedNum<T, lowerBound, upperBound> &rhs);
    friend TRangedNum<T, lowerBound, upperBound> operator-(const TRangedNum<T, lowerBound, upperBound> &lhs,
      const T rhs);
    friend TRangedNum<T, lowerBound, upperBound> operator-(const T lhs,
      const TRangedNum<T, lowerBound, upperBound> &rhs);
  private:
    T m_storedValue;
  };
}

#include "TRangedNum.tpp"

#endif
