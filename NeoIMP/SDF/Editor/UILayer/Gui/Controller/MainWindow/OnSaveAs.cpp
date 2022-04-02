/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnSaveAs.cpp
 * PURPOSE: Implements the OnSaveAs class.
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

#include "OnSaveAs.hpp"
#include "../../View/ViewType.hpp"
#include "../../IViewManager.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::MainWindow {
  OnSaveAs::OnSaveAs(IViewManager<View::ViewType> *a_viewManager)
    : m_viewManager(a_viewManager)
  {
  }

  void
  OnSaveAs::onTrigger() {
    if(m_viewManager != nullptr) {
      m_viewManager->produceView(View::VIEW_SAVE_DOCUMENT_DIALOG,
        std::shared_ptr<Support::Bundle>());
    }
  }
}
