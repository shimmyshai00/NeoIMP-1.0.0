#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_QTAPPLICATIONVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_QTAPPLICATIONVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtApplicationView.hpp
 * PURPOSE: Headers for the Qt-based application view implementation. This wraps the main window.
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

#include <SDF/Impl/UILayer/Impl/View/IApplicationView.hpp>

#include <QPointer>
#include <QWidget>
#include <QMetaObject>

#include <fruit/fruit.h>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  namespace Windows {
    class MainWindow;
  }

  class QtApplicationView : public IApplicationView {
  public:
    QtApplicationView(Windows::MainWindow *mainWindow);
    ~QtApplicationView();

    void show();
    void close();

    void setNewDocumentCommandObserver(AbstractController::INewDocumentCommandObserver *observer);
    void setSaveDocumentCommandObserver(AbstractController::ISaveDocumentCommandObserver *observer);
    void setExitCommandObserver(AbstractController::IExitCommandObserver *observer);
  private:
    QPointer<Windows::MainWindow> m_mainWindow;

    QMetaObject::Connection m_newDocumentCommandObserverConn;
    QMetaObject::Connection m_saveDocumentCommandObserverConn;
    QMetaObject::Connection m_exitCommandObserverConn;

    AbstractController::INewDocumentCommandObserver *m_newDocumentCommandObserver;
    AbstractController::ISaveDocumentCommandObserver *m_saveDocumentCommandObserver;
    AbstractController::IExitCommandObserver *m_exitCommandObserver;
  };
}

#endif
