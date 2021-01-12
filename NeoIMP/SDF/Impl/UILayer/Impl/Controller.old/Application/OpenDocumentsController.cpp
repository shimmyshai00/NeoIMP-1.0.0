/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentsController.cpp
 * PURPOSE: The controller for the open documents sub-view.
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

#include <OpenDocumentsController.hpp>
#include <iostream>

namespace SDF::Impl::UILayer::Impl::Controller::Application {
  OpenDocumentsController::OpenDocumentsController(
    AbstractAppModel::IFocusDocumentSelector *focusDocumentSelector,
    Framework::IMVCView *view
  )
    : m_focusDocumentSelector(focusDocumentSelector),
      m_view(view)
  {}

  OpenDocumentsController::~OpenDocumentsController() {}

  void OpenDocumentsController::receiveMessage(void *sender, std::string message) {
    std::cout << "odc recv: " << message << std::endl;
    m_view->update(message);
  }

  void OpenDocumentsController::notify(View::Events::FocusDocumentChangedEvent e) {
    std::cout << "focus doc handle: " << e.newFocusDocumentHandle << std::endl;
    m_focusDocumentSelector->setFocusDocument(e.newFocusDocumentHandle);
  }
}
