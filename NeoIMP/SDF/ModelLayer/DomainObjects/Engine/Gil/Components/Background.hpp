#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_BACKGROUND_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_BACKGROUND_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Background.hpp
 * PURPOSE: Defines the Background template.
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

#include "../../Components/IContent.hpp"
#include "../../Dimensions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Components {
  // Class:      Background
  // Purpose:    Defines a background content raster for the Boost.GIL-based engine implementation.
  // Parameters: GilImplT - The traits struct for this implementation.
  template<class GilImplT>
  class Background : public Engine::Components::IContent<GilImplT> {
  public:
    // Function:   Background
    // Purpose:    Create a fresh background raster.
    // Parameters: widthPx - The width in pixels.
    //             heightPx - The height in pixels.
    //             initialColor - The initial color to make the background.
    Background(ImageMeasure widthPx,
               ImageMeasure heightPx,
               typename GilImplT::pixel_t initialColor
              );

    Engine::Components::EContentType
    getType() const;

    ImageRect
    getIntrinsicRect() const;

    // Function:   getView
    // Purpose:    Gets a view onto the raster data.
    // Parameters: rect - The rectangle to get the view into.
    // Returns:    A view into all or part of the data.
    typename GilImplT::view_t
    getView();

    typename GilImplT::view_t::const_t
    getView() const;

    typename GilImplT::view_t
    getView(ImageRect rect);

    typename GilImplT::view_t::const_t
    getView(ImageRect rect) const;
  private:
    typename GilImplT::image_t m_data;
  };
}

#include "Background.tpp"

#endif
