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

#include "../Dimensions.hpp"

#include <boost/gil/image.hpp>

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Layer
  // Purpose:    Describes an image layer implemented using Boost.GIL.
  // Parameters: GilImageT - The Boost.GIL image type used for this layer. Must implement GIL's
  //                         RandomAccess2DImageConcept.
  template<class ... GilImageTs>
  class AnyLayer;

  template<class GilImageT>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Construct a layer of a specified size.
    // Parameters: widthPx - The layer width in pixels.
    //             heightPx - The layer height in pixels.
    //             initialColor - The color to fill this layer with.
    Layer(ImageMeasure widthPx,
          ImageMeasure heightPx,
          typename GilImageT::value_type initialColor
         );

    // Function:   getWidthPx
    // Purpose:    Get the layer's width in pixels.
    // Parameters: None.
    // Returns:    The layer's width in pixels.
    ImageMeasure
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Get the layer's height in pixels.
    // Parameters: None.
    // Returns:    The layer's height in pixels.
    ImageMeasure
    getHeightPx() const;

    // Function:   getPixelAt
    // Purpose:    Gets a pixel at a given coordinate.
    // Parameters: pos - The position to get the pixel from.
    typename GilImageT::view_t::value_type
    getPixelAt(ImagePoint pos) const;

    // Function:   getView
    // Purpose:    Gets a Boost.GIL view of a region of the image.
    // Parameters: rect - The rectangle to get the view for.
    typename GilImageT::view_t
    getView();

    typename GilImageT::const_view_t
    getView() const;

    typename GilImageT::view_t
    getView(ImageRect rect);

    typename GilImageT::const_view_t
    getView(ImageRect rect) const;
  public:
    // Function:   getMemorySize
    // Purpose:    Get the memory required for a single layer of the given width and height of this
    //             type.
    // Parameters: width - The desired width of the layer.
    //             height - The desired height of the layer.
    static std::size_t
    getMemorySize(ImageMeasure width,
                  ImageMeasure height
                 );
  private:
    template<class ... GilImageTs>
    friend class AnyLayer;

    Layer(const GilImageT &image);
    Layer(GilImageT &&image);

    GilImageT m_image;
  };
}

#include "Layer.tpp"

#endif
