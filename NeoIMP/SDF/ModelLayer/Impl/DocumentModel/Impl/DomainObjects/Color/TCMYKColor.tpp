/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TCMYKColor.tpp
 * PURPOSE: Implementation of the TCMYKColor template.
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

#include <Impl/DomainObjects/Color/TCMYKColor.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      template<class T, unsigned int bitDepth>
      TCMYKColor<T, bitDepth>::TCMYKColor()
        : c(0),
          m(0),
          y(0),
          k(0)
          {
          }

      template<class T, unsigned int bitDepth>
      TCMYKColor<T, bitDepth>::TCMYKColor(T c, T m, T y, T k)
      : c(c),
        m(m),
        y(y),
        k(k)
        {
        }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getC() const {
        return c.get();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getM() const {
        return m.get();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getY() const {
        return y.get();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getK() const {
        return k.get();
      }

      template<class T, unsigned int bitDepth>
      float TCMYKColor<T, bitDepth>::getCf() const {
        return c.getFloat();
      }

      template<class T, unsigned int bitDepth>
      float TCMYKColor<T, bitDepth>::getMf() const {
        return m.getFloat();
      }

      template<class T, unsigned int bitDepth>
      float TCMYKColor<T, bitDepth>::getYf() const {
        return y.getFloat();
      }

      template<class T, unsigned int bitDepth>
      float TCMYKColor<T, bitDepth>::getKf() const {
        return k.getFloat();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getMaxC() const {
        return c.getMax();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getMaxM() const {
        return m.getMax();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getMaxY() const {
        return y.getMax();
      }

      template<class T, unsigned int bitDepth>
      int TCMYKColor<T, bitDepth>::getMaxK() const {
        return k.getMax();
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setC(int c) {
        this->c.set(c);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setM(int m) {
        this->m.set(m);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setY(int y) {
        this->y.set(y);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setK(int k) {
        this->k.set(k);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setCf(float c) {
        this->c.setFloat(c);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setMf(float m) {
        this->m.setFloat(m);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setYf(float y) {
        this->y.setFloat(y);
      }

      template<class T, unsigned int bitDepth>
      void TCMYKColor<T, bitDepth>::setKf(float k) {
        this->k.setFloat(k);
      }
    }
  }
}
