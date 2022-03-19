#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_UICOLORCONVERTER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_UICOLORCONVERTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiColorConverter.hpp
 * PURPOSE: Defines the UiColorConverter template.
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

#include "../../../UILayer/AbstractModel/Defs/Color.hpp"
#include "../../DomainObjects/Engine/ColorSpaces/Fundamental/XyzD65.hpp"
#include "../../DomainObjects/Engine/IColorSpace.hpp"

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  // Class:      UiColorConverter
  // Purpose:    Converts a UI variant color object to a desired model color type. Not efficient -
  //             only for user color selections. Again we keep this in the service layer due to its
  //             bridging nature.
  // Parameters: DstPixelT - The destination pixel type.
  //             FundamentalSpaceT - The fundamental bridging space traits.
  template<class DstPixelT, class FundamentalSpaceT>
  class UiColorConverter {
  public:
    // Function:   UiColorConverter
    // Purpose:    Creates a new color converter.
    // Parameters: dstColorSpace - The destination color space.
    UiColorConverter(
      const DomainObjects::Engine::IColorSpace<DstPixelT, FundamentalSpaceT> *dstColorSpace
    );

    // Function:   convert
    // Purpose:    Convert a UI color variant.
    // Parameters: color - The color variant to convert.
    // Returns:    The color in the output pixel type.
    DstPixelT
    convert(UILayer::AbstractModel::Defs::AnyColor anyColor);
  private:
    const DomainObjects::Engine::IColorSpace<DstPixelT, FundamentalSpaceT> *m_dstColorSpace;
  };
}

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  // Convenience converters.
  template<class DstPixelT>
  using UiXyzD65Converter = UiColorConverter<
    DstPixelT,
    DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
  >;
}

#include "UiColorConverter.tpp"

#endif
