#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IIMAGEDELTA_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IIMAGEDELTA_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageDelta.hpp
 * PURPOSE: Defines the IImageDelta interface.
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

#include <SDF/Interfaces/IMessageReceiver.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <memory>
#include <string>

namespace SDF::ModelLayer::Services::AbstractDomain {
  class IImage;

  // Class:   IImageDelta
  // Purpose: Provides an interface for image deltas - objects which represent changes to an image document.
  //          All edits take the form of deltas, and an edited image is givne by the original plus a train of deltas
  //          leading to the new image. This allows for undoing operations easily and without storing a bunch of
  //          full-size copies of the image, which would otherwise be very wasteful of memory.
  class IImageDelta {
  public:
    virtual ~IImageDelta() = default;

    // Function:   applyDelta
    // Purpose:    Apply this image delta to a given image.
    // Parameters: image - The image to apply the delta to.
    //             messageReceiver - An optional message receiver to notify of the changes made to the image.
    // Returns:    None.
    virtual void
    applyDelta(IImage *image,
               Interfaces::IMessageReceiver<Defs::ImageChange> *messageReceiver
              ) = 0;
  };
}

#endif
