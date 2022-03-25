#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IBUILTINCOLORSPACEREPOSITORY_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IBUILTINCOLORSPACEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IBuiltinColorSpaceRepository.hpp
 * PURPOSE: Defines the IBuiltinColorSpaceRepository interface.
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

#include "../DomainObjects/Engine/IColorSpace.hpp"

#include <string>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IBuiltinColorSpaceRepository
  // Purpose:    Defines a fixed repository of color space objects (the ones hardcoded into the
  //             program.)
  // Parameters: EnumT - The enumeration type for the color spaces.
  //             PixelDataT - The pixel data type these color spaces operate on.
  //             FundamentalTraitsT - The fundamental spaces they map to.
  template<class EnumT, class PixelDataT, class FundamentalTraitsT>
  class IBuiltinColorSpaceRepository {
  public:
    virtual ~IBuiltinColorSpaceRepository() = default;

    // Function:   retrieve
    // Purpose:    Retrieves a color space from the repository.
    // Parameters: id - The key string identifying the color space.
    // Returns:    None.
    virtual DomainObjects::Engine::IColorSpace<PixelDataT, FundamentalTraitsT> *
    retrieve(EnumT id) = 0;
  };
}

#endif
