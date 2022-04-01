#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGERETAINER_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGERETAINER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageRetainer.hpp
 * PURPOSE: Defines the IImageRetainer interface.
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
  // Class:      IImageRetainer
  // Purpose:    Defines an interface to store images created in the model layer.
  // Parameters: ImageT - The image type.
  template<class ImageT>
  class IImageRetainer {
  public:
    virtual ~IImageRetainer() = default;

    // Function:   retainImageAtAutoID
    // Purpose:    Eat an image and store it in the repository at the next available ID.
    // Parameters: image - The image to store.
    // Returns:    The ID where the image is stored at.
    virtual Common::Handle
    retainImageAtAutoID(std::unique_ptr<ImageT> a_image) = 0;
  };
}

#endif
