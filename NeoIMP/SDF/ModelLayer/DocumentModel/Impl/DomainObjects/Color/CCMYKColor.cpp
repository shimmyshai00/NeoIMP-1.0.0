/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CCMYKColor.cpp
 * PURPOSE: Implementation of the color class for a CMYK color value.
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

#include <Impl/DomainObjects/Color/CCMYKColor.hpp>

#include <algorithm>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Color {
        CCMYKColor::CCMYKColor(int c, int m, int y, int k)
        : m_c(std::clamp(c, 0, c_channelMax)),
          m_m(std::clamp(m, 0, c_channelMax)),
          m_y(std::clamp(y, 0, c_channelMax)),
          m_k(std::clamp(k, 0, c_channelMax))
          {
          }

        int CCMYKColor::getChannelMax() const {
          return c_channelMax;
        }

        int CCMYKColor::getC() const {
          return m_c;
        }

        int CCMYKColor::getM() const {
          return m_m;
        }

        int CCMYKColor::getY() const {
          return m_y;
        }

        int CCMYKColor::getK() const {
          return m_k;
        }

        float CCMYKColor::getCF() const {
          return (0.0 + m_c) / c_channelMax;
        }

        float CCMYKColor::getMF() const {
          return (0.0 + m_m) / c_channelMax;
        }

        float CCMYKColor::getYF() const {
          return (0.0 + m_y) / c_channelMax;
        }

        float CCMYKColor::getKF() const {
          return (0.0 + m_k) / c_channelMax;
        }

        void CCMYKColor::setC(int c) {
          m_c = std::clamp(c, 0, c_channelMax);
        }

        void CCMYKColor::setM(int m) {
          m_m = std::clamp(m, 0, c_channelMax);
        }

        void CCMYKColor::setY(int y) {
          m_y = std::clamp(y, 0, c_channelMax);
        }

        void CCMYKColor::setK(int k) {
          m_k = std::clamp(k, 0, c_channelMax);
        }

        void CCMYKColor::setCF(float c) {
          setC(c * c_channelMax);
        }

        void CCMYKColor::setMF(float m) {
          setM(m * c_channelMax);
        }

        void CCMYKColor::setYF(float y) {
          setY(y * c_channelMax);
        }

        void CCMYKColor::setKF(float k) {
          setK(k * c_channelMax);
        }
      }
    }
  }
}
