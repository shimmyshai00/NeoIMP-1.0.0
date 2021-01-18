/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialogController.cpp
 * PURPOSE: The controller associated with the new-document dialog view.
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

#include <SDF/Impl/UILayer/Impl/Controller/NewDocumentDialogController.hpp>

#include <SDF/Impl/UILayer/AbstractAppModel/IDocumentCreator.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Data/DocumentSpec.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  NewDocumentDialogController::NewDocumentDialogController(
    View::IViewSink *viewSink,
    AbstractAppModel::IDocumentCreator *documentCreator
  )
    : m_viewSink(viewSink),
      m_documentCreator(documentCreator),
      m_newDocumentView(nullptr)
  {}

  void NewDocumentDialogController::setView(View::INewDocumentView *newDocumentView) {
    m_newDocumentView = newDocumentView;
  }

  void NewDocumentDialogController::connectToViewObservables(View::NewDocumentViewObservables &observables) {
    safeConnect(observables.onAccepted, [=](AbstractAppModel::Data::DocumentSpec spec) {
      m_documentCreator->createDocument(spec);
      m_viewSink->disposeView(m_newDocumentView->getViewHierarchy().removeSelf());
    });

    safeConnect(observables.onDismissed, [=]() {
      m_viewSink->disposeView(m_newDocumentView->getViewHierarchy().removeSelf());
    });
  }
}
