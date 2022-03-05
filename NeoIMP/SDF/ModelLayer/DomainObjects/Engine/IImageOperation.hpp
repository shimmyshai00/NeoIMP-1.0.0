#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IIMAGEOPERATION_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IIMAGEOPERATION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageOperation.hpp
 * PURPOSE: Defines the IImageOperation interface.
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

#include "../../Math/Rect.hpp"

#include "IProgressListener.hpp"

#include <cstddef>
#include <vector>

namespace SDF::ModelLayer::DomainObjects::Engine {
  struct OpRegion {
    std::size_t layerNum;
    Math::Rect<float> rect;

    OpRegion(std::size_t layerNum_,
             Math::Rect<float> rect_
            )
      : layerNum(layerNum_),
        rect(rect_)
    {
    }
  };
}

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      IImageOperation
  // Purpose:    Wraps an operation to be performed on an image.
  // Parameters: ImplT - The type of image implementation.
  template<class ImplT>
  class IImageOperation {
  public:
    virtual ~IImageOperation() = default;

    // Function:   performOperation
    // Purpose:    Perform the operation on a given part of the image.
    // Parameters: imageImpl - The implemented image to operate on.
    //             regions - The regions to operate on.
    //             progress - An optional progress indicator.
    // Returns:    Whether the operation succeeded or not.
    virtual bool
    performOperation(ImplT &imageImpl,
                     const std::vector<OpRegion> &regions,
                     IProgressListener *progress
                    ) = 0;
  };
}

#endif
