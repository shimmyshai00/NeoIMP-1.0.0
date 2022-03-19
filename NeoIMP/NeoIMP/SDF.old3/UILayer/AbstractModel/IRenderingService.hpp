#ifndef SDF_UILAYER_ABSTRACTMODEL_IRENDERINGSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IRENDERINGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRenderingService.hpp
 * PURPOSE: Defines the IRenderingService interface.
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

#include <cstddef>

namespace SDF::UILayer::AbstractModel {
  // Class:      IRenderingService
  // Purpose:    Defines the interface for an MVC service to render images to a screen-displayable
  //             format. Note: right now, only one format (RGB32) is supported.
  // Parameters: None.
  class IRenderingService {
  public:
    virtual ~IRenderingService() = default;

    // Function:   renderImage
    // Purpose:    Renders an image to a screenable format.
    // Parameters: imageHandle - The handle to the image to render.
    // Returns:    A handle to the produced rendering.
    virtual Defs::Handle
    renderImage(Defs::Handle imageHandle) = 0;

    // Function:   renderSubregion
    // Purpose:    Renders a sub-region of an image only. The image must first have been fully
    //             rendered with renderImage above.
    // Parameters: imageHandle - The handle to the image to render.
    //             x1, y1, x2, y2 - The pixel coordinates of the rectangle to render.
    // Returns:    The handle of the image rendering (same as from prior).
    virtual Defs::Handle
    renderSubregion(Defs::Handle imageHandle,
                    std::size_t x1,
                    std::size_t y1,
                    std::size_t x2,
                    std::size_t y2
                   ) = 0;

    // Function:   retrieveRenderData
    // Purpose:    Fetches a pointer to the render data of a previously-rendered image.
    // Parameters: renderHandle - The handle of the rendering (not the image!) to fetch.
    //             originPtr - Receives a pointer to the origin of the render data.
    //             rowStride - Receives the offset to, given a pixel pointed to by a pointer offset
    //                         from originPtr, step to the same image position on the next row of
    //                         pixels
    //             pixelWidth - Receives the size of each pixel in bytes.
    // Returns:    None - all returns are in passed reference arguments.
    virtual void
    retrieveRenderData(Defs::Handle renderHandle,
                       unsigned char * &originPtr,
                       std::ptrdiff_t &rowStride,
                       std::size_t &pixelWidth
                      ) = 0;
  };
}

#endif
