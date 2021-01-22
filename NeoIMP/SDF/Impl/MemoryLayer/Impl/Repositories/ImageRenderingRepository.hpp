#ifndef SDF_IMPL_MEMORYLAYER_IMPL_REPOSITORIES_IMAGERENDERINGREPOSITORY_HPP
#define SDF_IMPL_MEMORYLAYER_IMPL_REPOSITORIES_IMAGERENDERINGREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRenderingRepository.hpp
 * PURPOSE: Implementation of the image rendering repository.
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

#include <SDF/Impl/ModelLayer/AbstractMemory/Repositories/IImageRenderingRepository.hpp>
#include <SDF/Impl/ModelLayer/AbstractMemory/Handle.hpp>

#include <fruit/fruit.h>

#include <map>
#include <memory>

namespace SDF::Impl {
  namespace ModelLayer::Impl::DomainObjects::Rendering {
    class AbstractImageRendering;
  }

  namespace MemoryLayer {
    namespace Impl::Repositories {
      class ImageRenderingRepository : public ModelLayer::AbstractMemory::Repositories::IImageRenderingRepository {
      public:
        INJECT(ImageRenderingRepository());
        ~ImageRenderingRepository();

        void add(ModelLayer::AbstractMemory::Handle handle,
                 std::unique_ptr<ModelLayer::Impl::DomainObjects::Rendering::AbstractImageRendering> imageRendering
                );

        ModelLayer::Impl::DomainObjects::Rendering::AbstractImageRendering &access(ModelLayer::AbstractMemory::Handle handle);
        void remove(ModelLayer::AbstractMemory::Handle handle);
      private:
        std::map<ModelLayer::AbstractMemory::Handle,
                 std::unique_ptr<ModelLayer::Impl::DomainObjects::Rendering::AbstractImageRendering>
                > m_imageRenderingMap;
      };
    }
  }
}

#endif
