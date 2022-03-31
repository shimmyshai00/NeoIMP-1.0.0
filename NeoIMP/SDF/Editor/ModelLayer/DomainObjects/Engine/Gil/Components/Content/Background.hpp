#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_CONTENT_BACKGROUND_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_CONTENT_BACKGROUND_HPP

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

#include "../../../Image/Components/AContent.hpp"
#include "../../../Dimensions.hpp"

#include <cstddef>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Components::Content {
  // Class:      Background
  // Purpose:    Implements the background component for the Boost.GIL-based engine.
  // Parameters: GilSpecT - The implementation traits type.
  template<class GilSpecT>
  class Background : public Engine::Image::Components::AContent<GilSpecT> {
  public:
    // Function:   Background
    // Purpose:    Construct a new background content component.
    // Parameters: widthPx - The width of the raster in pixels.
    //             heightPx - The height of the raster in pixels.
    //             bkgColor - The initial background color.
    Background(std::size_t widthPx, std::size_t heightPx, typename GilSpecT::bkg_pixel_t bkgColor);

    ImageMeasure
    getWidthPx() const;

    ImageMeasure
    getHeightPx() const;

    ImageRect
    getDimensionsRect() const;

    void
    accept(typename GilSpecT::content_visitor_t &visitor);

    void
    accept(typename GilSpecT::content_visitor_t &visitor) const;

    // Function:   getView
    // Purpose:    Gets a view onto the image data.
    // Parameters: rect - The rectangle to get.
    // Returns:    None.
    typename GilSpecT::bkg_view_t
    getView();

    typename GilSpecT::bkg_view_t::const_t
    getView() const;

    typename GilSpecT::bkg_view_t
    getView(ImageRect rect);

    typename GilSpecT::bkg_view_t::const_t
    getView(ImageRect rect) const;
  private:
    typename GilSpecT::bkg_image_t m_data;
  };
}

#include "Background.tpp"

#endif
