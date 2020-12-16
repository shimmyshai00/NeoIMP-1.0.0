#ifndef SDF_IMPL_DATALAYER_IMPL_REPOSITORIES_ALGORITHMS_SAVEASPNGVISITOR_HPP
#define SDF_IMPL_DATALAYER_IMPL_REPOSITORIES_ALGORITHMS_SAVEASPNGVISITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveAsPNGVisitor.hpp
 * PURPOSE: The visitor for saving an image in PNG format.
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

#include <boost/gil.hpp>

namespace SDF::Impl::DataLayer::Impl::Repositories::Algorithms {
  class SaveAsPNGVisitor : public ModelLayer::Impl::DomainObjects::Image::ImageDataVisitor {
  public:
    SaveAsPNGVisitor(std::string pngFileName);

    void visitGilRegion(boost::gil::gray8_view_t regionView);
    void visitGilRegion(boost::gil::gray16_view_t regionView);
    void visitGilRegion(boost::gil::rgb8_view_t regionView);
    void visitGilRegion(boost::gil::rgb16_view_t regionView);
    void visitGilRegion(boost::gil::cmyk8_view_t regionView);
    void visitGilRegion(boost::gil::cmyk16_view_t regionView);
  private:
    std::string m_pngFileName;
  };
}

#endif
