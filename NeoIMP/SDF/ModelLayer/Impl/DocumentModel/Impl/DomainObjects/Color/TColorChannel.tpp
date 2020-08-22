/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TColorChannel.tpp
 * PURPOSE: Implementation of the TColorChannel template.
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

#include "Impl/DomainObjects/Color/TColorChannel.hpp"
#include <algorithm>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      template<class T, unsigned int bitWidth>
      TColorChannel<T, bitWidth>::TColorChannel()
      : m_val(0),
        m_maxVal((1U << bitWidth) - 1)
        {
        }

      template<class T, unsigned int bitWidth>
      TColorChannel<T, bitWidth>::TColorChannel(T initialValue)
      : m_val(std::min<T>(initialValue, (1U << bitWidth) - 1)),
        m_maxVal((1U << bitWidth) - 1)
        {
        }

      template<class T, unsigned int bitWidth>
      int TColorChannel<T, bitWidth>::get() const {
        return m_val;
      }

      template<class T, unsigned int bitWidth>
      float TColorChannel<T, bitWidth>::getFloat() const {
        return static_cast<float>(m_val) / m_maxVal;
      }

      template<class T, unsigned int bitWidth>
      int TColorChannel<T, bitWidth>::getMax() const {
        return m_maxVal;
      }

      template<class T, unsigned int bitWidth>
      void TColorChannel<T, bitWidth>::set(int val) {
        m_val = static_cast<T>(std::clamp<T>(val, 0, m_maxVal));
      }

      template<class T, unsigned int bitWidth>
      void TColorChannel<T, bitWidth>::setFloat(float val) {
        m_val = static_cast<T>(std::clamp<T>(val * m_maxVal, 0.0f, m_maxVal));
      }
    }
  }
}
