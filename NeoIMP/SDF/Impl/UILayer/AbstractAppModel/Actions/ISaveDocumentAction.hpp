#ifndef SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_ACTIONS_ISAVEDOCUMENTACTION_HPP
#define SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_ACTIONS_ISAVEDOCUMENTACTION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISaveDocumentAction.hpp
 * PURPOSE: Provides an interface for the action to save the currently-focused document to the same filename as it
 *          already has.
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

#include <SDF/Impl/DataLayer/Properties/FileFormat.hpp>
#include <string>

namespace SDF::Impl::UILayer::AbstractAppModel::Actions {
  class ISaveDocumentAction {
  public:
    virtual ~ISaveDocumentAction() = default;

    // Function:         saveDocument
    // Prupose:          Saves the current document into its file.
    // Error conditions: The current document has no already-assigned file name.
    virtual void saveDocument() = 0;
  };
}

#endif
