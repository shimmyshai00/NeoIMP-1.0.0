#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_DOCUMENTVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_DOCUMENTVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.hpp
 * PURPOSE: The Qt-based document view object.
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

#include <SDF/Impl/UILayer/Impl/View/IDocumentView.hpp>

#include <SDF/Impl/ModelLayer/Handle.hpp>

#include <QPointer>
#include <vector>
#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IImageInformationService;
    class IImageRenderingService;
  }

  namespace Impl::View {
    /*
    namespace Observers {
      class IApplicationViewObserver;
    }
    */

    namespace Impl::Qt {
      namespace CustomWidgets {
        class DocumentWidget;
      }

      namespace Windows {
        class MainWindow;
      }

      class ModelImageDataSource;

      class DocumentView : public IDocumentView {
      public:
        DocumentView(
          AbstractModel::Services::IImageInformationService *imageInformationService,
          AbstractModel::Services::IImageRenderingService *imageRenderingService,
          QPointer<Windows::MainWindow> mainWindow,
          QPointer<CustomWidgets::DocumentWidget> documentWidget,
          ModelLayer::Handle documentHandle
        );

        ~DocumentView();

        void updateDocumentTitle(std::string newDocumentTitle);
      private:
        QPointer<Windows::MainWindow> m_mainWindow;
        QPointer<CustomWidgets::DocumentWidget> m_documentWidget;

        ModelLayer::Handle m_documentHandle;
        std::unique_ptr<ModelImageDataSource> m_dataSource;

        /*std::vector<Observers::IApplicationViewObserver *> m_observers;*/
      };
    }
  }
}

#endif
