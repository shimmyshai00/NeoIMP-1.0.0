#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_RASTER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_RASTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Raster.hpp
 * PURPOSE: Defines the Raster template.
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
#include "../../Components/EContentType.hpp"
#include "../../Dimensions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Components {
  // Class:      Raster
  // Purpose:    Defines a content raster for the Boost.GIL-based engine implementation.
  // Parameters: GilImplT - The traits struct for this implementation.
  //             GilImageT - The image type to use.
  //             GilViewT - The view type to use.
  //             GilPixelT - The pixel type to use.
  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  class Raster : public Engine::Components::IContent<GilImplT> {
  public:
    // Function:   Raster
    // Purpose:    Create a fresh raster.
    // Parameters: widthPx - The width in pixels.
    //             heightPx - The height in pixels.
    //             initialColor - The initial color to make the raster.
    Raster(ImageMeasure widthPx,
           ImageMeasure heightPx,
           GilPixelT initialColor
          );

    Engine::Components::EContentType
    getType() const;

    ImageRect
    getIntrinsicRect() const;

    // Function:   getView
    // Purpose:    Gets a view onto the raster data.
    // Parameters: rect - The rectangle to get the view into.
    // Returns:    A view into all or part of the data.
    GilViewT
    getView();

    typename GilViewT::const_t
    getView() const;

    GilViewT
    getView(ImageRect rect);

    typename GilViewT::const_t
    getView(ImageRect rect) const;
  private:
    GilImageT m_data;
  };
}

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Components {
  // Convenience aliases.
  template<class GilImplT>
  using ForegroundRaster = Raster<
    GilImplT,
    typename GilImplT::image_t,
    typename GilImplT::view_t,
    typename GilImplT::pixel_t
  >;

  template<class GilImplT>
  using BackgroundRaster = Raster<
    GilImplT,
    typename GilImplT::bkg_image_t,
    typename GilImplT::bkg_view_t,
    typename GilImplT::bkg_pixel_t
  >;
}

#include "Raster.tpp"

#endif
