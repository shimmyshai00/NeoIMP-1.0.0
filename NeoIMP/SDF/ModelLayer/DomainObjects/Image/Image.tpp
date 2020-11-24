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

#include <SDF/ModelLayer/DomainObjects/Image/Image.hpp>

namespace SDF::ModelLayer::DomainObjects::Image {
  Image::Image(int width, int height, float ppi);
  Image::~Image();

  int Image::getWidth() const;
  int Image::getHeight() const;
  float Image::getPpi() const;

  int Image::getNumLayers() const;
  int Image::getLayerWidth(int layerNum) const;
  int Image::getLayerHeight(int layerNum) const;

  AlphaType Image::getAlphaAt(int layerNum, Coord<int> pos) const;
  PixelType Image::getPixelAt(int layerNum, Coord<int> pos) const;

  void Image::setAlphaAt(int layerNum, Coord<int> pos, PixelType newValue);
  void Image::setPixelAt(int layerNum, Coord<int> pos, PixelType newValue);
}
