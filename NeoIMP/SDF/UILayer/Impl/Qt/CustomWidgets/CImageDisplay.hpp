#ifndef SDF_MODELLAYER_UILAYER_IMPL_QT_CUSTOMWIDGETS_CIMAGEDISPLAY_HPP
#define SDF_MODELLAYER_UILAYER_IMPL_QT_CUSTOMWIDGETS_CIMAGEDISPLAY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CImageDisplay.hpp
 * PURPOSE: The Qt-based image display widget: another part of the image editor.
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

#include <QWidget>

#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentImageDataServiceDependency.hpp>
#include <SDF/ModelLayer/DocumentModel/include/DocumentHandle.hpp>

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
      class CImageDisplay : public QWidget,
      public ModelLayer::DocumentModel::Services::IDocumentImageDataServiceDependency {
        Q_OBJECT
      public:
        CImageDisplay(QWidget *parent = nullptr);
        ~CImageDisplay() {}

        void injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service);

        void setActiveDocument(ModelLayer::DocumentModel::DocumentHandle handle);
      private:
        ModelLayer::DocumentModel::Services::IDocumentImageDataService *m_documentImageDataService;
        ModelLayer::DocumentModel::DocumentHandle m_documentHandle;

        float m_viewCenterX;
        float m_viewCenterY;
        float m_magnificationFactor;

        void paintEvent(QPaintEvent *event);
      private:
        void drawWidget(QPainter &qp);
      };
    }
  }
}

#endif
