#ifndef SDF_UILAYER_METRICS_QUANTITY_HPP
#define SDF_UILAYER_METRICS_QUANTITY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Quantity.hpp
 * PURPOSE: A class representing quantities with a given physical dimension. This is a simplistic unit framework that
 *          only supports quantities that are powers of a single base dimension.
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

namespace SDF::UILayer::Metrics {
  template<class D, int Exp>
  class Quantity {
  public:
    Quantity() :
    m_val(0) {}

    Quantity(float val, const Unit<D> inUnit) :
    m_val(val * inUnit.getConversionTo(BaseUnit<D>())) {}

    ~Quantity() {}

    float inUnitsOf(const Unit<D> unit) {
      return m_val * inUnit.getConversionTo(BaseUnit<D>());
    }
    
    Quantity<D, Exp> &operator+=(const Quantity<D, Exp> &rhs) {
      m_val += rhs.m_val;
      return *this;
    }

    Quantity<D, Exp> &operator-=(const Quantity<D, Exp> &rhs) {
      m_val -= rhs.m_val;
      return *this;
    }

    // Non-member operators.
    template<class D, int Exp>
    friend bool operator==(const Quantity<D, Exp> &lhs, const Quantity<D, Exp> &rhs) {
      return lhs.m_val == rhs.m_val;
    }

    template<class D, int Exp>
    friend bool operator!=(const Quantity<D, Exp> &lhs, const Quantity<D, Exp> &rhs) {
      return !(lhs == rhs);
    }

    template<class D, int Exp>
    friend Quantity<D, Exp> operator+(const Quantity<D, Exp> &lhs, const Quantity<D, Exp> &rhs) {
      return Quantity<D, Exp>(lhs) += rhs;
    }

    template<class D, int Exp>
    friend Quantity<D, Exp> operator-(const Quantity<D, Exp> &lhs, const Quantity<D, Exp> &rhs) {
      return Quantity<D, Exp>(lhs) -= rhs;
    }

    template<class D, int ExpL, int ExpR>
    friend Quantity<D, ExpL + ExpR> operator*(const Quantity<D, ExpL> &lhs, const Quantity<D, ExpR> &rhs) {
      Quantity<D, ExpL, ExpR> rv;
      rv.m_val = lhs.m_val * rhs.m_val;
    }

    template<class D, int ExpL, int ExpR>
    friend Quantity<D, ExpL - ExpR> operator/(const Quantity<D, ExpL> &lhs, const Quantity<D, ExpR> &rhs) {
      Quantity<D, ExpL, ExpR> rv;
      rv.m_val = lhs.m_val / rhs.m_val;
    }
  private:
    // The size of the quantity in base units.
    float m_val;
  };
}

#endif
