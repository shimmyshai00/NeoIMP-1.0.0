/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewFactory.cpp
 * PURPOSE: Implements the ViewFactory class.
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

#include "ViewFactory.hpp"

#include "../../Controller/MainWindow/OnDocumentSelected.hpp"
#include "../../Controller/MainWindow/OnNew.hpp"
#include "../../Controller/MainWindow/OnOpen.hpp"
#include "../../Controller/MainWindow/OnSaveAs.hpp"
#include "../../Controller/MainWindow/OnSave.hpp"
#include "../../Controller/MainWindow/OnExit.hpp"
#include "../../Controller/NewDocumentDialog/OnAccept.hpp"
#include "../../Controller/FileChooserDialog/OnAccept_Open.hpp"
#include "../../Controller/FileChooserDialog/OnAccept_Save.hpp"
#include "../../Controller/DocumentView/OnScroll.hpp"

#include "file_format_names.hpp"
#include "makeFileFilterList.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt {
  ViewFactory::ViewFactory(
    AbstractModel::Create::IGetDocumentPrefabService *a_getDocumentPrefabService,
    AbstractModel::Create::IGetMemoryRequirementsService *a_getMemoryRequirementsService,
    AbstractModel::Create::ICreateDocumentService *a_createDocumentSerivce,
    AbstractModel::Metrics::IConvertLengthService *a_convertLengthService,
    AbstractModel::Metrics::IConvertResolutionService *a_convertResolutionService,
    AbstractModel::Metrics::IGetDocumentDimensionsService *a_getDocumentDimensionsService,
    AbstractModel::Storage::IGetDocumentFileInfoService *a_getDocumentFileInfoService,
    AbstractModel::Storage::ISaveDocumentService *a_saveDocumentService,
    AbstractModel::Storage::ILoadDocumentService *a_loadDocumentService,
    AbstractModel::Viewing::IAddViewService *a_addViewService,
    AbstractModel::Viewing::IGetViewCoordinatesService *a_getViewCoordinatesService,
    AbstractModel::Viewing::ISetViewXCoordinateService *a_setViewXCoordinateService,
    AbstractModel::Viewing::ISetViewYCoordinateService *a_setViewYCoordinateService,
    AbstractModel::Viewing::ISetViewCoordinatesService *a_setViewCoordinatesService,
    AbstractModel::Viewing::IRenderingService *a_renderingService,
    AbstractModel::Editing::IGetActiveDocumentService *a_getActiveDocumentService,
    AbstractModel::Editing::ISetActiveDocumentService *a_setActiveDocumentService
  )
    : m_getDocumentPrefabService(a_getDocumentPrefabService),
      m_getMemoryRequirementsService(a_getMemoryRequirementsService),
      m_createDocumentService(a_createDocumentSerivce),
      m_convertLengthService(a_convertLengthService),
      m_convertResolutionService(a_convertResolutionService),
      m_getDocumentDimensionsService(a_getDocumentDimensionsService),
      m_getDocumentFileInfoService(a_getDocumentFileInfoService),
      m_saveDocumentService(a_saveDocumentService),
      m_loadDocumentService(a_loadDocumentService),
      m_addViewService(a_addViewService),
      m_getViewCoordinatesService(a_getViewCoordinatesService),
      m_setViewXCoordinateService(a_setViewXCoordinateService),
      m_setViewYCoordinateService(a_setViewYCoordinateService),
      m_setViewCoordinatesService(a_setViewCoordinatesService),
      m_renderingService(a_renderingService),
      m_getActiveDocumentService(a_getActiveDocumentService),
      m_setActiveDocumentService(a_setActiveDocumentService),
      m_viewManager(nullptr)
  {
  }

  void
  ViewFactory::setViewManager(IViewManager<ViewType> *a_viewManager) {
    m_viewManager = a_viewManager;
  }

  MainWindow *
  ViewFactory::createMainWindow(QWidget *a_parent) {
    MainWindow *rv = new MainWindow(a_parent);

    auto onDocumentSelected = std::make_unique<Controller::MainWindow::OnDocumentSelected>(
      m_setActiveDocumentService);
    rv->hookOnDocumentSelected(std::move(onDocumentSelected))->connect();

    auto onNew = std::make_unique<Controller::MainWindow::OnNew>(m_viewManager);
    rv->hookOnNew(std::move(onNew))->connect();

    auto onOpen = std::make_unique<Controller::MainWindow::OnOpen>(m_viewManager);
    rv->hookOnOpen(std::move(onOpen))->connect();

    auto onSaveAs = std::make_unique<Controller::MainWindow::OnSaveAs>(m_viewManager);
    rv->hookOnSaveAs(std::move(onSaveAs))->connect();

    auto onSave = std::make_unique<Controller::MainWindow::OnSave>(m_getActiveDocumentService,
      m_getDocumentFileInfoService, m_saveDocumentService, m_viewManager);
    rv->hookOnSave(std::move(onSave))->connect();

    auto onExit = std::make_unique<Controller::MainWindow::OnExit>(m_viewManager);
    rv->hookOnExit(std::move(onExit))->connect();

    return rv;
  }

  NewDocumentDialog *
  ViewFactory::createNewDocumentDialog(QWidget *a_parent) {
    NewDocumentDialog *rv = new NewDocumentDialog(m_convertLengthService,
      m_convertResolutionService, m_getDocumentPrefabService, m_getMemoryRequirementsService,
      a_parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);

    auto onAccept = std::make_unique<Controller::NewDocumentDialog::OnAccept>(
      m_createDocumentService, m_viewManager);
    rv->hookOnAccept(std::move(onAccept))->connect();

    return rv;
  }

  FileChooserDialog *
  ViewFactory::createOpenDocumentDialog(QWidget *a_parent) {
    FileChooserDialog *rv = new FileChooserDialog(a_parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);
    rv->setAcceptMode(QFileDialog::AcceptOpen);
    rv->setNameFilters(makeFileFilterList(g_fileFormatNames, g_fileExtensionFilters,
      AbstractModel::Defs::FILE_FORMAT_MAX));

    auto c = std::make_unique<Controller::FileChooserDialog::OnAccept_Open>(m_loadDocumentService,
      m_viewManager);
    rv->hookOnAccept(std::move(c))->connect();

    return rv;
  }

  FileChooserDialog *
  ViewFactory::createSaveDocumentDialog(QWidget *a_parent) {
    FileChooserDialog *rv = new FileChooserDialog(a_parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);
    rv->setAcceptMode(QFileDialog::AcceptSave);
    rv->setNameFilters(makeFileFilterList(g_fileFormatNames, g_fileExtensionFilters,
      AbstractModel::Defs::FILE_FORMAT_MAX));

    auto c = std::make_unique<Controller::FileChooserDialog::OnAccept_Save>(
      m_getActiveDocumentService, m_saveDocumentService);
    rv->hookOnAccept(std::move(c))->connect();

    return rv;
  }

  DocumentView *
  ViewFactory::createDocumentView(Common::Handle a_documentHandle, QWidget *a_parent) {
    DocumentView *rv = new DocumentView(m_getDocumentDimensionsService, m_addViewService,
      m_getViewCoordinatesService, m_renderingService, a_documentHandle, a_parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);

    auto onHScroll = std::make_unique<Controller::DocumentView::OnHScroll>(
      m_setViewXCoordinateService);
    rv->hookOnHScroll(std::move(onHScroll))->connect();

    auto onVScroll = std::make_unique<Controller::DocumentView::OnVScroll>(
      m_setViewYCoordinateService);
    rv->hookOnVScroll(std::move(onVScroll))->connect();

    return rv;
  }
}
