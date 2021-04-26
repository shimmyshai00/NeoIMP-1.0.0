#ifndef SDF_MODELLAYER_SERVICES_UISTATEMODELSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_UISTATEMODELSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiStateModelService.hpp
 * PURPOSE: Defines the UiStateModelService template.
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

#include <SDF/UILayer/AbstractModel/IUiStateModelService.hpp>

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/UILayer/AbstractModel/Events/UiStateChangeEvent.hpp>

#include <fruit/fruit.h>

#include <string>
#include <map>
#include <vector>

namespace SDF::ModelLayer::Services {
  // Class:      UiStateModelService
  // Purpose:    Provides a database to store editor UI state that doesn't otherwise fit with a specific UI element or
  //             sensibly could be considered to reflect a property of the domain model.
  // Parameters: StateT - The type of state this state model service serves.
  template<class StateT>
  class UiStateModelService : public UILayer::AbstractModel::IUiStateModelService<StateT> {
  public:
    INJECT(UiStateModelService());

    void
    attachObserver(Interfaces::IEventHandler<UILayer::AbstractModel::Events::UiStateChangeEvent<StateT>> *observer);

    void
    removeObserver(Interfaces::IEventHandler<UILayer::AbstractModel::Events::UiStateChangeEvent<StateT>> *observer);

    StateT
    getStateElement(std::string key);

    void
    setStateElement(std::string key,
                    StateT value
                   );
  private:
    std::vector<Interfaces::IEventHandler<UILayer::AbstractModel::Events::UiStateChangeEvent<StateT>> *> m_observers;

    std::map<std::string, StateT> m_stateMap;
  };
}

#include "SDF/ModelLayer/Services/UiStateModelService.tpp"

#endif
