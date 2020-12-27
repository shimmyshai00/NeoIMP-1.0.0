#ifndef SDF_IMPL_MODELLAYER_IMPL_SERVICES_IMAGERENDERINGSERVICE_HPP
#define SDF_IMPL_MODELLAYER_IMPL_SERVICES_IMAGERENDERINGSERVICE_HPP

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

#include <SDF/Impl/UILayer/AbstractModel/Services/IImageRenderingService.hpp>

#include <fruit/fruit.h>

namespace SDF::Impl::ModelLayer {
  namespace AbstractData {
    class IImageRepository;
  }

  namespace Impl {
    namespace DomainObjects {
      namespace Image {
        class AbstractImage;
      }

      namespace Algorithms::Renderer {
        class Visitor;
      }
    }

    namespace Services {
      class ImageRenderingService : public UILayer::AbstractModel::Services::IImageRenderingService {
      public:
        INJECT(ImageRenderingService(AbstractData::IImageRepository *imageRepository));

        const unsigned char *renderImageRegion(Handle handle, int x1, int y1, int x2, int y2);
      private:
        AbstractData::IImageRepository *m_imageRepository;
        DomainObjects::Algorithms::Renderer::Visitor *m_visitor;
      };
    }
  }
}

#endif