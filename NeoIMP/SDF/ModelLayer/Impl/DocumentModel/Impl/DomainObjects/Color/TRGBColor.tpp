/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRGBColor.tpp
 * PURPOSE: Implementation of the TRGBColor template.
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

#include <Impl/DomainObjects/Color/TRGBColor.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      template<class T, unsigned int bitDepth>
      TRGBColor<T, bitDepth>::TRGBColor()
      : r(0),
        g(0),
        b(0)
        {
        }

      template<class T, unsigned int bitDepth>
      TRGBColor<T, bitDepth>::TRGBColor(T r, T g, T b)
      : r(r),
        g(g),
        b(b)
        {
        }

      template<class T, unsigned int bitDepth>
      int TRGBColor<T, bitDepth>::getR() const {
        return r.get();
      }

      template<class T, unsigned int bitDepth>
      int TRGBColor<T, bitDepth>::getG() const {
        return g.get();
      }

      template<class T, unsigned int bitDepth>
      int TRGBColor<T, bitDepth>::getB() const {
        return b.get();
      }

      template<class T, unsigned int bitDepth>
      float TRGBColor<T, bitDepth>::getRf() const {
        return static_cast<float>(r.getFloat());
      }

      template<class T, unsigned int bitDepth>
      float TRGBColor<T, bitDepth>::getGf() const {
        return static_cast<float>(g.getFloat());
      }

      template<class T, unsigned int bitDepth>
      float TRGBColor<T, bitDepth>::getBf() const {
        return static_cast<float>(b.getFloat());
      }

      template<class T, unsigned int bitDepth>
      int TRGBColor<T, bitDepth>::getMaxR() const {
        return r.getMax();
      }

      template<class T, unsigned int bitDepth>
      int TRGBColor<T, bitDepth>::getMaxG() const {
        return g.getMax();
      }

      template<class T, unsigned int bitDepth>
      int TRGBColor<T, bitDepth>::getMaxB() const {
        return b.getMax();
      }

      template<class T, unsigned int bitDepth>
      void TRGBColor<T, bitDepth>::setR(int r) {
        this->r.set(r);
      }

      template<class T, unsigned int bitDepth>
      void TRGBColor<T, bitDepth>::setG(int g) {
        this->g.set(g);
      }

      template<class T, unsigned int bitDepth>
      void TRGBColor<T, bitDepth>::setB(int b) {
        this->b.set(b);
      }

      template<class T, unsigned int bitDepth>
      void TRGBColor<T, bitDepth>::setRf(float r) {
        this->r.setFloat(r);
      }

      template<class T, unsigned int bitDepth>
      void TRGBColor<T, bitDepth>::setGf(float g) {
        this->g.setFloat(g);
      }

      template<class T, unsigned int bitDepth>
      void TRGBColor<T, bitDepth>::setBf(float b) {
        this->b.setFloat(b);
      }
    }
  }
}
