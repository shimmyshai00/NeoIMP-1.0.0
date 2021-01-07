#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_APPLICATIONVIEWCOMPOSITE_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_APPLICATIONVIEWCOMPOSITE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationViewComposite.hpp
 * PURPOSE: The Qt-based application view composite.
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

#include <SDF/Impl/UILayer/Impl/View/IApplicationViewComposite.hpp>

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
    class ApplicationView;
    class DocumentView;

    class ApplicationViewComposite : public IApplicationViewComposite {
    public:
      ApplicationViewComposite(
        AbstractModel::Services::IImageInformationService *imageInformationService,
        AbstractModel::Services::IImageRenderingService *imageRenderingService
      );

      ~ApplicationViewComposite();

      IApplicationView *getApplicationView();
      IDocumentView *getDocumentView(AbstractModel::Handle handle);

      void addDocument(AbstractModel::Handle handle);
    private:
      AbstractModel::Services::IImageInformationService *m_imageInformationService;
      AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

      std::unique_ptr<ApplicationView> m_applicationView;
      QPointer<QTabWidget> m_tabWidget;

      std::map<AbstractModel::Handle, std::unique_ptr<DocumentView>> m_documentViews;
    };
  }
}

#endif
