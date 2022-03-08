#ifndef SDF_MODELLAYER_DOMAINOBJECTS_GIL_ANYLAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_GIL_ANYLAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AnyLayer.hpp
 * PURPOSE: Defines the AnyLayer template.
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

#include <boost/gil/extension/dynamic_image/any_image.hpp>
#include <boost/gil/extension/dynamic_image/any_image_view.hpp>
#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      AnyLayer
  // Purpose:    Defines a variant layer that can store a variety of image types.
  // Parameters: GilImageTs - The Boost.GIL image types going into the variant.
  template<class ... GilImageTs>
  class AnyLayer {
  public:
    // Function:   AnyLayer
    // Purpose:    Construct a new variant layer.
    // Parameters: layer - The specific layer to construct from.
    template<class GilImageT>
    AnyLayer(const Layer<GilImageT> &layer);

    template<class GilImageT>
    AnyLayer(Layer<GilImageT> &&layer);

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
    // Purpose:    Gets a view onto the layer data. Note that because of the limitations of
    //             boost:gil::any_image, it is impossible to get a sub-view here.
    // Parameters: None.
    // Returns:    A view to the given rectangle.
    typename boost::gil::any_image<GilImageTs...>::view_t
    getView();

    typename boost::gil::any_image<GilImageTs...>::const_view_t
    getView() const;
  public:
    ImageMeasure m_widthPx;
    ImageMeasure m_heightPx;

    boost::gil::any_image<GilImageTs...> m_data;
  };
}

#include "AnyLayer.tpp"

#endif
