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
#include "../../Controller/MainWindow/OnSaveAs.hpp"
#include "../../Controller/MainWindow/OnSave.hpp"
#include "../../Controller/MainWindow/OnExit.hpp"
#include "../../Controller/NewDocumentDialog/OnAccept.hpp"
#include "../../Controller/FileChooserDialog/OnAccept_Save.hpp"
#include "../../Controller/DocumentView/OnScroll.hpp"

#include "FileFormatNames.hpp"
#include "makeFileFilterList.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt {
  ViewFactory::ViewFactory(
    AbstractModel::Create::IGetDocumentPrefabService *getDocumentPrefabService,
    AbstractModel::Create::IGetMemoryRequirementsService *getMemoryRequirementsService,
    AbstractModel::Create::ICreateDocumentService *createDocumentSerivce,
    AbstractModel::Metrics::IConvertLengthService *convertLengthService,
    AbstractModel::Metrics::IConvertResolutionService *convertResolutionService,
    AbstractModel::Metrics::IGetDocumentDimensionsService *getDocumentDimensionsService,
    AbstractModel::Storage::ISaveDocumentService *saveDocumentService,
    AbstractModel::Viewing::IAddViewService *addViewService,
    AbstractModel::Viewing::IGetViewCoordinatesService *getViewCoordinatesService,
    AbstractModel::Viewing::ISetViewXCoordinateService *setViewXCoordinateService,
    AbstractModel::Viewing::ISetViewYCoordinateService *setViewYCoordinateService,
    AbstractModel::Viewing::ISetViewCoordinatesService *setViewCoordinatesService,
    AbstractModel::Viewing::IRenderingService *renderingService,
    AbstractModel::Editing::IGetActiveDocumentService *getActiveDocumentService,
    AbstractModel::Editing::ISetActiveDocumentService *setActiveDocumentService
  )
    : m_getDocumentPrefabService(getDocumentPrefabService),
      m_getMemoryRequirementsService(getMemoryRequirementsService),
      m_createDocumentService(createDocumentSerivce),
      m_convertLengthService(convertLengthService),
      m_convertResolutionService(convertResolutionService),
      m_getDocumentDimensionsService(getDocumentDimensionsService),
      m_saveDocumentService(saveDocumentService),
      m_addViewService(addViewService),
      m_getViewCoordinatesService(getViewCoordinatesService),
      m_setViewXCoordinateService(setViewXCoordinateService),
      m_setViewYCoordinateService(setViewYCoordinateService),
      m_setViewCoordinatesService(setViewCoordinatesService),
      m_renderingService(renderingService),
      m_getActiveDocumentService(getActiveDocumentService),
      m_setActiveDocumentService(setActiveDocumentService),
      m_viewManager(nullptr)
  {
  }

  void
  ViewFactory::setViewManager(IViewManager<EViewType> *viewManager) {
    m_viewManager = viewManager;
  }

  MainWindow *
  ViewFactory::createMainWindow(QWidget *parent) {
    MainWindow *rv = new MainWindow(parent);

    auto onDocumentSelected = std::make_unique<Controller::MainWindow::OnDocumentSelected>(
      m_setActiveDocumentService);
    rv->hookOnDocumentSelected(std::move(onDocumentSelected))->connect();

    auto onNew = std::make_unique<Controller::MainWindow::OnNew>(m_viewManager);
    rv->hookOnNew(std::move(onNew))->connect();

    auto onSaveAs = std::make_unique<Controller::MainWindow::OnSaveAs>(m_viewManager);
    rv->hookOnSaveAs(std::move(onSaveAs))->connect();

    auto onSave = std::make_unique<Controller::MainWindow::OnSave>(m_viewManager);
    rv->hookOnSave(std::move(onSave))->connect();

    auto onExit = std::make_unique<Controller::MainWindow::OnExit>(m_viewManager);
    rv->hookOnExit(std::move(onExit))->connect();

    return rv;
  }

  NewDocumentDialog *
  ViewFactory::createNewDocumentDialog(QWidget *parent) {
    NewDocumentDialog *rv = new NewDocumentDialog(m_convertLengthService,
      m_convertResolutionService, m_getDocumentPrefabService, m_getMemoryRequirementsService,
      parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);

    auto onAccept = std::make_unique<Controller::NewDocumentDialog::OnAccept>(
      m_createDocumentService, m_viewManager);
    rv->hookOnAccept(std::move(onAccept))->connect();

    return rv;
  }

  FileChooserDialog *
  ViewFactory::createSaveDocumentDialog(QWidget *parent) {
    FileChooserDialog *rv = new FileChooserDialog(parent);
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
  ViewFactory::createDocumentView(Common::Handle documentHandle, QWidget *parent) {
    DocumentView *rv = new DocumentView(m_getDocumentDimensionsService, m_addViewService,
      m_getViewCoordinatesService, m_renderingService, documentHandle, parent);
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
