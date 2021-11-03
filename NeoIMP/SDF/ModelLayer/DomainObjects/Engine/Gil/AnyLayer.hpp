#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYLAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYLAYER_HPP

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

#include "../../../Math/Rect.hpp"
#include "../../../Math/Coord.hpp"

#include "Layer.hpp"

#include <boost/gil/extension/dynamic_image/dynamic_image_all.hpp>
#include <boost/gil/image.hpp>

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      AnyLayer
  // Purpose:    Describes an image layer variant implemented using Boost.GIL.
  // Parameters: GilImageTs - The Boost.GIL image types going into the variant.
  template<class ... GilImageTs>
  class AnyLayer {
  public:
    // Function:   AnyLayer
    // Purpose:    Construct a new variant from a particular concrete layer type.
    // Parameters: layer - The layer to construct to.
    //             doSwap - Whether to swap the image data or copy it.
    template<class T>
    AnyLayer(const Layer<T> &layer);

    template<class T>
    AnyLayer(Layer<T> &&layer);

    // Function:   specifize
    // Purpose:    Converts this variant back into a concrete layer type.
    // Parameters: doSwap - Whether to do the conversion by swap.
    //template<class T>
    //Layer<T> *specifize(bool doSwap);

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
  private:
    boost::gil::any_image<GilImageTs...> m_image;
  };
}

#include "AnyLayer.tpp"

#endif
