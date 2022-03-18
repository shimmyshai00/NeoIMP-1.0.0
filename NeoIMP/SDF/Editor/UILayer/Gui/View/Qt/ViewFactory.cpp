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
#include "../../Controller/MainWindow/OnExit.hpp"
#include "../../Controller/NewDocumentDialog/OnAccept.hpp"
#include "../../Controller/FileChooserDialog/OnAccept_Save.hpp"
#include "../../Controller/DocumentView/OnScroll.hpp"

#include "FileFormatNames.hpp"
#include "makeFileFilterList.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt {
  ViewFactory::ViewFactory(
    AbstractModel::IUiStateManagerService *uiStateManagerService,
    AbstractModel::IMetricsService *metricsService,
    AbstractModel::IDocumentPrefabsService *documentPrefabsService,
    AbstractModel::IDocumentRequirementsService *documentRequirementsService,
    AbstractModel::ICreateImageService *createImageService,
    AbstractModel::IGetDocumentMetricsService *getDocumentMetricsService,
    AbstractModel::IGetViewCoordinatesService *getViewCoordinatesService,
    AbstractModel::ISetViewCoordinatesService *setViewCoordinatesService,
    AbstractModel::IRenderingService *renderingService,
    AbstractModel::ISaveDocumentService *saveDocumentService
  )
    : m_uiStateManagerService(uiStateManagerService),
      m_metricsService(metricsService),
      m_documentPrefabsService(documentPrefabsService),
      m_documentRequirementsService(documentRequirementsService),
      m_createImageService(createImageService),
      m_getDocumentMetricsService(getDocumentMetricsService),
      m_getViewCoordinatesService(getViewCoordinatesService),
      m_setViewCoordinatesService(setViewCoordinatesService),
      m_renderingService(renderingService),
      m_saveDocumentService(saveDocumentService),
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
      m_uiStateManagerService);
    rv->hookOnDocumentSelected(std::move(onDocumentSelected))->connect();

    auto onNew = std::make_unique<Controller::MainWindow::OnNew>(m_viewManager);
    rv->hookOnNew(std::move(onNew))->connect();

    auto onExit = std::make_unique<Controller::MainWindow::OnExit>(m_viewManager);
    rv->hookOnExit(std::move(onExit))->connect();

    return rv;
  }

  NewDocumentDialog *
  ViewFactory::createNewDocumentDialog(QWidget *parent) {
    NewDocumentDialog *rv = new NewDocumentDialog(m_metricsService, m_documentPrefabsService,
      m_documentRequirementsService, parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);

    auto onAccept = std::make_unique<Controller::NewDocumentDialog::OnAccept>(m_createImageService,
      m_viewManager);
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

    auto c = std::make_unique<Controller::FileChooserDialog::OnAccept_Save>(m_uiStateManagerService,
      m_saveDocumentService);
    rv->hookOnAccept(std::move(c))->connect();

    return rv;
  }

  DocumentView *
  ViewFactory::createDocumentView(Common::Handle documentHandle, QWidget *parent) {
    DocumentView *rv = new DocumentView(m_renderingService, m_getDocumentMetricsService,
      m_getViewCoordinatesService, documentHandle, parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);

    auto onHScroll = std::make_unique<Controller::DocumentView::OnHScroll>(
      m_setViewCoordinatesService);
    rv->hookOnHScroll(std::move(onHScroll))->connect();

    auto onVScroll = std::make_unique<Controller::DocumentView::OnVScroll>(
      m_setViewCoordinatesService);
    rv->hookOnVScroll(std::move(onVScroll))->connect();

    return rv;
  }
}
