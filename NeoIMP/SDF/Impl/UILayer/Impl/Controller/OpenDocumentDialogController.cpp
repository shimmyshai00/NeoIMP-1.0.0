/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentDialogController.cpp
 * PURPOSE: The controller associated with the open-document dialog view.
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

#include <OpenDocumentDialogController.hpp>

#include <SDF/Impl/UILayer/Impl/View/IViewSink.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Actions/IOpenDocumentAction.hpp>
#include <SDF/Impl/DataLayer/Properties/FileFormat.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  OpenDocumentDialogController::OpenDocumentDialogController(
    View::IViewSink *viewSink,
    AbstractAppModel::Actions::IOpenDocumentAction *openDocumentAction
  )
    : m_viewSink(viewSink),
      m_openDocumentAction(openDocumentAction)
  {}

  void
  OpenDocumentDialogController::onAttachView() {
    safeConnect(m_view->onAccepted, [=](std::string fileName, DataLayer::Properties::FileFormat fileFormat) {
      m_openDocumentAction->openDocument(fileName, fileFormat);
      m_viewSink->disposeView(m_view->getViewHierarchy().removeSelf());
    });

    safeConnect(m_view->onDismissed, [=]() {
      m_viewSink->disposeView(m_view->getViewHierarchy().removeSelf());
    });
  }
}
