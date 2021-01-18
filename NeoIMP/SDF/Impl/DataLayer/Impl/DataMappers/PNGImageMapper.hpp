#ifndef SDF_IMPL_DATALAYER_IMPL_DATAMAPPERS_PNGIMAGEMAPPER_HPP
#define SDF_IMPL_DATALAYER_IMPL_DATAMAPPERS_PNGIMAGEMAPPER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PNGImageMapper.hpp
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

#include <SDF/Impl/MemoryLayer/AbstractData/IImageDataMapper.hpp>
#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Image/AbstractImage.hpp>

#include <fruit/fruit.h>
#include <string>

namespace SDF::Impl::DataLayer::Impl::DataMappers {
  class PNGImageMapper : public MemoryLayer::AbstractData::IImageDataMapper {
  public:
    INJECT(PNGImageMapper());

    void saveImage(std::string fileSpec,
                   ModelLayer::Impl::DomainObjects::Image::AbstractImage *image
                  );
    std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage> loadImage(std::string fileSpec);
  };
}

#endif
