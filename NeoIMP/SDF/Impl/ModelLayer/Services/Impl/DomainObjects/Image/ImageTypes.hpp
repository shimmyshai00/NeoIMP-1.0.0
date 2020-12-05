#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGETYPES_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGETYPES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageTypes.hpp
 * PURPOSE: Type definitions for the available image types.
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

#include <SDF/ModelLayer/DomainObjects/Color/ColorTypes.hpp>
#include <SDF/ModelLayer/DomainObjects/Image/Image.hpp>

#include <variant>

namespace SDF::ModelLayer::DomainObjects::Image {
  typedef Image<Color::ColorRGB24, Color::Channel8> RGB24Image;
  typedef Image<Color::ColorRGB30, Color::Channel10> RGB30Image;
  typedef Image<Color::ColorRGB36, Color::Channel12> RGB36Image;
  typedef Image<Color::ColorRGB48, Color::Channel16> RGB48Image;

  typedef Image<Color::ColorCMYK32, Color::Channel8> CMYK32Image;
  typedef Image<Color::ColorCMYK40, Color::Channel10> CMYK40Image;
  typedef Image<Color::ColorCMYK48, Color::Channel12> CMYK48Image;
  typedef Image<Color::ColorCMYK64, Color::Channel16> CMYK64Image;

  typedef std::variant<
    RGB24Image, RGB30Image, RGB36Image, RGB48Image,
    CMYK32Image, CMYK40Image, CMYK48Image, CMYK64Image
  > ImageVariant;
}

#endif
