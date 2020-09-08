/*
 * NeoIMP version 1.0.0
 * (C) 2020 The Shining Destiny Foundation. All rights reserved.
 * Licensed under GPLv3 and MPL. See COPYING for details.
 *
 * FILE:    CDocument.cpp
 * PURPOSE: Implementation of the CDocument class.
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

#include <Impl/Qt/Windows/CDocument.hpp>

#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentImageDataService.hpp>
#include <Impl/Qt/CustomWidgets/CImageEditor.hpp>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::Windows {
      CDocument::CDocument(std::string fileName, ModelLayer::DocumentModel::DocumentHandle handle)
        : m_documentImageDataService(nullptr),
          m_fileName(fileName),
          m_documentHandle(handle)
          {
          }

      void CDocument::injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service) {
        m_documentImageDataService = service;
      }

      QString CDocument::getDocumentFileName() const {
        return QString(m_fileName.c_str());
      }

      QString CDocument::getDocumentTabTitleString() const {
        using namespace ModelLayer::DocumentModel::Services;

        assert(m_documentImageDataService != nullptr);

        QString rv(m_fileName.c_str());
        rv += " ";
        rv += "(";
        rv += QString::number(m_documentImageDataService->getImageWidthInPixels(m_documentHandle)) + " px";
        rv += " × ";
        rv += QString::number(m_documentImageDataService->getImageHeightInPixels(m_documentHandle)) + " px";
        rv += ")";

        return(rv);
      }

      int CDocument::addTabTo(QTabWidget *tabWidget) const {
        assert(m_documentImageDataService != nullptr);

        CustomWidgets::CImageEditor *imageEditor(new CustomWidgets::CImageEditor);
        imageEditor->injectWith(m_documentImageDataService);
        imageEditor->setActiveDocument(m_documentHandle);

        int newTabIdx(tabWidget->addTab(imageEditor, getDocumentTabTitleString()));
        tabWidget->setCurrentIndex(newTabIdx);

        return newTabIdx;
      }
    }
  }
}
