/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CRGBColor.cpp
 * PURPOSE: Implementation of the color class for an RGB color value.
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

#include <Impl/DomainObjects/Color/CRGBColor.hpp>

#include <algorithm>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Color {
        CRGBColor::CRGBColor(int r, int g, int b)
        : m_r(std::clamp(r, 0, c_channelMax)),
          m_g(std::clamp(g, 0, c_channelMax)),
          m_b(std::clamp(b, 0, c_channelMax))
          {
          }

        int CRGBColor::getChannelMax() const {
          return c_channelMax;
        }

        int CRGBColor::getR() const {
          return m_r;
        }

        int CRGBColor::getG() const {
          return m_g;
        }

        int CRGBColor::getB() const {
          return m_b;
        }

        float CRGBColor::getRF() const {
          return (0.0f + m_r) / c_channelMax;
        }

        float CRGBColor::getGF() const {
          return (0.0f + m_g) / c_channelMax;
        }

        float CRGBColor::getBF() const {
          return (0.0f + m_b) / c_channelMax;
        }

        void CRGBColor::setR(int r) {
          m_r = std::clamp(r, 0, c_channelMax);
        }

        void CRGBColor::setG(int g) {
          m_g = std::clamp(g, 0, c_channelMax);
        }

        void CRGBColor::setB(int b) {
          m_b = std::clamp(b, 0, c_channelMax);
        }

        void CRGBColor::setRF(float r) {
          setR(r * c_channelMax);
        }

        void CRGBColor::setGF(float g) {
          setG(g * c_channelMax);
        }

        void CRGBColor::setBF(float b) {
          setB(b * c_channelMax);
        }
      }
    }
  }
}
