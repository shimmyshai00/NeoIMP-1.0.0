#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_RENDERING_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_RENDERING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Rendering.hpp
 * PURPOSE: Defines the Rendering class.
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

#include "ERenderPixelFormat.hpp"

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      Rendering
  // Purpose:    Stores data for a rendered image. Note right now we implement only the RGB32
  //             format. To be expanded later with other formats. This is essentially a super
  //             simple, SINGLE raster layer image format that doesn't permit any manipulations
  //             beyond direct raw data access.

  // Parameters: None.
  class Rendering {
  public:
    // Function:   Rendering
    // Purpose:    Construct to specified attributes (width, height, and pixel format).
    // Parameters: width - The width of the rendering buffer in pixels.
    //             height - The height of the rendering buffer in pixels.
    //             pixFmt - The pixel format for this rendering buffer.
    Rendering(std::size_t width,
              std::size_t height,
              ERenderPixelFormat pixFmt
             );

    ~Rendering();

    // Function:   getWidth
    // Purpose:    Get the width of the rendering in pixels.
    // Parameters: None.
    // Returns:    The width in pixels.
    std::size_t
    getWidth() const;

    // Function:   getHeight
    // Purpose:    Get the height of the rendering in pixels.
    // Parameters: None.
    // Returns:    The height in pixels.
    std::size_t
    getHeight() const;

    // Function:   getPixelFormat
    // Purpose:    Get the pixel format of this rendering.
    // Parameters: None.
    // Returns:    The used pixel format.
    ERenderPixelFormat
    getPixelFormat() const;

    // Function:   getOrigin
    // Purpose:    Get the origin pointer to the raw data contained inside.
    // Parameters: None.
    // Returns:    The origin pointer.
    unsigned char *
    getOrigin();

    // Function:   getRowStride
    // Purpose:    Get the size of the row stride for this rendering.
    // Parameters: None.
    // Returns:    The row stride in bytes.
    std::size_t
    getRowStride();

    // Function:   getPixelWidth
    // Purpose:    Gets the size of a single pixel in bytes.
    // Parameters: None.
    // Returns:    The width of a pixel in bytes.
    std::size_t
    getPixelWidth();
  private:
    std::size_t m_width;
    std::size_t m_height;
    ERenderPixelFormat m_pixFmt;

    unsigned char *m_renderBuffer;
  };
}

#endif
