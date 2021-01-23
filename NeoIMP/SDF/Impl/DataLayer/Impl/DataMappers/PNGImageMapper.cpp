/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PNGImageMapper.cpp
 * PURPOSE: A data mapper for mapping out images to PNG files.
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

#include <PNGImageMapper.hpp>

#include <ModelLayer/Impl/DomainObjects/Image/ImageDataVisitor.hpp>
#include <ModelLayer/Impl/DomainObjects/Image/Gil/ImageFactory.hpp>

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <boost/gil/extension/io/png.hpp>

namespace SDF::Impl::DataLayer::Impl::DataMappers {
  // Helper visitor class to save images.
  class PNGSaveVisitor : public ModelLayer::Impl::DomainObjects::Image::ImageDataVisitor {
  public:
    PNGSaveVisitor(std::string fileSpec)
      : m_fileSpec(fileSpec)
    {}

    void
    visitGilRegion(boost::gil::gray8_view_t regionView) {
      // TBA
    }

    void
    visitGilRegion(boost::gil::gray16_view_t regionView) {
      // TBA
    }

    void
    visitGilRegion(boost::gil::rgb8_view_t regionView) {
      boost::gil::write_view(m_fileSpec, regionView, boost::gil::png_tag{});
    }

    void
    visitGilRegion(boost::gil::rgb16_view_t regionView) {
      boost::gil::write_view(m_fileSpec, regionView, boost::gil::png_tag{});
    }

    void
    visitGilRegion(boost::gil::cmyk8_view_t regionView) {
      // TBA
    }

    void
    visitGilRegion(boost::gil::cmyk16_view_t regionView) {
      // TBA
    }
  private:
    std::string m_fileSpec;
  };
}

namespace SDF::Impl::DataLayer::Impl::DataMappers {
  PNGImageMapper::PNGImageMapper() {}

  void
  PNGImageMapper::saveImage(std::string fileSpec,
                            ModelLayer::Impl::DomainObjects::Image::AbstractImage *image
                           )
  {
    PNGSaveVisitor saveVisitor(fileSpec);
    image->acceptLayerPixelVisitor(0, image->getImageRect(), &saveVisitor);
  }

  std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage>
  PNGImageMapper::loadImage(std::string fileSpec) {
    try {
      // NB: only PNG format supported for now
      boost::gil::rgb8_image_t pngImage;
      boost::gil::read_image(fileSpec, pngImage, boost::gil::png_tag {});

      // NB: should name constant (image PPI default) somewhere / STUB for future import parameters specification
      return std::move(ModelLayer::Impl::DomainObjects::Image::Gil::createImage(fileSpec, 120.0f, pngImage));
    } catch(std::ios_base::failure &e) {
      throw DataLayer::Exceptions::BadFileException("PNG", "Must be 8-bit-per-channel RGB format only. No alpha channels supported.");
    }
  }
}
