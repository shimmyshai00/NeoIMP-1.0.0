#ifndef SDF_MODELLAYER_DOMAINOBJECTS_COLOR_COLORTYPES_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_COLOR_COLORTYPES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorTypes.hpp
 * PURPOSE: Type definitions for the available color model/channel combinations.
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

#include <SDF/ModelLayer/DomainObjects/Color/ColorChannel.hpp>
#include <SDF/ModelLayer/DomainObjects/Color/RGBColor.hpp>
#include <SDF/ModelLayer/DomainObjects/Color/CMYKColor.hpp>

namespace SDF::ModelLayer::DomainObjects::Color {
  typedef ColorChannel<unsigned char, 255> Channel8;
  typedef ColorChannel<unsigned short, 1023> Channel10;
  typedef ColorChannel<unsigned short, 4095> Channel12;
  typedef ColorChannel<unsigned short, 65535> Channel16;

  typedef RGBColor<Channel8> ColorRGB24;
  typedef RGBColor<Channel10> ColorRGB30;
  typedef RGBColor<Channel12> ColorRGB36;
  typedef RGBColor<Channel16> ColorRGB48;

  typedef CMYKColor<Channel8> ColorCMYK32;
  typedef CMYKColor<Channel10> ColorCMYK40;
  typedef CMYKColor<Channel12> ColorCMYK48;
  typedef CMYKColor<Channel16> ColorCMYK64;
}

#endif
