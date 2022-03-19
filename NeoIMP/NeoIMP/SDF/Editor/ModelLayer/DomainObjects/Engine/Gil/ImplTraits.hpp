#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMPLTRAITS_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMPLTRAITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImplTraits.hpp
 * PURPOSE: Defines traits for each implemented image type in the Boost.GIL-based engine.
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

#include "Components/Content/Background.hpp"
#include "Components/Visitor.hpp"

#include <boost/gil/pixel.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil {
  struct RGB24_888_Image_Impl {
    // These types are for internal convenience
    typedef boost::gil::rgb8_image_t bkg_image_t;
    typedef boost::gil::rgb8_view_t bkg_view_t;
    typedef boost::gil::rgb8_pixel_t bkg_pixel_t;

    typedef boost::gil::rgba8_image_t image_t;
    typedef boost::gil::rgba8_view_t view_t;
    typedef boost::gil::rgba8_pixel_t pixel_t;

    // These types must be defined in every image implementation traits class.
    typedef Components::Content::Background<RGB24_888_Image_Impl> background_content_component_t;

    typedef Components::Visitor<RGB24_888_Image_Impl> component_visitor_t;
    typedef Components::ConstVisitor<RGB24_888_Image_Impl> const_component_visitor_t;
  };
}

#endif
