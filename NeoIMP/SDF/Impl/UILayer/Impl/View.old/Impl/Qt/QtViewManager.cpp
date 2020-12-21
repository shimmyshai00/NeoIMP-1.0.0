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

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>

#include <IApplicationView.hpp>
#include <ICreateNewDocumentView.hpp>
#include <ISaveDocumentView.hpp>
#include <IDocumentView.hpp>

#include <CustomWidgets/IImageDataSource.hpp>

#include <QtApplicationView.hpp>
#include <QtCreateNewDocumentView.hpp>
#include <QtSaveDocumentView.hpp>
#include <QtDocumentView.hpp>

#include <Windows/MainWindow.hpp>
#include <Dialogs/NewDocumentDialog.hpp>
#include <CustomWidgets/DocumentWidget.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtViewManager::QtViewManager(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService),
      m_mainWindow(new Windows::MainWindow),
      m_newDocumentDialog(new Dialogs::NewDocumentDialog),
      m_saveDocumentDialog(new QFileDialog(nullptr, "Save As")),
      m_applicationView(new QtApplicationView(m_mainWindow.get())),
      m_createNewDocumentView(new QtCreateNewDocumentView(m_newDocumentDialog.get())),
      m_saveDocumentView(new QtSaveDocumentView(m_saveDocumentDialog.get()))
  {
    m_saveDocumentDialog->setAcceptMode(QFileDialog::AcceptSave);
  }

  QtViewManager::~QtViewManager() {}

  IApplicationView *QtViewManager::getApplicationView() {
    return m_applicationView.get();
  }

  ICreateNewDocumentView *QtViewManager::getCreateNewDocumentView() {
    return m_createNewDocumentView.get();
  }

  ISaveDocumentView *QtViewManager::getSaveDocumentView() {
    return m_saveDocumentView.get();
  }

  IDocumentView *QtViewManager::getDocumentView(ModelLayer::Handle documentHandle) {
    if(m_documentViews.find(documentHandle) == m_documentViews.end()) {
      return nullptr;
    } else {
      return m_documentViews[documentHandle].get();
    }
  }

  void QtViewManager::createDocumentView(ModelLayer::Handle handle) {
    if(m_documentViews.find(handle) == m_documentViews.end()) {
      CustomWidgets::DocumentWidget *documentWidget(new CustomWidgets::DocumentWidget);
      int newTabIndex(m_mainWindow->addDocumentTab("Untitled", documentWidget));

      std::unique_ptr<QtDocumentView> documentView(new QtDocumentView(
        m_imageInformationService,
        m_imageRenderingService,
        m_mainWindow.get(),
        documentWidget,
        newTabIndex,
        handle
      ));

      m_documentViews[handle] = std::move(documentView);
    }
  }
}
