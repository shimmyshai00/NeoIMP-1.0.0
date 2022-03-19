#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_CREATEIMAGESERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_CREATEIMAGESERVICE_HPP

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

#include "../../../UILayer/AbstractModel/Create/IGetMemoryRequirementsService.hpp"
#include "../../../UILayer/AbstractModel/Create/ICreateDocumentService.hpp"
#include "../../../UILayer/AbstractModel/Defs/ImageSpec.hpp"
#include "../../../../Common/MessageSystem/IChannel.hpp"
#include "../../../../Common/Handle.hpp"
#include "../../../../Common/IUUIDable.hpp"

#include "../../AbstractData/IImageRepository.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"

#include "../Messages/Object.hpp"

#include <boost/uuid/uuid.hpp>
#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      CreateImageService
  // Purpose:    Implements the ICreateImageService interface for the Boost.GIL framework.
  // Parameters: None.
  class CreateImageService : public UILayer::AbstractModel::Create::IGetMemoryRequirementsService,
                             public UILayer::AbstractModel::Create::ICreateDocumentService,
                             public Common::IUUIDable
  {
  public:
    INJECT(CreateImageService(
      AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *imageRepository,
      Common::MessageSystem::IChannel<Messages::ImageAdded> *imageAddedMessageChannel
    ));

    boost::uuids::uuid
    getUuid() const;

    std::size_t
    getMemoryRequiredForOneLayer(const UILayer::AbstractModel::Defs::ImageSpec &spec) const;

    Common::Handle
    createFromSpec(const UILayer::AbstractModel::Defs::ImageSpec &spec);
  private:
    boost::uuids::uuid m_uuid;

    AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *m_imageRepository;
    Common::MessageSystem::IChannel<Messages::ImageAdded> *m_imageAddedMessageChannel;

    Common::Handle m_nextHandle;
  };
}

#endif
