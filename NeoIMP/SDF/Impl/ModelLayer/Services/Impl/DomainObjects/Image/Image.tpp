/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Image.tpp
 * PURPOSE: Implementation of the full image template.
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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/Image.hpp>
#include <cassert>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image {
  template<class PixelType, class AlphaType>
  Image<PixelType, AlphaType>::Image(int width, int height, float ppi) : m_width(width), m_height(height), m_ppi(ppi) {
    addLayer(width, height);
  }

  template<class PixelType, class AlphaType>
  int Image<PixelType, AlphaType>::getWidth() const {
    return m_width;
  }

  template<class PixelType, class AlphaType>
  int Image<PixelType, AlphaType>::getHeight() const {
    return m_height;
  }

  template<class PixelType, class AlphaType>
  float Image<PixelType, AlphaType>::getPpi() const {
    return m_ppi;
  }

  template<class PixelType, class AlphaType>
  int Image<PixelType, AlphaType>::getNumLayers() const {
    return m_layers.size();
  }

  template<class PixelType, class AlphaType>
  int Image<PixelType, AlphaType>::getLayerWidth(int layerNum) const {
    assert((0 <= layerNum) && (layerNum < m_layers.size()));

    return m_layers[layerNum]->getWidth();
  }

  template<class PixelType, class AlphaType>
  int Image<PixelType, AlphaType>::getLayerHeight(int layerNum) const {
    assert((0 <= layerNum) && (layerNum < m_layers.size()));

    return m_layers[layerNum]->getHeight();
  }

  template<class PixelType, class AlphaType>
  AlphaType Image<PixelType, AlphaType>::getAlphaAt(int layerNum, Math::Coord<int> pos) const {
    assert((0 <= layerNum) && (layerNum < m_layers.size()));

    return m_layers[layerNum]->getAlphaAt(pos);
  }

  template<class PixelType, class AlphaType>
  PixelType Image<PixelType, AlphaType>::getPixelAt(int layerNum, Math::Coord<int> pos) const {
    assert((0 <= layerNum) && (layerNum < m_layers.size()));

    return m_layers[layerNum]->getPixelAt(pos);
  }

  template<class PixelType, class AlphaType>
  void Image<PixelType, AlphaType>::addLayer(int width, int height) {
    m_layers.push_back(std::make_unique<Layer<PixelType, AlphaType>>(width, height));
  }

  template<class PixelType, class AlphaType>
  void Image<PixelType, AlphaType>::setAlphaAt(int layerNum, Math::Coord<int> pos, AlphaType newValue) {
    assert((0 <= layerNum) && (layerNum < m_layers.size()));

    m_layers[layerNum]->setAlphaAt(pos, newValue);
  }

  template<class PixelType, class AlphaType>
  void Image<PixelType, AlphaType>::setPixelAt(int layerNum, Math::Coord<int> pos, PixelType newValue) {
    assert((0 <= layerNum) && (layerNum < m_layers.size()));

    m_layers[layerNum]->setAlphaAt(pos, newValue);
  }
}
