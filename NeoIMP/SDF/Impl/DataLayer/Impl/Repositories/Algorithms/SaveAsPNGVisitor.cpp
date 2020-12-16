/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveAsPNGVisitor.cpp
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

#include <SaveAsPNGVisitor.hpp>

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <boost/gil/extension/io/png.hpp>

namespace SDF::Impl::DataLayer::Impl::Repositories::Algorithms {
  template<class ViewType>
  void saveRegion(std::string pngFileName, ViewType regionView) {
    boost::gil::write_view(pngFileName, regionView, boost::gil::png_tag());
  }
}

namespace SDF::Impl::DataLayer::Impl::Repositories::Algorithms {
  SaveAsPNGVisitor::SaveAsPNGVisitor(std::string pngFileName)
    : m_pngFileName(pngFileName)
  {}

  // Generic boilerplate.
  void SaveAsPNGVisitor::visitGilRegion(boost::gil::gray8_view_t regionView) {
    saveRegion(m_pngFileName, regionView);
  }

  void SaveAsPNGVisitor::visitGilRegion(boost::gil::gray16_view_t regionView) {
    saveRegion(m_pngFileName, regionView);
  }

  void SaveAsPNGVisitor::visitGilRegion(boost::gil::rgb8_view_t regionView) {
    saveRegion(m_pngFileName, regionView);
  }

  void SaveAsPNGVisitor::visitGilRegion(boost::gil::rgb16_view_t regionView) {
    saveRegion(m_pngFileName, regionView);
  }

  void SaveAsPNGVisitor::visitGilRegion(boost::gil::cmyk8_view_t regionView) {
    throw DataLayer::Exceptions::ColorModelNotSupportedException("CMYK");
  }

  void SaveAsPNGVisitor::visitGilRegion(boost::gil::cmyk16_view_t regionView) {
    throw DataLayer::Exceptions::ColorModelNotSupportedException("CMYK");
  }
}
