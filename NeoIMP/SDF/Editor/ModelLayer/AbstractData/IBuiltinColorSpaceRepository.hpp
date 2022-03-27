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

#include <string>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IBuiltinColorSpaceRepository
  // Purpose:    Defines a repository of built-in and baked-in (immutable) color spaces.
  // Parameters: ColorSpaceT - The type of color spaces held.
  //             PixelDataT - The type of pixel data used.
  template<template<class PixelDataT> class ColorSpaceT>
  class IBuiltinColorSpaceRepository {
  public:
    virtual ~IBuiltinColorSpaceRepository() = default;

    // Function:   retrieve
    // Purpose:    Retrieves a color space by a string key.
    // Parameters: key - The key to get.
    // Returns:    A reference to the color space.
    virtual const ColorSpaceT<PixelDataT> &
    retrieve(std::string key) const = 0;
  };
}

#endif
