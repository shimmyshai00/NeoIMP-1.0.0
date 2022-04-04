#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DOCUMENTMGMT_IDOCUMENTADDEDSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DOCUMENTMGMT_IDOCUMENTADDEDSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentAddedService.hpp
 * PURPOSE: Defines the IDocumentAddedService interface.
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

#include "../../../../Common/Handle.hpp"
#include "../../../../Common/IListenable.hpp"
#include "../../../../Common/IListener.hpp"
#include "../../../../Common/IConnection.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::DocumentMgmt {
  // Class:      IDocumentAddedService
  // Purpose:    Defines a service interface for listening for the addition of new documents to the
  //             editor.
  // Parameters: None.
  class IDocumentAddedService : public Common::IListenable<Common::Handle> {
  public:
    virtual ~IDocumentAddedService() = default;

    virtual Common::PIConnection
    addListener(std::shared_ptr<Common::IListener<Common::Handle>> a_listener) = 0;
  };
}

#endif
