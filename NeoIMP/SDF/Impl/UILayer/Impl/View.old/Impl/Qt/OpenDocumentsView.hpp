#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_OPENDOCUMENTSVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_OPENDOCUMENTSVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentsView.hpp
 * PURPOSE: The Qt-based open-documents view.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCViewDetail.hpp>
#include <SDF/Impl/UILayer/Impl/View/IOpenDocumentsView.hpp>

#include <SDF/Impl/UILayer/AbstractModel/Handle.hpp>

#include <QPointer>
#include <QTabWidget>

#include <map>
#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IImageInformationService;
    class IImageRenderingService;
  }

  namespace Impl::View::Impl::Qt {
    namespace Windows {
      class MainWindow;
    }

    class DocumentView;

    class OpenDocumentsView : public Framework::IMVCViewDetail<QTabWidget>, public IOpenDocumentsView {
    public:
      OpenDocumentsView(
        QPointer<Windows::MainWindow> mainWindow,
        AbstractModel::Services::IImageInformationService *imageInformationService,
        AbstractModel::Services::IImageRenderingService *imageRenderingService
      );

      ~OpenDocumentsView();

      QTabWidget *getDetail();

      void activate();
      void update(std::string updateEvent);
      void shutdown();

      IDocumentView *getDocumentView(AbstractModel::Handle handle);
    private:
      AbstractModel::Services::IImageInformationService *m_imageInformationService;
      AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

      QPointer<QTabWidget> m_tabWidget;

      std::map<AbstractModel::Handle, std::unique_ptr<DocumentView>> m_documentViews;
    };
  }
}

#endif
