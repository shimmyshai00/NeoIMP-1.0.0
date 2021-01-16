/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialogController.cpp
 * PURPOSE: The controller for the new-document dialog view.
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

#include <NewDocumentDialogController.hpp>

#include <IViewSink.hpp>
#include <AbstractAppModel/IDocumentCreator.hpp>

#include <View/IApplicationView.hpp>
#include <View/INewDocumentView.hpp>

#include <View/Events/Events.hpp>

#include <iostream>

namespace SDF::Impl::UILayer::Impl::Controller {
  NewDocumentDialogController::NewDocumentDialogController(
    AbstractAppModel::IDocumentCreator *documentCreator,
    IViewSink *viewSink
  )
    : m_documentCreator(documentCreator),
      m_viewSink(viewSink)
  {}

  void NewDocumentDialogController::onViewEvent(Framework::IMVCView *view, Framework::MVCViewEvent e) {
    if(auto *newDocumentView = dynamic_cast<View::INewDocumentView *>(view)) {
      if(e.m_eventDescription == View::Events::DialogAccepted) {
        m_documentCreator->createDocument(newDocumentView->getEnteredSpec());
        m_viewSink->viewRemoved(newDocumentView->getParent()->removeChild(newDocumentView));
      } else if(e.m_eventDescription == View::Events::DialogDismissed) {
        m_viewSink->viewRemoved(newDocumentView->getParent()->removeChild(newDocumentView));
      }
    }
  }
}
