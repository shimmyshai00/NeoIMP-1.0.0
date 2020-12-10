#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_IMAGEDATAVISITOR_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_IMAGEDATAVISITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageDataVisitor.hpp
 * PURPOSE: The base class for visiting image data.
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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/Gil/Types.hpp>

#include <boost/gil/extension/dynamic_image/any_image_view.hpp>
#include <boost/gil/image_view.hpp>
#include <boost/gil.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image {
  // Note: This visitor interface, unfortunatealy, cannot entirely avoid leaking the implementation details because of
  //       the fact of incompatible pixel formats and the overhead of virtual function calls if they were done on a
  //       pixel-by-pixel basis, so we must provide visitation methods for different data implementations to permit
  //       direct access thereto.
  class ImageDataVisitor {
  public:
    virtual ~ImageDataVisitor() = 0;

    // Boost GIL-based visitation methods.
    void visitGilRegion(boost::gil::any_image_view<Gil::SupportedViewTypes> regionView) {}

    void visitGilRegion(boost::gil::image_view<boost::gil::gray8_view_t> regionView) {}
    void visitGilRegion(boost::gil::image_view<boost::gil::gray16_view_t> regionView) {}
    void visitGilRegion(boost::gil::image_view<boost::gil::rgb8_view_t> regionView) {}
    void visitGilRegion(boost::gil::image_view<boost::gil::rgb16_view_t> regionView) {}
    void visitGilRegion(boost::gil::image_view<boost::gil::cmyk8_view_t> regionView) {}
    void visitGilRegion(boost::gil::image_view<boost::gil::cmyk16_view_t> regionView) {}
  };
}

#endif
