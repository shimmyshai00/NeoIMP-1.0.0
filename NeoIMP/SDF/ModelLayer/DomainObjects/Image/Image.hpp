#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Image.hpp
 * PURPOSE: Definition of the full image template.
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

#include <SDF/ModelLayer/Domainobjects/Image/Layer.hpp>
#include <SDF/ModelLayer/DomainObjects/Image/Coord.hpp>

#include <vector>

namespace SDF::ModelLayer::DomainObjects::Image {
  template<class PixelType, class AlphaType>
  class Image {
  public:
    Image(int width, int height, float ppi);
    ~Image();

    int getWidth() const;
    int getHeight() const;
    float getPpi() const;

    int getNumLayers() const;
    int getLayerWidth(int layerNum) const;
    int getLayerHeight(int layerNum) const;

    AlphaType getAlphaAt(int layerNum, Coord<int> pos) const;
    PixelType getPixelAt(int layerNum, Coord<int> pos) const;

    void addLayer(int width, int height);

    void setAlphaAt(int layerNum, Coord<int> pos, AlphaType newValue);
    void setPixelAt(int layerNum, Coord<int> pos, PixelType newValue);
  private:
    int m_width;
    int m_height;
    float m_ppi;

    std::vector<std::unique_ptr<Layer<PixelType, AlphaType>>> m_layers;
  };
}

#include "SDF/ModelLayer/DomainObjects/Image/Image.tpp"

#endif
