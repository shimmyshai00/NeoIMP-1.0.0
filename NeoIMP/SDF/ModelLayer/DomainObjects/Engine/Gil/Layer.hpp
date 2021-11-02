#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_LAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_LAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Layer.hpp
 * PURPOSE: Defines the Layer template.
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

#include "../../../Math/Rect.hpp"
#include "../../../Math/Coord.hpp"

#include <boost/gil/image.hpp>

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Layer
  // Purpose:    Describes an image layer implemented using Boost.GIL.
  // Parameters: GilImageT - The Boost.GIL image type used for this layer. Must implement GIL's
  //                         RandomAccess2DImageConcept.
  template<class GilImageT>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Construct a layer of a specified size.
    // Parameters: widthPx - The layer width in pixels.
    //             heightPx - The layer height in pixels.
    Layer(std::size_t widthPx,
          std::size_t heightPx
         );

    // Function:   getWidthPx
    // Purpose:    Get the layer's width in pixels.
    // Parameters: None.
    // Returns:    The layer's width in pixels.
    std::size_t
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Get the layer's height in pixels.
    // Parameters: None.
    // Returns:    The layer's height in pixels.
    std::size_t
    getHeightPx() const;

    // Function:   getPixelAt
    // Purpose:    Gets a pixel at a given coordinate.
    // Parameters: pos - The position to get the pixel from.
    //             x - The x-coordinate to get the pixel from.
    //             y - The y-coordinate to get the pixel from.
    GilImageT::view_t::value_t
    getPixelAt(Math::Coord<std::size_t> pos) const;

    GilImageT::view_t::value_t
    getPixelAt(std::size_t x,
               std::size_t y
              ) const;

    // Function:   getView
    // Purpose:    Gets a Boost.GIL view of a region of the image.
    // Parameters: rect - The rectangle to get the view for.
    //             x1 - The upper-left x-coordinate of the rectangle.
    //             y1 - The upper-left y-coordinate of the rectangle.
    //             x2 - The lower-right x-coordinate of the rectangle.
    //             y2 - The lower-right y-coordinate of the rectangle.
    GilImageT::view_t
    getView();

    GilImageT::const_view_t
    getView() const;

    GilImageT::view_t
    getView(Math::Rect<std::size_t> rect);

    GilImageT::const_view_t
    getView(Math::Rect<std::size_t> rect) const;

    GilImageT::view_t
    getView(std::size_t x1,
            std::size_t y1,
            std::size_t x2,
            std::size_t y2
           );

    GilImageT::const_view_t
    getView(std::size_t x1,
            std::size_t y1,
            std::size_t x2,
            std::size_t y2
           ) const;
  private:
    GilImageT m_image;
  };
}

#include "Layer.tpp"

#endif