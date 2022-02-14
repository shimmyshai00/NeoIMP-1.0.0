#ifndef SDF_MODELLAYER_SERVICES_GIL_CREATEIMAGESERVICE_HPP
#define SDF_MODELLAYER_SERVICES_GIL_CREATEIMAGESERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CreateImageService.hpp
 * PURPOSE: Defines the CreateImageService class.
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

#include "../../../Common/Handle.hpp"
#include "../../../UILayer/AbstractModel/Defs/ImageSpec.hpp"
#include "../../../UILayer/AbstractModel/ICreateImageService.hpp"

#include "../../Repositories/IRepository.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"

#include <fruit/fruit.h>

namespace SDF::ModelLayer::Services::Gil {
  // Class:      CreateImageService
  // Purpose:    Implements the ICreateImageService interface for the Boost.GIL framework.
  // Parameters: None.
  class CreateImageService : public UILayer::AbstractModel::ICreateImageService {
  public:
    INJECT(CreateImageService(
      Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *imageRepository
    ));

    Common::Handle
    createImage(UILayer::AbstractModel::Defs::ImageSpec spec);
  private:
    Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *m_imageRepository;

    Common::Handle m_nextHandle;
  };
}

#endif
