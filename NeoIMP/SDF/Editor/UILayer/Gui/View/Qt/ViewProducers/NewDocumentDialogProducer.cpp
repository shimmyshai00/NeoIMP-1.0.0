/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialogProducer.cpp
 * PURPOSE: Implements the NewDocumentDialogProducer class.
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

#include "NewDocumentDialogProducer.hpp"

#include "../../../Controller/NewDocumentDialog/OnAccept.hpp"

#include "../Views/NewDocumentDialog.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  NewDocumentDialogProducer::NewDocumentDialogProducer(
    deps_t a_deps,
    Common::Handle a_id,
    AProducerNode *a_parent
  )
    : AProducerNode(a_id, a_parent),
      m_services(a_deps)
  {
  }

  QWidget *
  NewDocumentDialogProducer::getViewWidget() {
    return m_newDocumentDialog;
  }

  void
  NewDocumentDialogProducer::produceView() {
    using namespace Controller::NewDocumentDialog;
    using namespace Views;

    if(!m_newDocumentDialog) {
      m_newDocumentDialog = new NewDocumentDialog(m_services, getParent()->getViewWidget());
      m_newDocumentDialog->setAttribute(::Qt::WA_DeleteOnClose);

      auto onAcceptController = std::make_unique<OnAccept>(m_services);

      m_newDocumentDialog->hookOnAccept(std::move(onAcceptController))->connect();

      m_newDocumentDialog->exec();
    }
  }
}
