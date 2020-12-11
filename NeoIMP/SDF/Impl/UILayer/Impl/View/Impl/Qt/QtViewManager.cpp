/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.cpp
 * PURPOSE: The view manager for Qt-based MVC views. This supplies the views with widgets and makes sure the widgets
 *          are properly linked together.
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

#include <QtViewManager.hpp>

#include <ModelLayer/Services/IImageRenderingService.hpp>

#include <IApplicationView.hpp>
#include <INewDocumentParamsView.hpp>
#include <IDocumentView.hpp>

#include <QtApplicationView.hpp>
#include <QtNewDocumentParamsView.hpp>
#include <QtDocumentView.hpp>

#include <Windows/MainWindow.hpp>
#include <Dialogs/NewDocumentDialog.hpp>
#include <CustomWidgets/DocumentWidget.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtViewManager::QtViewManager(ModelLayer::Services::IImageRenderingService *imageRenderingService)
  : m_imageRenderingService(imageRenderingService),
    m_mainWindow(new Windows::MainWindow),
    m_newDocumentDialog(new Dialogs::NewDocumentDialog),
    m_applicationView(new QtApplicationView(m_mainWindow.get())),
    m_newDocumentParamsView(new QtNewDocumentParamsView(m_newDocumentDialog.get()))
  {}

  QtViewManager::~QtViewManager() {}

  IApplicationView *QtViewManager::getApplicationView() {
    return m_applicationView.get();
  }

  INewDocumentParamsView *QtViewManager::getNewDocumentParamsView() {
    return m_newDocumentParamsView.get();
  }

  std::unique_ptr<IDocumentView> QtViewManager::createDocumentView(ModelLayer::Handle handle) {
    CustomWidgets::DocumentWidget *documentWidget(new CustomWidgets::DocumentWidget);
    m_mainWindow->addDocumentTab("Untitled", documentWidget);

    std::unique_ptr<QtDocumentView> rv(new QtDocumentView(m_imageRenderingService, documentWidget));
    rv->showDocument(handle);

    return std::move(rv);
  }
}
