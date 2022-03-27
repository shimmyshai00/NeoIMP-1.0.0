#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_GIL_BUILTINRGBCOLORSPACEREPOSITORY_HPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_GIL_BUILTINRGBCOLORSPACEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BuiltinRgbColorSpaceRepository.hpp
 * PURPOSE: Defines the BuiltinRgbColorSpaceRepository template.
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

#include "../../../ModelLayer/DomainObjects/Engine/ColorSpaces/Fundamental/XyzD65.hpp"
#include "../../../ModelLayer/DomainObjects/Engine/Gil/ColorModel.hpp"
#include "../../../ModelLayer/AbstractData/Gil/ColorSpace.hpp"
#include "../../../ModelLayer/AbstractData/IBuiltinColorSpaceRepository.hpp"

#include <fruit/fruit.h>
#include <map>

namespace SDF::Editor::DataLayer::Repositories::Gil {
  // Class:      BuiltinRgbColorSpaceRepository
  // Purpose:    Defines a repository of fixed, built-in color space objects in order to help
  //             centralize their collection and access, for the Boost.GIL-based engine
  //             implementation and RGB-type color spaces.
  // Parameters: GilPixelT - The pixel data type the spaces map to.
  template<class GilPixelT>
  class BuiltinRgbColorSpaceRepository :
    public ModelLayer::AbstractData::IBuiltinColorSpaceRepository<
      ModelLayer::AbstractData::Gil::RgbColorSpace<GilPixelT>
    >
  {
  public:
    INJECT(BuiltinRgbColorSpaceRepository());

    const RgbColorSpace<PixelDataT> &
    retrieve(std::string key) const;
  private:
    std::map<std::string, ModelLayer::AbstractData::Gil::RgbColorSpace<GilPixelT>> m_colorSpaces;
  };
}

#include "BuiltinRgbColorSpaceRepository.tpp"

#endif
