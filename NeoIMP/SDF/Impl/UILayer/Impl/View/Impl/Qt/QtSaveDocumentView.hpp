#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_QTSAVEDOCUMENTVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_QTSAVEDOCUMENTVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtSaveDocumentView.hpp
 * PURPOSE: Headers for the Qt-based save-document view implementation.
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

#include <SDF/Impl/UILayer/Impl/View/ISaveDocumentView.hpp>

#include <SDF/Impl/ModelLayer/Handle.hpp>

#include <QPointer>
#include <QFileDialog>
#include <QMetaObject>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  namespace Windows {
    class MainWindow;
  }

  class QtSaveDocumentView : public ISaveDocumentView {
  public:
    QtSaveDocumentView(QFileDialog *saveFileDialog);
    ~QtSaveDocumentView();

    void show();
    
    void setAcceptDocumentSaveParamsCommandObserver(
      AbstractController::IAcceptDocumentSaveParamsCommandObserver *observer
    );
  private:
    QPointer<QFileDialog> m_saveFileDialog;

    QMetaObject::Connection m_acceptDocumentSaveParamsCommandObserverConn;

    AbstractController::IAcceptDocumentSaveParamsCommandObserver *m_acceptDocumentSaveParamsCommandObserver;
  };
}

#endif
