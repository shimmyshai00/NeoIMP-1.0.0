#ifndef SDF_IMPL_MEMORYLAYER_IIMAGEREPOSITORY_HPP
#define SDF_IMPL_MEMORYLAYER_IIMAGEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageRepository.hpp
 * PURPOSE: Definition of the image repository interface for the memory layer.
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

#include <SDF/Impl/MemoryLayer/IImageRepositoryAccessor.hpp>
#include <SDF/Impl/ModelLayer/Handle.hpp>

#include <string>
#include <memory>

namespace SDF::Impl {
  namespace ModelLayer::Services::Impl::DomainObjects::Image {
    class ImageVariant;
  }

  namespace MemoryLayer {
    class IImageRepository : public IImageRepositoryAccessor {
    public:
      virtual ~IImageRepository() = default;

      virtual ModelLayer::Handle addNewImage(
        std::string uri, std::unique_ptr<ModelLayer::Services::Impl::DomainObjects::Image::ImageVariant> image
      ) = 0;
      virtual void persistImage(ModelLayer::Handle handle) = 0;

      virtual ModelLayer::Services::Impl::DomainObjects::Image::ImageVariant *access(ModelLayer::Handle handle) = 0;
    };
  }
}

#endif
