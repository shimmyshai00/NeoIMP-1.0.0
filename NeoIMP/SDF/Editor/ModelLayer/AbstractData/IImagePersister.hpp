#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEPERSISTER_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEPERSISTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImagePersister.hpp
 * PURPOSE: Defines the IImagePersister interface.
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
  // Class:      IImagePersister
  // Purpose:    Defines an interface to persist images.
  // Parameters: ImageT - The image type. This generally should be a variant aggregating all image
  //                      types of a particular implementation.
  template<class ImageT>
  class IImagePersister {
  public:
    virtual ~IImagePersister() = default;

    // Function:   registerFileSpec
    // Purpose:    Registers a new file spec with the repository. Does not save any data under
    //             it.
    // Parameters: id - The ID of the image to give a file spec to.
    //             fileSpec - The file spec to register.
    //             fileFormat - The file format to use for persistence.
    virtual void
    registerFileSpec(Common::Handle id, std::string fileSpec, EFormat fileFormat) = 0;

    // Function:   persistImage
    // Purpose:    Forces persistence of an image. Note: either this image must have already
    //             been loaded or else a file spec must have been given to the repository via
    //             the registerFileSpec method. If neither of these are done, this will throw.
    // Parameters: id - The ID of the image to persist.
    // Returns:    None.
    virtual void
    persistImage(Common::Handle id) = 0;
  };
}

#endif
