#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_DOCUMENTVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_DOCUMENTVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.hpp
 * PURPOSE: Headers for the Qt-based document view implementation.
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

#include <SDF/Impl/Framework/MVCView.hpp>
#include <SDF/Impl/UILayer/Impl/View/IDocumentView.hpp>

#include <SDF/Impl/UILayer/AbstractAppModel/DocumentHandle.hpp>

#include <QPointer>
#include <QTabWidget>
#include <memory>
#include <string>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  namespace CustomWidgets {
    class DocumentWidget;
    class IImageDataSource;
  }

  class DocumentView : public Framework::MVCViewExt<AbstractAppModel::EditorModelObservables, DocumentViewObservables>,
                       public IDocumentView
  {
  public:
    DocumentView(AbstractAppModel::DocumentHandle handle);
    ~DocumentView();

    void connectToModelObservables(AbstractAppModel::EditorModelObservables &observables);

    void addToTabWidget(QPointer<QTabWidget> tabWidget);
  private:
    QPointer<QTabWidget> m_tabWidget;
    QPointer<CustomWidgets::DocumentWidget> m_documentWidget;

    std::string m_documentTitle;
    AbstractAppModel::DocumentHandle m_documentHandle;
    std::unique_ptr<CustomWidgets::IImageDataSource> m_imageDataSource;
  };
}

#endif
