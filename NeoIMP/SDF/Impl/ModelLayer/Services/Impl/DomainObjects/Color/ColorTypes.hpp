#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_COLOR_COLORTYPES_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_COLOR_COLORTYPES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorTypes.hpp
 * PURPOSE: Defines different available specific color types (enumerated in ModelLayer::ColorModel and
 *          ModelLayer::BitDepth).
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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Color/Channel.hpp>
#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Color/RGBColor.hpp>
#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Color/CMYKColor.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Color {
  typedef Channel<unsigned char, 255, 0> AdditiveChannel8;
  typedef Channel<unsigned short, 1023, 0> AdditiveChannel10;
  typedef Channel<unsigned short, 4095, 0> AdditiveChannel12;
  typedef Channel<unsigned short, 65535, 0> AdditiveChannel16;

  typedef Channel<unsigned char, 255, 255> SubtractiveChannel8;
  typedef Channel<unsigned short, 1023, 1023> SubtractiveChannel10;
  typedef Channel<unsigned short, 4095, 4095> SubtractiveChannel12;
  typedef Channel<unsigned short, 65535, 65535> SubtractiveChannel16;

  typedef RGBColor<AdditiveChannel8> RGB24Color;
  typedef RGBColor<AdditiveChannel10> RGB30Color;
  typedef RGBColor<AdditiveChannel12> RGB36Color;
  typedef RGBColor<AdditiveChannel16> RGB48Color;

  typedef CMYKColor<SubtractiveChannel8> CMYK32Color;
  typedef CMYKColor<SubtractiveChannel10> CMYK40Color;
  typedef CMYKColor<SubtractiveChannel12> CMYK48Color;
  typedef CMYKColor<SubtractiveChannel16> CMYK64Color;
}

#endif
