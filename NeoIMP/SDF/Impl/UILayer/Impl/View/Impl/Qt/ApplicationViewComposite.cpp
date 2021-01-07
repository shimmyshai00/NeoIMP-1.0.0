/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationViewComposite.cpp
 * PURPOSE: The Qt-based application view composite.
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

#include <ApplicationViewComposite.hpp>

#include <UILayer/Exceptions/Exceptions.hpp>

#include <ApplicationView.hpp>
#include <DocumentView.hpp>

#include <Windows/MainWindow.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationViewComposite::ApplicationViewComposite(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService),
      m_applicationView(new ApplicationView()),
      m_tabWidget(new QTabWidget())
  {
    m_applicationView->getDetail()->addPrincipalWidget(m_tabWidget);
  }

  ApplicationViewComposite::~ApplicationViewComposite() {}

  IApplicationView *ApplicationViewComposite::getApplicationView() {
    return m_applicationView.get();
  }

  IDocumentView *ApplicationViewComposite::getDocumentView(AbstractModel::Handle handle) {
    if(m_documentViews.find(handle) == m_documentViews.end()) {
      throw UILayer::Exceptions::InvalidHandleException(handle);
    }

    return m_documentViews[handle].get();
  }

  void ApplicationViewComposite::addDocument(AbstractModel::Handle handle) {
    if(m_documentViews.find(handle) == m_documentViews.end()) {
      m_documentViews[handle] = std::make_unique<DocumentView>(
        m_tabWidget,
        m_imageInformationService,
        m_imageRenderingService,
        handle
      );
    }
  }
}
