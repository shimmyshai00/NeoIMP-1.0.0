#ifndef SDF_IMPL_APPMODELLAYER_IMPL_DOCUMENTSTATEMODEL_HPP
#define SDF_IMPL_APPMODELLAYER_IMPL_DOCUMENTSTATEMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStateModel.hpp
 * PURPOSE: Centralizes all the UI state for a single document.
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

#include <SDF/Impl/AppModelLayer/Impl/IDocumentStateModelMutation.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/State/IDocumentAppModel.hpp>

#include <fruit/fruit.h>
#include <vector>
#include <string>

namespace SDF::Impl::AppModelLayer::Impl {
  class DocumentStateModel : public IDocumentStateModelMutation,
                             public UILayer::AbstractAppModel::State::IDocumentAppModel
  {
  public:
    DocumentStateModel();

    // State manipulation.
    void setDocumentName(std::string newName);

    // State access.
    std::string getDocumentName();
  private:
    // State.
    std::string m_documentName;
  };
}

#endif
