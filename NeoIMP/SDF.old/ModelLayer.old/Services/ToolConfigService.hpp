#ifndef SDF_MODELLAYER_SERVICES_TOOLCONFIGSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_TOOLCONFIGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolConfigService.hpp
 * PURPOSE: Defines the ToolConfigService class.
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

#include <SDF/Interfaces/IMessageSubscriber.hpp>
#include <SDF/Interfaces/IMessageBroker.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/ITool.hpp>
#include <SDF/ModelLayer/Services/Events/RepositoryUpdates.hpp>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IRepository;
  }

  namespace Services {
    // Class:      ToolConfigService
    // Purpose:    Provide a common base template for tool configuration services to hold initialization boilerplate.
    // Parameters: ToolT - The type of tool configured.
    template<class ToolT>
    class ToolConfigService : private Interfaces::IMessageSubscriber<Events::RepositoryUpdate<AbstractDomain::ITool>> {
    public:
      ToolConfigService(AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
                        Interfaces::IMessageBroker<Events::RepositoryUpdate<AbstractDomain::ITool>> *broker,
                        int subscriberUid
                       );
      ~ToolConfigService();
    protected:
      ToolT *m_tool;

      void
      toolUpdated();
    private:
      int m_subscriberUid;

      AbstractData::IRepository<AbstractDomain::ITool> *m_toolRepository;
      Interfaces::IMessageBroker<Events::RepositoryUpdate<AbstractDomain::ITool>> *m_broker;

      int
      getUid() const;

      void
      receiveMessage(std::shared_ptr<Events::RepositoryUpdate<AbstractDomain::ITool>> message);

      void
      handleCreateMessage(Events::Created<AbstractDomain::ITool> *message);
    };
  }
}

#include "ToolConfigService.tpp"

#endif
