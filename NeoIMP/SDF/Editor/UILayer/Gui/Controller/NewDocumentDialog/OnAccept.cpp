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

namespace SDF::Editor::UILayer::Gui::Controller::NewDocumentDialog {
  OnAccept::OnAccept(
    AbstractModel::Create::ICreateDocumentService *a_createDocumentService,
    IViewProducer<Common::Handle> *a_documentViewProducer
  )
    : m_createDocumentService(a_createDocumentService),
      m_documentViewProducer(a_documentViewProducer)
  {
  }

  void
  OnAccept::onTrigger(AbstractModel::Defs::ImageSpec a_imageSpec) {
    if(m_documentViewProducer != nullptr) {
      Common::Handle documentHandle = m_createDocumentService->createFromSpec(a_imageSpec);

      m_documentViewProducer->produceView(documentHandle);
    }
  }
}
