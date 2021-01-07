/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentsView.cpp
 * PURPOSE: The Qt-based open-documents view implementation.
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

#include <OpenDocumentsView.hpp>

#include <UILayer/Exceptions/Exceptions.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>

#include <IDocumentView.hpp>

#include <ApplicationView.hpp>
#include <DocumentView.hpp>

#include <Windows/MainWindow.hpp>
#include <CustomWidgets/DocumentWidget.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  OpenDocumentsView::OpenDocumentsView(
    ApplicationView *context,
    AbstractModel::Services::IImageInformationService *imageInformationService
  )
    : m_imageInformationService(imageInformationService),
      m_tabWidget(new QTabWidget())
  {
    if(context != nullptr) {
      context->getPresentation()->addPrincipalWidget(m_tabWidget);
    }
  }

  QTabWidget *OpenDocumentsView::getPresentation() {
    return m_tabWidget;
  }

  void OpenDocumentsView::documentAdded(AbstractModel::Handle handle, IDocumentView *documentView) {
    std::string imageName(m_imageInformationService->getImageName(handle));

    if(DocumentView *documentViewQt = dynamic_cast<DocumentView *>(documentView)) {
      m_tabWidget->addTab(documentViewQt->getPresentation(), imageName.c_str());
      m_documentViewMap[handle] = documentViewQt;
    } else {
      // cannot add a non-Qt view!
      throw UILayer::Exceptions::IncompatibleContextException("DocumentView");
    }
  }

  void OpenDocumentsView::documentRemoved(AbstractModel::Handle handle) {
    int tabIndex(m_tabWidget->indexOf(m_documentViewMap[handle]->getPresentation()));

    m_tabWidget->removeTab(tabIndex);
  }

  void OpenDocumentsView::documentNameChanged(AbstractModel::Handle handle) {
    int tabIndex(m_tabWidget->indexOf(m_documentViewMap[handle]->getPresentation()));
    std::string imageName(m_imageInformationService->getImageName(handle));

    m_tabWidget->setTabText(tabIndex, imageName.c_str());
  }
}
