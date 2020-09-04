/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TCMYKPixel.tpp
 * PURPOSE: Definition for the CMYK pixel template.
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

#include <Impl/DomainObjects/Pixel/TCMYKPixel.hpp>

#include <Impl/DomainObjects/Pixel/IPixelVisitor.hpp>
#include <Impl/DomainObjects/Color/CCMYKColor.hpp>

#include <algorithm>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Pixel {
        template<class ValueType, ValueType maxVal>
        TCMYKPixel<ValueType, maxVal>::TCMYKPixel()
        : m_alpha(maxVal),
          m_c(0),
          m_m(0),
          m_y(0),
          m_k(maxVal)
          {
          }

        template<class ValueType, ValueType maxVal>
        TCMYKPixel<ValueType, maxVal>::TCMYKPixel(ValueType c, ValueType m, ValueType y, ValueType k)
        : m_alpha(maxVal),
          m_c(std::clamp(c, 0, maxVal)),
          m_m(std::clamp(m, 0, maxVal)),
          m_y(std::clamp(y, 0, maxVal)),
          m_k(std::clamp(k, 0, maxVal))
          {
          }

        template<class ValueType, ValueType maxVal>
        TCMYKPixel<ValueType, maxVal>::TCMYKPixel(ValueType alpha, ValueType c, ValueType m, ValueType y, ValueType k)
        : m_alpha(std::clamp(alpha, 0, maxVal)),
          m_c(std::clamp(c, 0, maxVal)),
          m_m(std::clamp(m, 0, maxVal)),
          m_y(std::clamp(y, 0, maxVal)),
          m_k(std::clamp(k, 0, maxVal))
          {
          }

        template<class ValueType, ValueType maxVal>
        TCMYKPixel<ValueType, maxVal>::TCMYKPixel(Color::CCMYKColor color)
        : m_alpha(maxVal),
          m_c(color.getCF() * maxVal),
          m_m(color.getMF() * maxVal),
          m_y(color.getYF() * maxVal),
          m_k(color.getKF() * maxVal)
          {
          }

        template<class ValueType, ValueType maxVal>
        TCMYKPixel<ValueType, maxVal>::TCMYKPixel(ValueType alpha, Color::CCMYKColor color)
        : m_alpha(std::clamp(alpha, 0, maxVal)),
          m_c(color.getCF() * maxVal),
          m_m(color.getMF() * maxVal),
          m_y(color.getYF() * maxVal),
          m_k(color.getKF() * maxVal)
          {
          }

        template<class ValueType, ValueType maxVal>
        int TCMYKPixel<ValueType, maxVal>::getChannelMax() const {
          return maxVal;
        }

        template<class ValueType, ValueType maxVal>
        int TCMYKPixel<ValueType, maxVal>::getAlpha() const {
          return m_alpha;
        }

        template<class ValueType, ValueType maxVal>
        int TCMYKPixel<ValueType, maxVal>::getC() const {
          return m_c;
        }

        template<class ValueType, ValueType maxVal>
        int TCMYKPixel<ValueType, maxVal>::getM() const {
          return m_m;
        }

        template<class ValueType, ValueType maxVal>
        int TCMYKPixel<ValueType, maxVal>::getY() const {
          return m_y;
        }

        template<class ValueType, ValueType maxVal>
        int TCMYKPixel<ValueType, maxVal>::getK() const {
          return m_k;
        }

        template<class ValueType, ValueType maxVal>
        float TCMYKPixel<ValueType, maxVal>::getAlphaF() const {
          return (0.0f + m_alpha) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TCMYKPixel<ValueType, maxVal>::getCF() const {
          return (0.0f + m_c) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TCMYKPixel<ValueType, maxVal>::getMF() const {
          return (0.0f + m_m) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TCMYKPixel<ValueType, maxVal>::getYF() const {
          return (0.0f + m_y) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        float TCMYKPixel<ValueType, maxVal>::getKF() const {
          return (0.0f + m_k) / maxVal;
        }

        template<class ValueType, ValueType maxVal>
        Color::CCMYKColor TCMYKPixel<ValueType, maxVal>::getColor() const {
          Color::CCMYKColor dummy(0, 0, 0, 0);
          return Color::CCMYKColor(getCF() * dummy.getChannelMax(),
            getMF() * dummy.getChannelMax(),
            getYF() * dummy.getChannelMax(),
            getKF() * dummy.getChannelMax());
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setAlpha(int alpha) {
          m_alpha = std::clamp<int>(alpha, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setC(int c) {
          m_c = std::clamp<int>(c, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setM(int m) {
          m_m = std::clamp<int>(m, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setY(int y) {
          m_y = std::clamp<int>(y, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setK(int k) {
          m_k = std::clamp<int>(k, 0, maxVal);
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setAlphaF(float alpha) {
          m_alpha = std::clamp(alpha, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setCF(float c) {
          m_c = std::clamp(c, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setMF(float m) {
          m_m = std::clamp(m, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setYF(float y) {
          m_y = std::clamp(y, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setKF(float k) {
          m_k = std::clamp(k, 0.0f, 1.0f) * maxVal;
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::setWithColor(Color::CCMYKColor color) {
          setCF(color.getCF());
          setMF(color.getMF());
          setYF(color.getYF());
          setKF(color.getKF());
        }

        template<class ValueType, ValueType maxVal>
        void TCMYKPixel<ValueType, maxVal>::accept(IPixelVisitor &vis) {
          vis.visit(*this);
        }
      }
    }
  }
}
