/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderCell.cpp
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

#include "RenderCell.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Buffers {
  RenderCell::RenderCell(std::size_t width, std::size_t height, ERenderPixelFormat pixelFormat)
    : m_width(width),
      m_height(height),
      m_pixelFormat(pixelFormat),
      m_data(nullptr)
  {
    // TBA: check to make sure someone didn't pass RENDERFMT_MAX for a pixel format, and throw if
    //      they did

    m_data = new unsigned char[getPixelWidth()*m_width*m_height];
  }

  RenderCell::~RenderCell() {
    delete[] m_data;
  }

  // Function:   getWidth
  // Purpose:    Get the width of this render cell.
  // Parameters: None.
  // Returns:    The width of the render cell in pixels.
  std::size_t
  RenderCell::getWidth() const {
    return m_width;
  }

  // Function:   getHeight
  // Purpose:    Get the height of this render cell.
  // Parameters: None.
  // Returns:    The height of the render cell in pixels.
  std::size_t
  RenderCell::getHeight() const {
    return m_height;
  }

  // Function:   getPixelFormat
  // Purpose:    Get the pixel format of this render cell.
  // Parameters: None.
  // Returns:    The pixel format.
  ERenderPixelFormat
  RenderCell::getPixelFormat() const {
    return m_pixelFormat;
  }

  // Function:   getOrigin
  // Purpose:    Get the pointer to the origin corner (upper-left corner) of this cell's data.
  // Parameters: None.
  // Returns:    The origin pointer.
  unsigned char *
  RenderCell::getOrigin() {
    return m_data;
  }

  // Function:   getRowStride
  // Purpose:    Get the step, in *bytes*, required to push a data pointer to the next row of the
  //             cell.
  // Parameters: None.
  // Returns:    The required step amount.
  std::ptrdiff_t
  RenderCell::getRowStride() const {
    return getPixelWidth()*m_width;
  }

  // Function:   getPixelWidth
  // Purpose:    Get the width of a pixel in bytes.
  // Parameters: None.
  // Returns:    The pixel width in bytes.
  std::size_t
  RenderCell::getPixelWidth() const {
    return g_pixelFormatWidths[m_pixelFormat];
  }
}
