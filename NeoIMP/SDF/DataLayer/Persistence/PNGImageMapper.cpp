/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PNGImageMapper.cpp
 * PURPOSE: Implements the PNGImageMapper class.
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

#include <ModelLayer/Services/AbstractDomain/IImageDataVisitor.hpp>

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <boost/gil/extension/io/png.hpp>

namespace SDF::DataLayer::Persistence {
  // Helper visitor class to save images.
  class PNGSaveVisitor : public ModelLayer::Services::AbstractDomain::IImageDataVisitor {
  public:
    PNGSaveVisitor(std::string fileSpec)
      : m_fileSpec(fileSpec)
    {}

    int
    getId() const {
      return -1; // not for outside use
    }

    void
    visitGilRegion(ModelLayer::Math::Rect<std::size_t> rect,
                   ModelLayer::Services::AbstractDomain::Defs::GilRegionType &gilRegion
                  )
    {
      printf("gil visit\n");
      boost::gil::write_view(m_fileSpec, gilRegion, boost::gil::png_tag{});
    }
  private:
    std::string m_fileSpec;
  };
}

namespace SDF::DataLayer::Persistence {
  PNGImageMapper::PNGImageMapper(std::string fileSpec)
    : m_fileSpec(fileSpec)
  {
  }

  void
  PNGImageMapper::persist(ModelLayer::Services::AbstractDomain::IImage *obj) {
    printf("P\n");
    PNGSaveVisitor saveVisitor(m_fileSpec);
    obj->acceptImageDataVisitor(0,
                                ModelLayer::Math::Rect<std::size_t>(0, 0, obj->getWidth()-1, obj->getHeight()-1),
                                saveVisitor
                               );
  }

  std::unique_ptr<ModelLayer::Services::AbstractDomain::IImage>
  PNGImageMapper::retrieve() {
    /*
    try {
      // NB: only kind of PNG format supported for now
      boost::gil::rgb8_image_t pngImage;
      boost::gil::read_image(fileSpec, pngImage, boost::gil::png_tag {});

      // NB: should name constant (image PPI default) somewhere / STUB for future import parameters specification
      return std::move(ModelLayer::Impl::DomainObjects::Image::Gil::createImage(fileSpec, 120.0f, pngImage));
    } catch(std::ios_base::failure &e) {
      throw DataLayer::Exceptions::BadFileException("PNG", "Must be 8-bit-per-channel RGB format only. No alpha channels supported.");
    }
    */
    return std::unique_ptr<ModelLayer::Services::AbstractDomain::IImage>(); // TBA
  }
}
