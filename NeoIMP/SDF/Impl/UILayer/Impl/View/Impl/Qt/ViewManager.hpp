#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_VIEWMANAGER_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_VIEWMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.hpp
 * PURPOSE: Headers for the Qt-based view manager implementation.
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
#include <SDF/Impl/UILayer/AbstractModel/Handle.hpp>

#include <fruit/fruit.h>

#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IImageInformationService;
    class IImageRenderingService;
  }

  namespace Impl::View::Impl::Qt {
    class ApplicationView;
    class NewDocumentView;

    class ViewManager : public IViewManager {
    public:
      INJECT(ViewManager(
        AbstractModel::Services::IImageInformationService *imageInformationService,
        AbstractModel::Services::IImageRenderingService *imageRenderingService
      ));

      ~ViewManager();

      void createApplicationView();
      void createNewDocumentView();

      IApplicationView *getApplicationView();
      INewDocumentView *getNewDocumentView();
    private:
      AbstractModel::Services::IImageInformationService *m_imageInformationService;
      AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

      std::unique_ptr<ApplicationView> m_applicationView;
      std::unique_ptr<NewDocumentView> m_newDocumentView;
    };
  }
}

#endif
