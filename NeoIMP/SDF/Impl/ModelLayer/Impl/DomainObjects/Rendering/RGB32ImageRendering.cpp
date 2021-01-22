/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB32ImageRendering.cpp
 * PURPOSE: Defines an RGB32-format image rendering buffer.
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

#include <RGB32ImageRendering.hpp>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Rendering {
  RGB32ImageRendering::RGB32ImageRendering(std::size_t width, std::size_t height)
    : m_renderingWidthPx(width),
      m_renderingHeightPx(height)
  {}

  std::size_t RGB32ImageRendering::getRenderingWidthPx() {
    return m_renderingWidthPx;
  }

  std::size_t RGB32ImageRendering::getRenderingHeightPx() {
    return m_renderingHeightPx;
  }

  void RGB32ImageRendering::accessRenderingData(const unsigned char *&origin,
                                                std::ptrdiff_t rowStride,
                                                Math::Rect<std::size_t> region
                                               )
  {
    origin = &m_dataBuffer[0] + (4*(region.getY1()*m_renderingWidthPx + region.getX1()));
    rowStride = 4*region.getWidth();
  }
}
