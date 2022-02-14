/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.cpp
 * PURPOSE: Implements the ViewManager class.
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

#include "ViewManager.hpp"

#include "MainWindow.hpp"

namespace SDF::UILayer::Gui::View::Qt {
  void ViewManager::addViewIfNotPresent(Common::Handle handle,
                                        QWidget *view
                                       )
  {
    if(m_views.find(handle) == m_views.end()) {
      m_views[handle] = view;
      m_views[handle]->show();

      QObject::connect(view, &QObject::destroyed, [=]() { m_views.erase(handle); });
    }
  }
}

namespace SDF::UILayer::Gui::View::Qt {
  ViewManager::ViewManager(ViewFactory *viewFactory)
    : m_viewFactory(viewFactory)
  {
    m_viewFactory->setViewManager(this);
  }

  ViewManager::~ViewManager() {
  }

  Common::Handle
  ViewManager::produceView(EViewType viewType,
                           std::shared_ptr<Support::Bundle> argBundle
                          )
  {
    switch(viewType) {
      case VIEW_MAIN_WINDOW:
        addViewIfNotPresent(HANDLE_MAIN_WINDOW, m_viewFactory->createMainWindow());
        return HANDLE_MAIN_WINDOW;
      case VIEW_NEW_DOCUMENT_DIALOG:
        addViewIfNotPresent(HANDLE_NEW_DOCUMENT_DIALOG, m_viewFactory->createNewDocumentDialog());
        return HANDLE_NEW_DOCUMENT_DIALOG;
      default:
        return Common::HANDLE_INVALID;
    }
  }

  void
  ViewManager::destroyView(Common::Handle viewHandle) {
    if(m_views.find(viewHandle) != m_views.end()) {
      m_views[viewHandle]->close();
      m_views.erase(viewHandle);
    }
  }

  void
  ViewManager::destroyAllOfType(EViewType viewType) {
    // TBA
  }

  void
  ViewManager::destroyAll() {
    for(const auto &ent : m_views) {
      ent.second->close();
    }

    m_views.clear();
  }
}
