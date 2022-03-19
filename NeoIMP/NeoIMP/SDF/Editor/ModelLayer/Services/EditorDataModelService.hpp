#ifndef SDF_EDITOR_MODELLAYER_SERVICES_EDITORDATAMODELSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_EDITORDATAMODELSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditorDataModelService.hpp
 * PURPOSE: Defines the EditorDataModelService class.
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

#include "../DomainObjects/Editor/DataModel.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services {
  // Class:      EditorDataModelService
  // Purpose:    Defines an MVC service to act as a model for the editor application state data.
  // Parameters: None.
  class EditorDataModelService {
  public:
    INJECT(EditorDataModelService(DomainObjects::Editor::DataModel *dataModel));

  private:
    DomainObjects::Editor::DataModel *m_dataModel;
  };
}

#endif
