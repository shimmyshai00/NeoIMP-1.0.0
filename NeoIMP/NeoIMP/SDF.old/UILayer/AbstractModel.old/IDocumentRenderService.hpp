#ifndef SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTRENDERSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTRENDERSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentRenderService.hpp
 * PURPOSE: Defines the IDocumentRenderService interface.
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

#include <SDF/Interfaces/IObservable.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <vector>

namespace SDF::UILayer::AbstractModel {
  // Class:      IDocumentRenderService
  // Purpose:    Defines an interface for the service for rendering documents.
  // Parameters: None.
  class IDocumentRenderService {
  public:
    virtual ~IDocumentRenderService() = default;

    // Function:   renderImage
    // Purpose:    Performs a complete render of a loaded image document.
    // Parameters: imageHandle - The handle of the image to render.
    // Returns:    A domain handle to the rendering.
    virtual Handle
    renderImage(Handle imageHandle) = 0;

    // Function:   getRenderedRegion
    // Purpose:    Get a region of an already-rendered document.
    // Parameters: origin - A reference to receive the pointer to the upper-left pixel of the region.
    //             rowStride - The step size that must be added to that pointer to get to the next row of pixels.
    //             renderingHandle - The handle of the rendered image.
    //             x1, y1, x2, y2 - The coordinates of the rectangle of the region to render.
    // Returns:    None.
    virtual void
    getRenderedRegion(const unsigned char *&origin,
                      std::ptrdiff_t &rowStride,
                      Handle renderingHandle,
                      int x1, int y1, int x2, int y2
                     ) = 0;
  };
}

#endif
