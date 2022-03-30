#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGELOADER_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGELOADER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageLoader.hpp
 * PURPOSE: Defines the IImageLoader interface.
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
#include "EFormat.hpp"

#include <string>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IImageLoader
  // Purpose:    Defines an interface to load an image from persistent storage.
  // Parameters: ImageT - The image type. This generally should be a variant aggregating all image
  //                      types of a particular implementation.
  template<class ImageT>
  class IImageLoader {
  public:
    virtual ~IImageLoader() = default;

    // Function:   loadImageFromFile
    // Purpose:    Loads an image from a disk file.
    // Parameters: fileSpec - The file spec to load.
    //             fileFormat - The format to attempt interpretation of the image as.
    // Returns:    The ID of the loaded image, or Common::HANDLE_INVALID if failed.
    virtual Common::Handle
    loadImageFromFile(std::string fileSpec, EFormat fileFormat) = 0;
  };
}

#endif
