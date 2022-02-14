#ifndef SDF_MODELLAYER_SERVICES_GIL_RENDERINGSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_GIL_RENDERINGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderingService.hpp
 * PURPOSE: Defines the RenderingService class.
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

#include "../../../UILayer/AbstractModel/IRenderingService.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../DomainObjects/Engine/Rendering.hpp"
#include "../../Repositories/IRepository.hpp"
#include <fruit/fruit.h>

namespace SDF::ModelLayer::Services::Gil {
  // Class:      RenderingService
  // Purpose:    Implements the IRenderingService interface for the Boost.GIL framework.
  // Parameters: None.
  class RenderingService : public UILayer::AbstractModel::IRenderingService {
  public:
    INJECT(RenderingService(
      Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *imageRepository,
      Repositories::IRepository<DomainObjects::Engine::Rendering> *renderingRepository
    ));

    Defs::Handle
    renderImage(Defs::Handle imageHandle);

    Defs::Handle
    renderSubregion(Defs::Handle imageHandle,
                    std::size_t x1,
                    std::size_t y1,
                    std::size_t x2,
                    std::size_t y2
                   );

    void
    retrieveRenderData(Defs::Handle renderHandle,
                       unsigned char * &originPtr,
                       std::ptrdiff_t &rowStride,
                       std::size_t &pixelWidth
                     );
  private:
    Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *m_imageRepository;
    Repositories::IRepository<DomainObjects::Engine::Rendering> *m_renderingRepository;
  };
}

#endif