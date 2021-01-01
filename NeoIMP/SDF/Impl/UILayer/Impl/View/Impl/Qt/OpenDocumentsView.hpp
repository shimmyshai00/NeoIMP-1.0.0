#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_OPENDOCUMENTSVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_OPENDOCUMENTSVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentsView.hpp
 * PURPOSE: Headers for the Qt-based open-documents view implementation. This provides a tab widget to be inserted into
 *          the main window, and to which can be added tabs with document views in them.
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

#include <SDF/Impl/UILayer/Impl/View/Impl/Qt/IQtMVCView.hpp>
#include <SDF/Impl/UILayer/Impl/View/IOpenDocumentsView.hpp>

#include <QPointer>
#include <QTabWidget>
#include <QWidget>

#include <boost/signals2/signal.hpp>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IImageInformationService;
  }

  namespace Impl::View::Impl::Qt {
    class DocumentView;
    
    class OpenDocumentsView : public IQtMVCView, public IOpenDocumentsView {
    public:
      OpenDocumentsView(AbstractModel::Services::IImageInformationService *imageInformationService);

      QWidget *getQWidget();

      void show();
      void close();

      void addDocumentView(AbstractModel::Handle handle, DocumentView &documentView);

      void update(Updates::DocumentAddedUpdate updateData);
    private:
      AbstractModel::Services::IImageInformationService *m_imageInformationService;

      QPointer<QTabWidget> m_tabWidget;
      std::map<AbstractModel::Handle, QPointer<QWidget>> m_documentWidgetHolders;
    };
  }
}

#endif
