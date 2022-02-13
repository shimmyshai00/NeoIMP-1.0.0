#ifndef SDF_UILAYER_ABSTRACTMODEL_ICREATEIMAGESERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_ICREATEIMAGESERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ICreateImageService.hpp
 * PURPOSE: Defines the ICreateImageService interface.
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

#include "Defs/Handle.hpp"
#include "Defs/ImageSpec.hpp"

#include <memory>

namespace SDF::UILayer::AbstractModel {
  // Class:      ICreateImageService
  // Purpose:    Defines the interface for an MVC service that creates image documents.
  // Parameters: None.
  class ICreateImageService {
  public:
    virtual ~ICreateImageService() = default;

    // Function:   createImage
    // Purpose:    Create a new image document.
    // Parameters: spec - The spec to use to create the document.
    // Returns:    A handle to the new image document.
    virtual Defs::Handle
    createImage(Defs::ImageSpec spec) = 0;
  };
}

#endif
