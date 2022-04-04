/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewProducer.cpp
 * PURPOSE: Implements the DocumentViewProducer class.
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

#include "DocumentViewProducer.hpp"

#include "../../../Controller/DocumentView/OnScroll.hpp"

#include "../Views/MainWindow.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  DocumentViewProducer::DocumentViewProducer(
    deps_t a_deps,
    Common::Handle a_id,
    AProducerNode *a_parent,
    Common::Handle a_documentHandle
  )
    : AProducerNode(a_id, a_parent),
      m_services(a_deps),
      m_documentHandle(a_documentHandle)
  {
  }

  QWidget *
  DocumentViewProducer::getViewWidget() {
    return m_documentView;
  }

  void
  DocumentViewProducer::produceView() {
    using namespace AbstractModel::Editing;
    using namespace Controller::DocumentView;
    using namespace Views;

    MainWindow *mainWindow(dynamic_cast<MainWindow *>(getParent()->getViewWidget()));
    if(mainWindow != nullptr) {
      m_documentView = new DocumentView(m_services, m_documentHandle);

      auto onHScrollController = std::make_unique<OnHScroll>(m_services);
      auto onVScrollController = std::make_unique<OnVScroll>(m_services);

      m_documentView->hookOnHScroll(std::move(onHScrollController))->connect();
      m_documentView->hookOnVScroll(std::move(onVScrollController))->connect();

      std::string documentName(m_services.get<IGetDocumentNameService>()->getDocumentName(
        m_documentHandle));

      mainWindow->addTabPane(documentName, m_documentView);
    }
  }
}
