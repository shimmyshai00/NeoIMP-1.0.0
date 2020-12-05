/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Layer.tpp
 * PURPOSE: Implementation of the image layer template.
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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/Layer.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image {
  template<class PixelType, class AlphaType>
  Layer<PixelType, AlphaType>::Layer(int width, int height) :
  m_alphaChannel(width, height),
  m_imageRaster(width, height) {}

  template<class PixelType, class AlphaType>
  int Layer<PixelType, AlphaType>::getWidth() const {
    return m_imageRaster.getWidth();
  }

  template<class PixelType, class AlphaType>
  int Layer<PixelType, AlphaType>::getHeight() const {
    return m_imageRaster.getHeight();
  }

  template<class PixelType, class AlphaType>
  AlphaType Layer<PixelType, AlphaType>::getAlphaAt(Math::Coord<int> pos) const {
    return m_alphaChannel(pos);
  }

  template<class PixelType, class AlphaType>
  PixelType Layer<PixelType, AlphaType>::getPixelAt(Math::Coord<int> pos) const {
    return m_imageRaster(pos);
  }

  template<class PixelType, class AlphaType>
  void Layer<PixelType, AlphaType>::setAlphaAt(Math::Coord<int> pos, AlphaType newValue) {
    m_alphaChannel(pos) = newValue;
  }

  template<class PixelType, class AlphaType>
  void Layer<PixelType, AlphaType>::setPixelAt(Math::Coord<int> pos, PixelType newValue) {
    m_imageRaster(pos) = newValue;
  }
}
