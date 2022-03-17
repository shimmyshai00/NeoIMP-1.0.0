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

#include "../../Controller/MainWindow/OnNew.hpp"
#include "../../Controller/MainWindow/OnExit.hpp"
#include "../../Controller/NewDocumentDialog/OnAccept.hpp"
#include "../../Controller/DocumentView/OnScroll.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt {
  ViewFactory::ViewFactory(
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
    : m_metricsService(metricsService),
      m_documentPrefabsService(documentPrefabsService),
      m_documentRequirementsService(documentRequirementsService),
      m_createImageService(createImageService),
      m_getDocumentMetricsService(getDocumentMetricsService),
      m_getViewCoordinatesService(getViewCoordinatesService),
      m_setViewCoordinatesService(setViewCoordinatesService),
      m_renderingService(renderingService),
      m_saveDocumentService(saveDocumentService)
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

    std::unique_ptr<IController<>> nullaryController;

    nullaryController = std::make_unique<Controller::MainWindow::OnNew>(m_viewManager);
    rv->hookOnNew(std::move(nullaryController))->connect();

    nullaryController = std::make_unique<Controller::MainWindow::OnExit>(m_viewManager);
    rv->hookOnExit(std::move(nullaryController))->connect();

    return rv;
  }

  NewDocumentDialog *
  ViewFactory::createNewDocumentDialog(QWidget *parent) {
    NewDocumentDialog *rv = new NewDocumentDialog(m_metricsService, m_documentPrefabsService,
      m_documentRequirementsService, parent);

    std::unique_ptr<IController<AbstractModel::Defs::ImageSpec>> acceptController;
    acceptController = std::make_unique<Controller::NewDocumentDialog::OnAccept>(
      m_createImageService, m_viewManager);
    rv->hookOnAccept(std::move(acceptController))->connect();

    rv->setAttribute(::Qt::WA_DeleteOnClose);

    return rv;
  }

  FileChooserDialog *
  ViewFactory::createSaveDocumentDialog(QWidget *parent) {
    
  }

  DocumentView *
  ViewFactory::createDocumentView(Common::Handle documentHandle, QWidget *parent) {
    DocumentView *rv = new DocumentView(m_renderingService, m_getDocumentMetricsService,
      m_getViewCoordinatesService, documentHandle, parent);
    rv->setAttribute(::Qt::WA_DeleteOnClose);

    std::unique_ptr<IController<Common::Handle, float>> hScrollController;
    hScrollController = std::make_unique<Controller::DocumentView::OnHScroll>(
      m_setViewCoordinatesService);
    rv->hookOnHScroll(std::move(hScrollController))->connect();

    std::unique_ptr<IController<Common::Handle, float>> vScrollController;
    vScrollController = std::make_unique<Controller::DocumentView::OnVScroll>(
      m_setViewCoordinatesService);
    rv->hookOnVScroll(std::move(vScrollController))->connect();

    return rv;
  }
}
