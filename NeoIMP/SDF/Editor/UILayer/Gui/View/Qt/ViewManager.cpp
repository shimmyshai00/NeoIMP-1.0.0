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
#include "DocumentView.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  const Common::Handle HANDLE_MAIN_WINDOW = 0;
  const Common::Handle HANDLE_NEW_DOCUMENT_DIALOG = 1;
  const Common::Handle HANDLE_OPEN_DOCUMENT_DIALOG = 2;
  const Common::Handle HANDLE_SAVE_DOCUMENT_DIALOG = 3;
  const Common::Handle HANDLE_DOCUMENT_VIEW_ORIGIN = 10000;
}

namespace SDF::Editor::UILayer::Gui::View::Qt {
  Common::Handle ViewManager::addViewIfNotPresent(Common::Handle handle, QWidget *view) {
    if(m_views.find(handle) == m_views.end()) {
      m_views[handle] = view;
      m_views[handle]->show();

      QObject::connect(view, &QObject::destroyed, [=]() { m_views.erase(handle); });

      return handle;
    } else {
      return Common::HANDLE_INVALID;
    }
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt {
  ViewManager::ViewManager(
    AbstractModel::Editing::IGetDocumentNameService *documentNameService,
    ViewFactory *viewFactory
  )
    : m_documentNameService(documentNameService),
      m_viewFactory(viewFactory),
      m_nextDocumentViewHandle(Impl::HANDLE_DOCUMENT_VIEW_ORIGIN)
  {
    m_viewFactory->setViewManager(this);
  }

  ViewManager::~ViewManager() {
  }

  Common::Handle
  ViewManager::produceView(ViewType viewType, std::shared_ptr<Support::Bundle> argBundle) {
    switch(viewType) {
      case VIEW_MAIN_WINDOW:
        return addViewIfNotPresent(Impl::HANDLE_MAIN_WINDOW, m_viewFactory->createMainWindow());
      case VIEW_NEW_DOCUMENT_DIALOG:
        return addViewIfNotPresent(Impl::HANDLE_NEW_DOCUMENT_DIALOG,
          m_viewFactory->createNewDocumentDialog());
      case VIEW_OPEN_DOCUMENT_DIALOG:
        return addViewIfNotPresent(Impl::HANDLE_OPEN_DOCUMENT_DIALOG,
          m_viewFactory->createOpenDocumentDialog());
      case VIEW_SAVE_DOCUMENT_DIALOG:
        return addViewIfNotPresent(Impl::HANDLE_SAVE_DOCUMENT_DIALOG,
          m_viewFactory->createSaveDocumentDialog());
      case VIEW_DOCUMENT_VIEW:
      {
        Common::Handle documentHandle =
          argBundle->getHandle("document_handle", Common::HANDLE_INVALID);

        printf("Handle: %u\n", documentHandle);

        if(documentHandle != Common::HANDLE_INVALID) {
          // This kind of view requires special procedures to add as it composes with the main
          // window nontrivially.
          DocumentView *docView = m_viewFactory->createDocumentView(documentHandle);
          if(m_views.find(Impl::HANDLE_MAIN_WINDOW) != m_views.end()) {
            auto mw = dynamic_cast<MainWindow *>(m_views[Impl::HANDLE_MAIN_WINDOW]);
            if(mw != nullptr) { // SHOULD always be OK...
              std::string title = m_documentNameService->getDocumentName(documentHandle);
              mw->addTabPane(title, docView);
            }

            Common::Handle viewHandle = m_nextDocumentViewHandle++;
            m_views[viewHandle] = docView; // should be unique handle
            return viewHandle;
          } else {
            delete docView;
            return Common::HANDLE_INVALID;
          }
        } else {
          return Common::HANDLE_INVALID;
        }

      }
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
  ViewManager::destroyAllOfType(ViewType viewType) {
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
