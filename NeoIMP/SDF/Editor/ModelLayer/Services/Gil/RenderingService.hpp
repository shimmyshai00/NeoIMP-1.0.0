#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_RENDERINGSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_RENDERINGSERVICE_HPP

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

#include "../../../../Common/Data/IOwningCrudable.hpp"
#include "../../../../Common/Handle.hpp"
#include "../../../UILayer/AbstractModel/Viewing/IRenderingService.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../DomainObjects/Engine/Buffers/GridRendering.hpp"
#include "../../AbstractData/IImageRetriever.hpp"
#include <fruit/fruit.h>

#include <map>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      RenderingService
  // Purpose:    Implements the IRenderingService interface for the Boost.GIL framework.
  // Parameters: None.
  class RenderingService : public UILayer::AbstractModel::Viewing::IRenderingService {
  public:
    INJECT(RenderingService(
      AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *a_imageRepository,
      Common::Data::IOwningCrudable<Common::Handle, DomainObjects::Engine::Buffers::GridRendering>
        *a_renderingRepository
    ));

    Common::Handle
    createStaticRendering(Common::Handle a_imageHandle);

    std::shared_ptr<UILayer::AbstractModel::Defs::IRenderRegion>
    getRegion(
      Common::Handle a_renderHandle,
      std::size_t a_x1,
      std::size_t a_y1,
      std::size_t a_x2,
      std::size_t a_y2
    );

    void
    deleteRendering(Common::Handle a_renderHandle);
  private:
    AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *m_imageRepository;
    Common::Data::IOwningCrudable<Common::Handle, DomainObjects::Engine::Buffers::GridRendering> *
      m_renderingRepository;

    Common::Handle m_nextRenderingHandle;
  };
}

#endif
