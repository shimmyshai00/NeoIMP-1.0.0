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
#include "../../../../Common/MessageSystem/IMessageDispatcher.hpp"
#include "../../../../Common/Handle.hpp"
#include "../../../../Common/IUUIDable.hpp"
#include "../../../../Common/IValidator.hpp"

#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../AbstractData/IImageRetainer.hpp"

#include "../Messages/ObjectChanges.hpp"

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
      AbstractData::IImageRetainer<DomainObjects::Engine::Gil::Any_Image> *a_imageStore,
      Common::MessageSystem::IMessageDispatcher<Messages::ImageAdded> *
        a_imageAddedMessageDispatcher
    ));

    boost::uuids::uuid
    getUuid() const;

    std::size_t
    getMemoryRequiredForOneLayer(const UILayer::AbstractModel::Defs::ImageSpec &a_spec) const;

    Common::Handle
    createFromSpec(const UILayer::AbstractModel::Defs::ImageSpec &a_spec);
  private:
    boost::uuids::uuid m_uuid;

    AbstractData::IImageRetainer<DomainObjects::Engine::Gil::Any_Image> *m_imageStore;
    Common::MessageSystem::IMessageDispatcher<Messages::ImageAdded> *m_imageAddedMessageDispatcher;

    std::size_t m_nextNewDocumentNumber;

    template<class GilSpecT>
    std::unique_ptr<DomainObjects::Engine::Gil::Any_Image>
    doConstructFromSpec(const UILayer::AbstractModel::Defs::ImageSpec &a_spec);
  };
}

#endif
