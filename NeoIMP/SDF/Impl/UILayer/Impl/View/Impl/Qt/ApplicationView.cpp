/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationView.cpp
 * PURPOSE: The Qt-based application view.
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

#include <ApplicationView.hpp>

#include <FileCommandsView.hpp>
#include <OpenDocumentsView.hpp>

#include <Windows/MainWindow.hpp>

#include <QObject>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationView::ApplicationView(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_mainWindow(new Windows::MainWindow),
      m_fileCommandsView(new FileCommandsView(m_mainWindow)),
      m_openDocumentsView(new OpenDocumentsView(m_mainWindow, imageInformationService, imageRenderingService))
  {
    // Hook events.
    QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() {
      Framework::MVCObservable<Events::ExitCommandEvent>::notifyObservers(Events::ExitCommandEvent());
    });

    m_mainWindow->show();
  }

  ApplicationView::~ApplicationView() {}

  IFileCommandsView *ApplicationView::getFileCommandsView() {
    return m_fileCommandsView.get();
  }

  IOpenDocumentsView *ApplicationView::getOpenDocumentsView() {
    return m_openDocumentsView.get();
  }
}
