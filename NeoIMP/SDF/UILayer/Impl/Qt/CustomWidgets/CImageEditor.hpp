#ifndef SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CIMAGEEDITOR_HPP
#define SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CIMAGEEDITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CImageEditor.hpp
 * PURPOSE: The Qt-based image editor widget.
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

#include <QWidget>
#include <QGridLayout>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Services {
        class IDocumentImageDataService;
      }
    }
  }

  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      class CRuler;
      class CImageDisplay;

      class CImageEditor : public QWidget,
      public ModelLayer::DocumentModel::Services::IDocumentImageDataServiceDependency {
        Q_OBJECT
      public:
        CImageEditor(QWidget *parent = nullptr, int initialImgWidthPx = 640, int initialImgHeightPx = 480);
        ~CImageEditor() {}

        void injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service);
        void setActiveDocument(ModelLayer::DocumentModel::DocumentHandle handle);
      private:
        ModelLayer::DocumentModel::Services::IDocumentImageDataService *m_documentImageDataService;
        ModelLayer::DocumentModel::DocumentHandle m_documentHandle;

        QGridLayout *m_gridLayout;

        CRuler *m_topRuler;
        CRuler *m_leftRuler;
        CImageDisplay *m_imageDisplay;

        int m_imageWidthPx;
        int m_imageHeightPx;

        int m_viewCenterX;
        int m_viewCenterY;

        void paintEvent(QPaintEvent *event);
      };
    }
  }
}

#endif
