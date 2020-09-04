/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRGBPixel.tpp
 * PURPOSE: Definition for the RGB pixel template.
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

#include <Impl/DomainObjects/Pixel/TRGBPixel.hpp>

#include <Impl/DomainObjects/Pixel/IPixelVisitor.hpp>
#include <Impl/DomainObjects/Color/CRGBColor.hpp>

#include <algorithm>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Pixel {
        template<class ValueType, ValueType maxVal>
        TRGBPixel<ValueType, maxVal>::TRGBPixel()
        : m_alpha(maxVal),
          m_r(0),
          m_g(0),
          m_b(0)
          {
          }

        template<class ValueType, ValueType maxVal>
        TRGBPixel<ValueType, maxVal>::TRGBPixel(ValueType r, ValueType g, ValueType b)
        : m_alpha(maxVal),
          m_r(std::clamp(r, 0, maxVal)),
          m_g(std::clamp(g, 0, maxVal)),
          m_b(std::clamp(b, 0, maxVal))
          {
          }

        template<class ValueType, ValueType maxVal>
        TRGBPixel<ValueType, maxVal>::TRGBPixel(ValueType alpha, ValueType r, ValueType g, ValueType b)
        : m_alpha(std::clamp(alpha, 0, maxVal)),
          m_r(std::clamp(r, 0, maxVal)),
          m_g(std::clamp(g, 0, maxVal)),
          m_b(std::clamp(b, 0, maxVal))
          {
          }

        template<class ValueType, ValueType maxVal>
        TRGBPixel<ValueType, maxVal>::TRGBPixel(Color::CRGBColor color)
        : m_alpha(maxVal),
          m_r(color.getRF() * maxVal),
          m_g(color.getGF() * maxVal),
          m_b(color.getBF() * maxVal)
          {
          }

        template<class ValueType, ValueType maxVal>
        TRGBPixel<ValueType, maxVal>::TRGBPixel(ValueType alpha, Color::CRGBColor color)
        : m_alpha(std::clamp(alpha, 0, maxVal)),
          m_r(color.getRF() * maxVal),
          m_g(color.getGF() * maxVal),
          m_b(color.getBF() * maxVal)
          {
          }

        template<class ValueType, ValueType maxVal>
        int TRGBPixel<ValueType, maxVal>::getChannelMax() const {
          return maxVal;
        }

        template<class ValueType, ValueType maxVal>
        int TRGBPixel<ValueType, maxVal>::getAlpha() const {
          return m_alpha;
        }

        template<class ValueType, ValueType maxVal>
        int TRGBPixel<ValueType, maxVal>::getR() const {
          return m_r;
        }

        template<class ValueType, ValueType maxVal>
        int TRGBPixel<ValueType, maxVal>::getG() const {
          return m_g;
        }

        template<class ValueType, ValueType maxVal>
        int TRGBPixel<ValueType, maxVal>::getB() const {
          return m_b;
        }

        template<class ValueType, ValueType maxVal>
        float TRGBPixel<ValueType, maxVal>::getAlphaF() const {
          return (0.0f + m_alpha) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TRGBPixel<ValueType, maxVal>::getRF() const {
          return (0.0f + m_r) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TRGBPixel<ValueType, maxVal>::getGF() const {
          return (0.0f + m_g) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TRGBPixel<ValueType, maxVal>::getBF() const {
          return (0.0f + m_b) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        Color::CRGBColor TRGBPixel<ValueType, maxVal>::getColor() const {
          Color::CRGBColor dummy(0, 0, 0);
          return Color::CRGBColor(getRF() * dummy.getChannelMax(),
            getGF() * dummy.getChannelMax(),
            getBF() * dummy.getChannelMax());
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setAlpha(int alpha) {
          m_alpha = std::clamp<int>(alpha, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setR(int r) {
          m_r = std::clamp<int>(r, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setG(int g) {
          m_g = std::clamp<int>(g, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setB(int b) {
          m_b = std::clamp<int>(b, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setAlphaF(float alpha) {
          m_alpha = std::clamp(alpha, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setRF(float r) {
          m_r = std::clamp(r, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setGF(float g) {
          m_g = std::clamp(g, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setBF(float b) {
          m_b = std::clamp(b, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::setWithColor(Color::CRGBColor color) {
          setRF(color.getRF());
          setGF(color.getGF());
          setBF(color.getBF());
        }

        template<class ValueType, ValueType maxVal>
        void TRGBPixel<ValueType, maxVal>::accept(IPixelVisitor &vis) {
          vis.visit(*this);
        }
      }
    }
  }
}
