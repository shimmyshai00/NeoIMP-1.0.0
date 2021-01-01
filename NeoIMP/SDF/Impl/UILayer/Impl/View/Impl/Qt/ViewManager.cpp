/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.cpp
 * PURPOSE: The Qt-based view manager implementation.
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

#include <ViewManager.hpp>

#include <UILayer/Exceptions/Exceptions.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>
#include <AbstractModel/Handle.hpp>

#include <IApplicationView.hpp>
#include <INewDocumentView.hpp>
#include <IOpenDocumentsView.hpp>
#include <IDocumentView.hpp>

#include <ApplicationView.hpp>
#include <NewDocumentView.hpp>
#include <OpenDocumentsView.hpp>
#include <DocumentView.hpp>

#include <Windows/MainWindow.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ViewManager::ViewManager(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService),
      m_applicationView(new ApplicationView),
      m_newDocumentView(new NewDocumentView),
      m_openDocumentsView(new OpenDocumentsView(m_imageInformationService))
  {
    // Assemble view hierarchy
    // nb: should template IQtMVCView interface?
    static_cast<Windows::MainWindow *>(m_applicationView->getQWidget())->addPrincipalWidget(
      m_openDocumentsView->getQWidget()
    );
  }

  ViewManager::~ViewManager() {}

  void ViewManager::createDocumentView(AbstractModel::Handle documentHandle) {
    if(m_documentViews.find(documentHandle) == m_documentViews.end()) {
      m_documentViews[documentHandle] = std::make_unique<DocumentView>(
        m_imageInformationService,
        m_imageRenderingService,
        documentHandle
      );

      m_openDocumentsView->addDocumentView(documentHandle, *m_documentViews[documentHandle]);
    }
  }

  void ViewManager::removeDocumentView(AbstractModel::Handle documentHandle) {
    if(m_documentViews.find(documentHandle) == m_documentViews.end()) {
      throw UILayer::Exceptions::InvalidHandleException(documentHandle);
    }

    m_documentViews.erase(documentHandle);
  }

  IApplicationView *ViewManager::getApplicationView() {
    return m_applicationView.get();
  }

  INewDocumentView *ViewManager::getNewDocumentView() {
    return m_newDocumentView.get();
  }

  IOpenDocumentsView *ViewManager::getOpenDocumentsView() {
    return m_openDocumentsView.get();
  }

  IDocumentView *ViewManager::getDocumentView(AbstractModel::Handle documentHandle) {
    if(m_documentViews.find(documentHandle) == m_documentViews.end()) {
      throw UILayer::Exceptions::InvalidHandleException(documentHandle);
    }

    return m_documentViews[documentHandle].get();
  }
}
