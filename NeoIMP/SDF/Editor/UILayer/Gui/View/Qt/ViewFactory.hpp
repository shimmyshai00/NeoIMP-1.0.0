#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWFACTORY_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewFactory.hpp
 * PURPOSE: Defines the ViewFactory class.
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

#include "../../../../../Common/Handle.hpp"
#include "../../../AbstractModel/IMetricsService.hpp"
#include "../../../AbstractModel/IDocumentPrefabsService.hpp"
#include "../../../AbstractModel/IDocumentRequirementsService.hpp"
#include "../../../AbstractModel/ICreateImageService.hpp"
#include "../../../AbstractModel/IGetDocumentMetricsService.hpp"
#include "../../../AbstractModel/IGetViewCoordinatesService.hpp"
#include "../../../AbstractModel/ISetViewCoordinatesService.hpp"
#include "../../../AbstractModel/IRenderingService.hpp"
#include "../../IViewManager.hpp"
#include "../EViewType.hpp"

#include "MainWindow.hpp"
#include "NewDocumentDialog.hpp"
#include "DocumentView.hpp"

#include <QWidget>
#include <fruit/fruit.h>

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // Class:      ViewFactory
  // Purpose:    Centralizes the creation of views.
  // Parameters: None.
  class ViewFactory {
  public:
    INJECT(ViewFactory(
      AbstractModel::IMetricsService *metricsService,
      AbstractModel::IDocumentPrefabsService *documentPrefabsService,
      AbstractModel::IDocumentRequirementsService *documentRequirementsService,
      AbstractModel::ICreateImageService *createImageService,
      AbstractModel::IGetDocumentMetricsService *getDocumentMetricsService,
      AbstractModel::IGetViewCoordinatesService *getViewCoordinatesService,
      AbstractModel::ISetViewCoordinatesService *setViewCoordinatesService,
      AbstractModel::IRenderingService *renderingService
    ));

    void
    setViewManager(IViewManager<EViewType> *viewManager);

    MainWindow *
    createMainWindow(QWidget *parent = nullptr);

    NewDocumentDialog *
    createNewDocumentDialog(QWidget *parent = nullptr);

    DocumentView *
    createDocumentView(Common::Handle documentHandle, QWidget *parent = nullptr);
  private:
    AbstractModel::IMetricsService *m_metricsService;
    AbstractModel::IDocumentPrefabsService *m_documentPrefabsService;
    AbstractModel::IDocumentRequirementsService *m_documentRequirementsService;
    AbstractModel::ICreateImageService *m_createImageService;
    AbstractModel::IGetDocumentMetricsService *m_getDocumentMetricsService;
    AbstractModel::IGetViewCoordinatesService *m_getViewCoordinatesService;
    AbstractModel::ISetViewCoordinatesService *m_setViewCoordinatesService;
    AbstractModel::IRenderingService *m_renderingService;

    IViewManager<EViewType> *m_viewManager;
  };
}

#endif
