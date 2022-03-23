#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_IRENDERINGSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_IRENDERINGSERVICE_HPP

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

#include "../../../../Common/Handle.hpp"
#include "../Defs/IRenderRegion.hpp"

#include <cstddef>
#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::Viewing {
  // Class:      IRenderingService
  // Purpose:    Defines a service interface to render images to a screen-displayable format. Note:
  //             right now, only one format (RGB32) is supported.
  // Parameters: None.
  class IRenderingService {
  public:
    virtual ~IRenderingService() = default;

    // Function:   createStaticRendering
    // Purpose:    Creates a static rendering of an entire image. This type of rendering is
    //             not memory-efficient: it simply renders all parts of the image at full or
    //             fractional resolution. It is most useful when browsing the image is not
    //             required.
    // Parameters: imageHandle - The handle to the image to render.
    // Returns:    A handle to the produced rendering.
    virtual Common::Handle
    createStaticRendering(Common::Handle imageHandle) = 0;

    // Function:   getRegion
    // Purpose:    Gets an accessor to the render data for a given region. The accessor
    //             suggests a tiled format for the data; so that it is possible to dynamically
    //             render only portions thereof as needed.
    // Parameters: renderHandle - The handle to the rendering to get the region iterator for.
    //             x1, y1, x2, y2 - The rectangular region in question.
    // Returns:    The region accessor.
    virtual std::shared_ptr<Defs::IRenderRegion>
    getRegion(
      Common::Handle renderHandle,
      std::size_t x1,
      std::size_t y1,
      std::size_t x2,
      std::size_t y2
    ) = 0;

    // Function:         deleteRendering
    // Purpose:          Deletes a rendering from the rendering service.
    // Parameters:       renderHandle - The handle of the rendering to delete.
    // Returns:          None.
    // Throws (non-bug): RenderingNotFoundException
    virtual void
    deleteRendering(Common::Handle renderHandle) = 0;
  };
}

#endif
