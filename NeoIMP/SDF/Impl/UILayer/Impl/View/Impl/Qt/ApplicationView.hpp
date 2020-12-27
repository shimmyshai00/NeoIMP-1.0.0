#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_APPLICATIONVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_APPLICATIONVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationView.hpp
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

#include <SDF/Impl/UILayer/Impl/View/Impl/Qt/IQtView.hpp>
#include <SDF/Impl/UILayer/Impl/View/IApplicationView.hpp>

#include <SDF/Impl/Framework/IMVCObservable.hpp>
#include <SDF/Impl/Framework/MVCNotifiable.hpp>

#include <QPointer>
#include <QMetaObject>

#include <fruit/fruit.h>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  namespace Windows {
    class MainWindow;
  }

  class ApplicationView : public IQtView<Windows::MainWindow>, public IApplicationView {
  public:
    ApplicationView();
    ~ApplicationView();

    QPointer<Windows::MainWindow> getQWidget();

    void show();
    void close();

    Framework::IMVCObservable<> &getNewDocumentCommandObservable();
    Framework::IMVCObservable<> &getSaveDocumentCommandObservable();
    Framework::IMVCObservable<> &getExitCommandObservable();
  private:
    QPointer<Windows::MainWindow> m_mainWindow;

    QMetaObject::Connection m_newDocumentCommandNotifiableConn;
    QMetaObject::Connection m_newDocumentCommandNotifiableConn;
    QMetaObject::Connection m_newDocumentCommandNotifiableConn;

    Framework::MVCNotifiable<> m_newDocumentCommandNotifiable;
    Framework::MVCNotifiable<> m_saveDocumentCommandNotifiable;
    Framework::MVCNotifiable<> m_exitCommandNotifiable;
  };
}

#endif