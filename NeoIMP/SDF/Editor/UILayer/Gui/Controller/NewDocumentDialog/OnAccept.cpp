/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAccept.cpp
 * PURPOSE: Implements the OnAccept class.
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

#include "OnAccept.hpp"

#include "../../../Support/Bundle.hpp"
#include "../../View/EViewType.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::NewDocumentDialog {
  OnAccept::OnAccept(AbstractModel::ICreateImageService *createImageService,
                     IViewManager<View::EViewType> *viewManager
                    )
    : m_createImageService(createImageService),
      m_viewManager(viewManager)
  {
  }

  void
  OnAccept::onTrigger(AbstractModel::Defs::ImageSpec imageSpec) {
    if(m_createImageService != nullptr) {
      Common::Handle documentHandle = m_createImageService->createImage(imageSpec);

      std::shared_ptr<Support::Bundle> bundle(new Support::Bundle());
      bundle->addHandle("document_handle", documentHandle);
      m_viewManager->produceView(View::VIEW_DOCUMENT_VIEW, bundle);
    }
  }
}
