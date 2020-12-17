#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_QTVIEWMANAGER_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_QTVIEWMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.hpp
 * PURPOSE: The view manager for Qt-based MVC views.
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

#include <SDF/Impl/UILayer/Impl/View/IViewManager.hpp>

#include <QFileDialog>

#include <fruit/fruit.h>
#include <memory>
#include <map>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IImageInformationService;
    class IImageRenderingService;
  }

  namespace Impl::Controller::AbstractView {
    class ISaveDocumentView;
  }

  namespace Impl::View {
    class IApplicationView;
    class INewDocumentParamsView;
    class IDocumentView;

    namespace Impl::Qt {
      namespace Windows {
        class MainWindow;
      }

      namespace Dialogs {
        class NewDocumentDialog;
      }

      class QtApplicationView;
      class QtNewDocumentParamsView;
      class QtSaveDocumentView;
      class QtDocumentView;

      class QtViewManager : public IViewManager {
      public:
        INJECT(QtViewManager(
          AbstractModel::Services::IImageInformationService *imageInformationService,
          AbstractModel::Services::IImageRenderingService *imageRenderingService
        ));

        ~QtViewManager();

        IApplicationView *getApplicationView();
        INewDocumentParamsView *getNewDocumentParamsView();
        Controller::AbstractView::ISaveDocumentView *getSaveDocumentView();
        IDocumentView *createDocumentView(ModelLayer::Handle documentHandle);
      private:
        AbstractModel::Services::IImageInformationService *m_imageInformationService;
        AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

        std::unique_ptr<Windows::MainWindow> m_mainWindow;
        std::unique_ptr<Dialogs::NewDocumentDialog> m_newDocumentDialog;
        std::unique_ptr<QFileDialog> m_saveDocumentDialog;

        std::unique_ptr<QtApplicationView> m_applicationView;
        std::unique_ptr<QtNewDocumentParamsView> m_newDocumentParamsView;
        std::unique_ptr<QtSaveDocumentView> m_saveDocumentView;

        std::map<ModelLayer::Handle, std::unique_ptr<QtDocumentView>> m_documentViews;

        // nb: move this out of here?
        std::map<int, ModelLayer::Handle> m_tabHandles;
      };
    }
  }
}

#endif
