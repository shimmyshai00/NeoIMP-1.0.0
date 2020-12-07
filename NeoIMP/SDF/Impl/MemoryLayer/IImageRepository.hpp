#ifndef SDF_IMPL_MEMORYLAYER_IIMAGEREPOSITORY_HPP
#define SDF_IMPL_MEMORYLAYER_IIMAGEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageRepository.hpp
 * PURPOSE: Definition of the image repository interface template for the memory layer.
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

#include <SDF/Impl/ModelLayer/Services/Impl/Repositories/IImageRepository.hpp>
#include <SDF/Impl/ModelLayer/Handle.hpp>

#include <string>

namespace SDF::Impl::MemoryLayer {
  template<class ImageType>
  class IImageRepository : public ModelLayer::Services::Impl::Repositories::IImageRepository<ImageType> {
  public:
    virtual ~IImageRepository() = default;

    virtual ModelLayer::Handle addNewImage(std::string uri, std::unique_ptr<ImageType> image) = 0;
    virtual void persistImage(ModelLayer::Handle handle) = 0;

    virtual ImageType *access(ModelLayer::Handle handle) = 0;
  };
}

#endif
