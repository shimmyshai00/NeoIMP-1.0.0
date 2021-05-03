#ifndef SDF_MODELLAYER_SERVICES_TOOLBASEDEDITINGSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_TOOLBASEDEDITINGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolBasedEditingService.hpp
 * PURPOSE: Defines the ToolBasedEditingService class.
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

#include <SDF/Interfaces/IMessagePublisher.hpp>
#include <SDF/Interfaces/IMessageReceiver.hpp>
#include <SDF/Interfaces/IMessageBroker.hpp>
#include <SDF/Interfaces/IFactory.hpp>
#include <SDF/Interfaces/IEventHandler.hpp>

#include <SDF/UILayer/AbstractModel/IToolBasedEditingService.hpp>

#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>
#include <SDF/UILayer/AbstractModel/Events/ToolEvent.hpp>
#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <fruit/fruit.h>

#include <map>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class IImage;
      class ITool;
      class IDeltaEditor;
    }

    // Class:      ToolBasedEditingService
    // Purpose:    Performs image editing using editing tools.
    // Parameters: None.
    class ToolBasedEditingService : public UILayer::AbstractModel::IToolBasedEditingService,
                                    private Interfaces::IMessagePublisher<AbstractDomain::Defs::ImageChange>,
                                    private Interfaces::IMessageReceiver<AbstractDomain::Defs::ImageChange>
    {
    public:
      INJECT(ToolBasedEditingService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                     AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
                                     AbstractData::IRepository<AbstractDomain::IDeltaEditor> *deltaEditorRepository,
                                     Interfaces::IFactory<AbstractDomain::ITool,
                                                          UILayer::AbstractModel::Properties::Tool
                                                         > *toolFactory
                                    ));

      int
      getUid() const;

      void
      attachObserver(Interfaces::IEventHandler<UILayer::AbstractModel::Events::ToolEvent> *observer);

      void
      removeObserver(Interfaces::IEventHandler<UILayer::AbstractModel::Events::ToolEvent> *observer);

      void
      setBroker(Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *broker);

      UILayer::AbstractModel::Properties::Tool
      getActiveTool() const;

      void
      setActiveTool(UILayer::AbstractModel::Properties::Tool tool);

      void
      beginToolApplication(UILayer::AbstractModel::Handle handle);

      void
      applyToolAtPoint(float x, float y);

      void
      finishToolApplication();
    private:
      AbstractData::IRepository<AbstractDomain::IImage> *m_imageRepository;
      AbstractData::IRepository<AbstractDomain::ITool> *m_toolRepository;
      AbstractData::IRepository<AbstractDomain::IDeltaEditor> *m_deltaEditorRepository;

      std::vector<Interfaces::IEventHandler<UILayer::AbstractModel::Events::ToolEvent> *> m_observers;
      Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *m_broker;

      std::map<UILayer::AbstractModel::Properties::Tool, int> m_toolIdMap;

      UILayer::AbstractModel::Properties::Tool m_activeTool;

      Interfaces::IFactory<AbstractDomain::IDeltaEditor,
                           AbstractDomain::IImage *
                          > *m_deltaEditorFactory;
      void
      receiveMessage(std::shared_ptr<AbstractDomain::Defs::ImageChange> message);

      void
      addTool(UILayer::AbstractModel::Properties::Tool toolLabel,
              std::unique_ptr<AbstractDomain::ITool> tool
             );
    };
  }
}

#endif
