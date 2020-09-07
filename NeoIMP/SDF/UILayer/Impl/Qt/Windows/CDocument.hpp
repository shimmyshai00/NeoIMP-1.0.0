#ifndef SDF_UILAYER_IMPL_QT_WINDOWS_CDOCUMENT_HPP
#define SDF_UILAYER_IMPL_QT_WINDOWS_CDOCUMENT_HPP

/*
 * NeoIMP version 1.0.0
 * (C) 2020 The Shining Destiny Foundation. All rights reserved.
 * Licensed under GPLv3 and MPL. See COPYING for details.
 *
 * FILE:    CDocument.hpp
 * PURPOSE: An object representing a document for UI purposes.
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

#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentImageDataServiceDependency.hpp>
#include <SDF/ModelLayer/DocumentModel/include/DocumentHandle.hpp>

#include <QTabWidget>
#include <string>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Services {
        class IDocumentImageDataService;
      }
    }
  }

  namespace UILayer {
    namespace Error {
      class IErrorReporter;
    }

    namespace Impl::Qt::Windows {
      class CDocument : public ModelLayer::DocumentModel::Services::IDocumentImageDataServiceDependency {
      public:
        CDocument(std::string fileName, ModelLayer::DocumentModel::DocumentHandle handle);
        void injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service);

        QString getDocumentFileName() const;
        QString getDocumentTabTitleString() const;

        int addTabTo(QTabWidget *tabWidget) const;
      private:
        ModelLayer::DocumentModel::Services::IDocumentImageDataService *m_documentImageDataService;

        std::string m_fileName;
        ModelLayer::DocumentModel::DocumentHandle m_documentHandle;
      };
    }
  }
}

#endif
