/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Controller.cpp
 * PURPOSE: The controller for the save-document dialog view.
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

#include <SaveDocumentDlg/Controller.hpp>

#include <Framework/MVCMessageEncoder.hpp>

#include <AbstractModel/Handle.hpp>
#include <AbstractModel/Services/IDocumentStorageService.hpp>

#include <Messages.hpp>

namespace SDF::Impl::UILayer::Impl::Controller::SaveDocumentDlg {
  Controller::Controller(AbstractModel::Services::IDocumentStorageService *documentStorageService)
    : m_documentStorageService(documentStorageService)
  {}

  Controller::~Controller() {}

  void Controller::receiveMessage(void *sender, std::string message) {
    // This controller needs no update messages
  }

  void Controller::notify(View::Events::AcceptSaveParametersEvent e) {
    /*
    AbstractModel::Handle handle(m_documentStorageService->createDocument(e.spec));

    dispatchMessage(Framework::encodeExtra(Messages::DocumentCreated, handle));
    */
    dispatchMessage(Messages::DestroySaveDocumentView);
  }

  void Controller::notify(View::Events::ViewDismissedEvent e) {
    dispatchMessage(Messages::DestroySaveDocumentView);
  }
}
