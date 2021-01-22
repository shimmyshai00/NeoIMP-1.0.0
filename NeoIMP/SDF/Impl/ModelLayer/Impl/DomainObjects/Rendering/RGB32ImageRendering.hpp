#ifndef SDF_IMPL_MODELLAYER_IMPL_DOMAINOBJECTS_RENDERING_RGB32IMAGERENDERING_HPP
#define SDF_IMPL_MODELLAYER_IMPL_DOMAINOBJECTS_RENDERING_RGB32IMAGERENDERING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB32ImageRendering.hpp
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Rendering/AbstractImageRendering.hpp>
#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Math/Coord.hpp>
#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Math/Rect.hpp>
#include <cstdlib>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Rendering {
  // nb: make template?
  class RGB32ImageRendering : public AbstractImageRendering {
  public:
    RGB32ImageRendering(std::size_t width, std::size_t height);

    std::size_t getRenderingWidthPx();
    std::size_t getRenderingHeightPx();

    // note: inlined for speed
    void setPixelAt(Math::Coord<std::size_t> pos, unsigned char r, unsigned char g, unsigned char b) {
      std::size_t bufferPos(4*(pos.getY()*m_renderingHeightPx + pos.getX()));

      m_dataBuffer[bufferPos+3] = 0xFF;
      m_dataBuffer[bufferPos+2] = r;
      m_dataBuffer[bufferPos+1] = g;
      m_dataBuffer[bufferPos  ] = b;
    }

    void accessRenderingData(const unsigned char *&origin,
                             std::ptrdiff_t rowStride,
                             Math::Rect<std::size_t> region
                            );
  private:
    std::size_t m_renderingWidthPx;
    std::size_t m_renderingHeightPx;

    std::vector<unsigned char> m_dataBuffer;
  };
}

#endif
