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

#include <SDF/ModelLayer/DomainObjects/Image/Layer.hpp>

namespace SDF::ModelLayer::DomainObjects::Image {
  template<class PixelType, class AlphaType>
  Layer::Layer(int width, int height) :
  m_width(width),
  m_height(height),
  m_alphaChannel(width, height),
  m_imageRaster(with, height) {}

  template<class PixelType, class AlphaType>
  Layer::~Layer() {}

  template<class PixelType, class AlphaType>
  int Layer::getWidth() const {
    return m_width;
  }

  template<class PixelType, class AlphaType>
  int Layer::getHeight() const {
    return m_height;
  }

  template<class PixelType, class AlphaType>
  AlphaType Layer::getAlphaAt(Coord<int> pos) const {
    return m_alphaChannel(pos);
  }

  template<class PixelType, class AlphaType>
  PixelType Layer::getPixelAt(Coord<int> pos) const {
    return m_imageRaster(pos);
  }

  template<class PixelType, class AlphaType>
  void Layer::setAlphaAt(Coord<int> pos, PixelType newValue) {
    m_alphaChannel(pos) = newValue;
  }

  template<class PixelType, class AlphaType>
  void Layer::setPixelAt(Coord<int> pos, PixelType newValue) {
    m_imageRaster(pos) = newValue;
  }
}
