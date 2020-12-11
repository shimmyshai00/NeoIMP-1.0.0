#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_IMAGERENDERINGSERVICE_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_IMAGERENDERINGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRenderingService.hpp
 * PURPOSE: Headers for the UI image rendering service implementation.
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

#include <SDF/Impl/ModelLayer/Services/IImageRenderingService.hpp>

#include <fruit/fruit.h>

#include <vector>
#include <memory>

namespace SDF::Impl {
  namespace MemoryLayer {
    class IImageRepository;
  }

  namespace ModelLayer::Services::Impl {
    namespace DomainObjects::Algorithms::DisplayGenerator {
      class Visitor;
    }

    class ImageRenderingService : public IImageRenderingService {
    public:
      INJECT(ImageRenderingService(MemoryLayer::IImageRepository *imageRepository));

      const std::vector<unsigned int> &renderImageRegion(Handle handle, int x1, int y1, int x2, int y2);
    private:
      MemoryLayer::IImageRepository *m_imageRepository;

      std::unique_ptr<DomainObjects::Algorithms::DisplayGenerator::Visitor> m_visitor;
    };
  }
}

#endif
