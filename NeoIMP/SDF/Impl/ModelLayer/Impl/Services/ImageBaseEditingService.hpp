#ifndef SDF_IMPL_MODELLAYER_IMPL_SERVICES_IMAGEBASEEDITINGSERVICE_HPP
#define SDF_IMPL_MODELLAYER_IMPL_SERVICES_IMAGEBASEEDITINGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageBaseEditingService.hpp
 * PURPOSE: Headers for the implementation of the MVC base image editing service.
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

#include <SDF/Impl/UILayer/AbstractModel/Services/IImageBaseEditingService.hpp>

#include <SDF/Impl/ModelLayer/Handle.hpp>

#include <fruit/fruit.h>
#include <string>

namespace SDF::Impl::ModelLayer::Impl {
  namespace DomainObjects {
    namespace Meta {
      template<class T>
      class ObjectMap;
    }

    namespace Image {
      class AbstractImage;
    }
  }

  namespace Services {
    class ImageBaseEditingService : public UILayer::AbstractModel::Services::IImageBaseEditingService {
    public:
      INJECT(ImageBaseEditingService(DomainObjects::Meta::ObjectMap<DomainObjects::Image::AbstractImage> *imageMap));

      void setImageName(ModelLayer::Handle handle, std::string newImageName);
    private:
      DomainObjects::Meta::ObjectMap<DomainObjects::Image::AbstractImage> *m_imageMap;
    };
  }
}

#endif
