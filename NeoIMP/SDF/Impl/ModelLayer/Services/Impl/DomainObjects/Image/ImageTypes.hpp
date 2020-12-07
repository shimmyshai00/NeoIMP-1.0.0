#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_IMAGETYPES_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_IMAGETYPES_HPP

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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Color/ColorTypes.hpp>
#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/Image.hpp>

#include <variant>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image {
  typedef Image<Color::RGB24Color, Color::AdditiveChannel8> RGB24Image;
  typedef Image<Color::RGB30Color, Color::AdditiveChannel10> RGB30Image;
  typedef Image<Color::RGB36Color, Color::AdditiveChannel12> RGB36Image;
  typedef Image<Color::RGB48Color, Color::AdditiveChannel16> RGB48Image;

  typedef Image<Color::CMYK32Color, Color::AdditiveChannel8> CMYK32Image;
  typedef Image<Color::CMYK40Color, Color::AdditiveChannel8> CMYK40Image;
  typedef Image<Color::CMYK48Color, Color::AdditiveChannel8> CMYK48Image;
  typedef Image<Color::CMYK64Color, Color::AdditiveChannel8> CMYK64Image;

  typedef std::variant<
    RGB24Image, RGB30Image, RGB36Image, RGB48Image,
    CMYK32Image, CMYK40Image, CMYK48Image, CMYK64Image
  > ImageVariant;
}

#endif
