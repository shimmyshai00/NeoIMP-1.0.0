#ifndef SDF_MODELLAYER_SERVICES_UISTATEMODELSERVICE_TPP
#define SDF_MODELLAYER_SERVICES_UISTATEMODELSERVICE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiStateModelService.tpp
 * PURPOSE: Implements the UiStateModelService template.
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

#include <SDF/ModelLayer/Exceptions/Exceptions.hpp>

namespace SDF::ModelLayer::Services {
  template<class StateT>
  UiStateModelService<StateT>::UiStateModelService()
  {
  }

  template<class StateT>
  StateT
  UiStateModelService<StateT>::getStateElement(std::string key) {
    if(m_stateMap.find(key) == m_stateMap.end()) {
      throw ModelLayer::Exceptions::KeyNotFoundException(key.c_str());
    } else {
      return m_stateMap[key];
    }
  }

  template<class StateT>
  void
  UiStateModelService<StateT>::setStateElement(std::string key,
                                               StateT value
                                              )
  {
    m_stateMap[key] = value;
  }
}

#endif
