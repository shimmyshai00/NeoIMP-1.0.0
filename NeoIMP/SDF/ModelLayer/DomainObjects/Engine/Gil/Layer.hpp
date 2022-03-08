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

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Layer
  // Purpose:    Defines a single layer of an image.
  // Parameters: GilImageT - The underlying Boost.GIL image type.
  template<class GilImageT>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Construct a new layer.
    // Parameters: widthPx - The layer width in pixels.
    //             heightPx - The layer height in pixels.
    //             fillColor - The color to fill the layer with.
    Layer(ImageMeasure widthPx,
          ImageMeasure heightPx,
          typename GilImageT::value_type fillColor
         );

    // Function:   getWidthPx
    // Purpose:    Gets the layer width in pixels.
    // Parameters: None.
    // Returns:    The layer width in pixels.
    ImageMeasure
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Gets the layer height in pixels.
    // Parameters: None.
    // Returns:    The layer height in pixels.
    ImageMeasure
    getHeightPx() const;

    // Function:   getRect
    // Purpose:    Get the layer bounding rectangle.
    // Parameters: None.
    // Returns:    The bounding rectangle for this layer.
    ImageRect
    getRect() const;

    // Function:   getView
    // Purpose:    Gets a view onto the layer data.
    // Parameters: rect - The rectangle to get the view onto.
    // Returns:    A view to the given rectangle.
    typename GilImageT::view_t
    getView();

    typename GilImageT::const_view_t
    getView() const;

    typename GilImageT::view_t
    getView(ImageRect rect);

    typename GilImageT::const_view_t
    getView(ImageRect rect) const;
  public:
    template<class ... GilImageTs>
    friend class AnyLayer;

    ImageMeasure m_widthPx;
    ImageMeasure m_heightPx;

    GilImageT m_data;
  };
}

#include "Layer.tpp"

#endif
