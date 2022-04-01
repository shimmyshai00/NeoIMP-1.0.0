#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEACCESSOR_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEACCESSOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageAccessor.hpp
 * PURPOSE: Defines the IImageAccessor interface.
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

#include "../../../Common/Handle.hpp"

#include <memory>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IImageAccessor
  // Purpose:    Defines an interface to access stored images using one of their interfaces.
  // Parameters: IfaceT - The interface type to access the images as. Must be a base of
  //             DomainObjects::Engine::Image::Image.
  template<class IfaceT>
  class IImageAccessor {
  public:
    virtual ~IImageAccessor() = default;

    // Function:   accessImage
    // Purpose:    Accesses the image with the given interface only.
    // Parameters: imageHandle - The handle to the image to access.
    // Returns:    A pointer to the image interface.
    virtual IfaceT *
    accessImage(Common::Handle a_imageHandle) = 0;
  };
}

#endif
