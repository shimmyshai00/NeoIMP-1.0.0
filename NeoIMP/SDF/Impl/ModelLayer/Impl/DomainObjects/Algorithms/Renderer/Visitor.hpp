#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_ALGORITHMS_RENDERER_VISITOR_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_ALGORITHMS_RENDERER_VISITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Visitor.hpp
 * PURPOSE: An image processing algorithm to render images to a directly-accessible pixel buffer, such as for use in
 *          the UI layer, or for data mapping to output file formats taht do not support layered images or compositing.
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Image/ImageDataVisitor.hpp>

#include <vector>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Algorithms::Renderer {
  class Visitor : public Image::ImageDataVisitor {
  public:
    Visitor();

    // Access the rendering. For the format, see below. The visitor owns this data, so it should not be discarded
    // until one is done using it! Note, this will return a NULL pointer until a region has been rendered by visiting
    // an image.
    const unsigned char *getRenderData();

    // Visitation methods. For this algorithm, we have to process each pixel type separately, as each has its own
    // distinct conversion. We cannot just use a boost::gil::any_image_view.
    void visitGilRegion(boost::gil::gray8_view_t regionView);
    void visitGilRegion(boost::gil::gray16_view_t regionView);
    void visitGilRegion(boost::gil::rgb8_view_t regionView);
    void visitGilRegion(boost::gil::rgb16_view_t regionView);
    void visitGilRegion(boost::gil::cmyk8_view_t regionView);
    void visitGilRegion(boost::gil::cmyk16_view_t regionView);
  private:
    // Right now, the sole supported target render format is a conventional 24-bit RGB style format, similar to the
    // HTML Hex representation. (Namely, it is an ARGB32 format with the alpha always at 255.) THIS IS RESTRICTIVE,
    // because this program is designed to support greater color depths internally, and thus this prohibits the display
    // of such data with greater than 24-bit fidelity. The reason this author does not include better support here is
    // TESTING - this author does not have the money to purchase a monitor with a color depth surpassing 8 bits per
    // channel (24 bits total). Thus it would be impossible to debug properly. This is thus a large FIXME for any
    // potential future contributors who happen to have the relevant hardware.
    std::vector<unsigned char> m_renderBuffer;
  };
}

#endif
