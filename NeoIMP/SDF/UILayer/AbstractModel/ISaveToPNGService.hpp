#ifndef SDF_UILAYER_ABSTRACTMODEL_ISAVETOPNGSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_ISAVETOPNGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISaveToPNGService.hpp
 * PURPOSE: Defines the ISaveToPNGService interface.
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

#include "../../Common/Handle.hpp"

#include <memory>
#include <string>

namespace SDF::UILayer::AbstractModel {
  // Class:      ISaveToPNGService
  // Purpose:    Defines the interface for an MVC service that saves image documents to PNG files.
  // Parameters: None.
  class ISaveToPNGService {
  public:
    virtual ~ISaveToPNGService() = default;

    // Function:   save
    // Purpose:    Saves an image document to a .PNG file.
    // Parameters: imageHandle - The handle of the image to save.
    //             fileSpec - The file spec to save to.
    //             fileFormat - The file format to save in.
    // Returns:    None.
    virtual void
    save(Common::Handle imageHandle,
         std::string fileSpec
        ) = 0;
  };
}

#endif
