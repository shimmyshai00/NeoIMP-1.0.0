#ifndef SDF_IMPL_MODELLAYER_ABSTRACTDATA_IIMAGEREPOSITORY_HPP
#define SDF_IMPL_MODELLAYER_ABSTRACTDATA_IIMAGEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageRepository.hpp
 * PURPOSE: The interface for the data layer image repository.
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Image/AbstractImage.hpp>

#include <string>
#include <memory>

namespace SDF::Impl::ModelLayer::AbstractData {
  class IImageRepository {
  public:
    virtual ~IImageRepository() = default;

    // Similar to the usual "CRUD" type methods for repository access. Note: for efficiency reasons, we do not want to
    // just return copies, so we presume ownership of the image object to the repository.
    virtual void addImage(Handle handle, std::unique_ptr<Impl::DomainObjects::Image::AbstractImage> &image) = 0;
    virtual Impl::DomainObjects::Image::AbstractImage &accessImage(Handle handle) = 0;
    virtual void removeImage(Handle handle) = 0;
  };
}

#endif
