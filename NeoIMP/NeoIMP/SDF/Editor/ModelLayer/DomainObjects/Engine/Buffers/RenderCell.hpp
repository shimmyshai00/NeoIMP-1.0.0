#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_BUFFERS_RENDERCELL_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_BUFFERS_RENDERCELL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderCell.hpp
 * PURPOSE: Defines the RenderCell class.
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

#include "../ERenderPixelFormat.hpp"

#include <cstddef>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Buffers {
  // Class:      RenderCell
  // Purpose:    Defines a single cell or tile of a multi-tile rendering. This format is used to
  //             break up large renderings so that other parts of the program can handle them, as
  //             well as to permit rendering only part of an image to save memory.
  // Parameters: None.
  class RenderCell {
  public:
    // Function:   RenderCell
    // Purpose:    Create a new render cell.
    // Parameters: width - The width in pixels.
    //             height - The height of the cell in pixels.
    //             pixelFormat - The pixel format the cell is presumed to carry.
    RenderCell(std::size_t width, std::size_t height, ERenderPixelFormat pixelFormat);

    ~RenderCell();

    // Function:   getWidth
    // Purpose:    Get the width of this render cell. Note: since this is a low level buffer class,
    //             we use std::size_t here, not ImageMeasure.
    // Parameters: None.
    // Returns:    The width of the render cell in pixels.
    std::size_t
    getWidth() const;

    // Function:   getHeight
    // Purpose:    Get the height of this render cell.
    // Parameters: None.
    // Returns:    The height of the render cell in pixels.
    std::size_t
    getHeight() const;

    // Function:   getPixelFormat
    // Purpose:    Get the pixel format of this render cell.
    // Parameters: None.
    // Returns:    The pixel format.
    ERenderPixelFormat
    getPixelFormat() const;

    // Function:   getOrigin
    // Purpose:    Get the pointer to the origin corner (upper-left corner) of this cell's data.
    // Parameters: None.
    // Returns:    The origin pointer.
    unsigned char *
    getOrigin();

    // Function:   getRowStride
    // Purpose:    Get the step, in *bytes*, required to push a data pointer to the next row of the
    //             cell.
    // Parameters: None.
    // Returns:    The required step amount.
    std::ptrdiff_t
    getRowStride() const;

    // Function:   getPixelWidth
    // Purpose:    Get the width of a pixel in bytes.
    // Parameters: None.
    // Returns:    The pixel width in bytes.
    std::size_t
    getPixelWidth() const;
  private:
    std::size_t m_width;
    std::size_t m_height;

    ERenderPixelFormat m_pixelFormat;

    unsigned char *m_data;
  };
}

#endif
