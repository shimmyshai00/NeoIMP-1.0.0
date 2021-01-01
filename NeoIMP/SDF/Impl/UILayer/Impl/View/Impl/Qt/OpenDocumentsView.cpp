/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentsView.cpp
 * PURPOSE: Implementation of the OpenDocumentsView class.
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

#include <AbstractModel/Services/IImageInformationService.hpp>

#include <DocumentView.hpp>

#include <iostream>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  OpenDocumentsView::OpenDocumentsView(AbstractModel::Services::IImageInformationService *imageInformationService)
    : m_imageInformationService(imageInformationService),
      m_tabWidget(new QTabWidget)
  {
    m_tabWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
  }

  QWidget *OpenDocumentsView::getQWidget() {
    return m_tabWidget;
  }

  void OpenDocumentsView::show() {}

  void OpenDocumentsView::close() {}

  void OpenDocumentsView::addDocumentView(AbstractModel::Handle handle, DocumentView &documentView) {
    if(m_documents.find(handle) != m_documents.end()) {
      m_tabWidget->addTab(documentView.getQWidget(), m_imageInformationService->getImageName(handle).c_str());
    }
  }

  void OpenDocumentsView::update(Updates::DocumentAddedUpdate updateData) {
    m_documents.insert(updateData.handle);
  }
}
