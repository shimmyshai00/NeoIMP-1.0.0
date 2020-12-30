#ifndef SDF_IMPL_UILAYER_IMPL_VIEWMODEL_APPLICATIONVIEWMODEL_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEWMODEL_APPLICATIONVIEWMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationViewModel.hpp
 * PURPOSE: The view model for the application view. This stores UI state that doesn't fit in other areas such as what
 *          document is currently selected as the active document for editing commands.
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

#include <SDF/Impl/UILayer/AbstractModel/Handle.hpp>

namespace SDF::Impl::UILayer::Impl::ViewModel {
  class ApplicationViewModel {
  public:
    ApplicationViewModel();

    // NB: should be matured into a data binding at some point to make a "proper" viewmodel
    AbstractModel::Handle getActiveDocumentHandle();
    void setActiveDocumentHandle(AbstractModel::Handle handle);
  private:
    AbstractModel::Handle m_activeDocumentHandle;
  };
}

#endif
