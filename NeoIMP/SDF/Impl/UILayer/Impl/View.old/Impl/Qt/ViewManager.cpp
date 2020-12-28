/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.cpp
 * PURPOSE: The view manager for Qt-based MVC views. This supplies the views with widgets and makes sure the widgets
 *          are properly linked together.
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

#include <QtViewManager.hpp>

#include <IApplicationView.hpp>
#include <ICreateNewDocumentView.hpp>
#include <ISaveDocumentView.hpp>

#include <ApplicationView.hpp>
#include <CreateNewDocumentView.hpp>
#include <SaveDocumentView.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ViewManager::ViewManager()
    : m_applicationView(new ApplicationView())
  {}

  IApplicationView *ViewManager::getApplicationView() {
    return m_applicationView.get();
  }

  ICreateNewDocumentView *ViewManager::getCreateNewDocumentView() {
    if(!m_createNewDocumentView) {
      m_createNewDocumentView = std::make_unique<CreateNewDocumentView>(m_applicationView);
    }

    return m_createNewDocumentView.get();
  }

  ISaveDocumentView *ViewManager::getSaveDocumentView() {
    if(!m_saveDocumentView) {
      m_saveDocumentView = std::make_unique<SaveDocumentView>(m_applicationView);
    }

    return m_saveDocumentView.get();
  }

  IDocumentView *ViewManager::getDocumentView(ModelLayer::Handle documentHandle) {
    // TBA
    return nullptr;
  }

  void ViewManager::addNewDocument(ModelLayer::Handle documentHandle) {
    // TBA
  }
}
