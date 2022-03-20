/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CellRender.cpp
 * PURPOSE: Implements the CellRender algorithm.
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

#include "CellRender.hpp"

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/image_view.hpp>
#include <boost/gil/rgb.hpp>

#include <cstdio>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Impl {
  // The actual renderer implementations.
  template<>
  void renderOntoCell<boost::gil::rgb8_view_t>(
    Engine::Buffers::RenderCell *dstCell,
    Math::Rect<std::size_t> dstRect,
    const boost::gil::rgb8_view_t &view
  ) {
    printf("view rect: %ld %ld\n", view.width(), view.height());
    printf("dst rect: %lu %lu\n", dstRect.getWidth(), dstRect.getHeight());

    // Render the entirety of rectangle view into the destination rectangle dstRect. This is
    // designed to scale the rectangle appropriately. There is no compositing here; typically a
    // pure RGB layer (no alpha) is a background layer. Hence we first simply establish a linear
    // map between the rectangles in m_destRect and src: in particular, since we are tracing on
    // m_destRect, we want the *reverse* mapping going from m_destRect back to src, not from src
    // to m_destRect.
    unsigned char *outOriginPtr = dstCell->getOrigin();
    std::size_t outRowStride = dstCell->getRowStride();
    std::size_t outPixelWidth = dstCell->getPixelWidth();
    ERenderPixelFormat outPixelFormat = dstCell->getPixelFormat();

    // NB: this is a ROUGH DRAFT implementation - we need to likely add some color space mapping
    // here in a more mature program
    unsigned char *outYPtr = outOriginPtr +
      ((outRowStride * dstRect.y1()) + (outPixelWidth * dstRect.x1()));
    for(std::size_t y(dstRect.y1()); y < dstRect.y2(); ++y) {
      unsigned char *outXPtr = outYPtr;
      for(std::size_t x(dstRect.x1()); x < dstRect.x2(); ++x) {
        float inY = ((0.0f + y - dstRect.y1()) / dstRect.getHeight()) * view.height();
        float inX = ((0.0f + x - dstRect.x1()) / dstRect.getWidth()) * view.width();

        boost::gil::rgb8_view_t::y_coord_t viewY(floor(inY + 0.5f));
        boost::gil::rgb8_view_t::x_coord_t viewX(floor(inX + 0.5f));

        boost::gil::rgb8_pixel_t imagePixel(*view.xy_at(viewX, viewY));
        unsigned int pixelCode = 0xFF000000U
          ^ ((unsigned int)boost::gil::at_c<0>(imagePixel) << 16)
          ^ ((unsigned int)boost::gil::at_c<1>(imagePixel) <<  8)
          ^ ((unsigned int)boost::gil::at_c<2>(imagePixel)      );

        memcpy(outXPtr, &pixelCode, 4);

        outXPtr += outPixelWidth;
      }

      outYPtr += outRowStride;
    }

/*
    for(std::size_t y(0); y < 10; ++y) {
      for(std::size_t x(0); x < 10; ++x) {
        printf("pel: %08X\n", *(unsigned int *)(&outOriginPtr[outRowStride*y + outPixelWidth*x]));
      }
      printf("\n");
    }
    printf("\n");

    printf("---\n");

    for(std::size_t y(dstRect.y2() - 10); y < dstRect.y2(); ++y) {
      for(std::size_t x(dstRect.x2() - 10); x < dstRect.x2(); ++x) {
        printf("pel: %08X\n", *(unsigned int *)(&outOriginPtr[outRowStride*y + outPixelWidth*x]));
      }
      printf("\n");
    }
    printf("\n");

    printf("RAW cell writing %lu x %lu...\n", dstRect.getWidth(), dstRect.getHeight());

    FILE *fd = fopen("render.raw", "wb");
    fwrite(outOriginPtr, outPixelWidth, dstRect.getWidth()*dstRect.getHeight(), fd);
    fclose(fd);

    printf("done!\n");
*/
  }
}
