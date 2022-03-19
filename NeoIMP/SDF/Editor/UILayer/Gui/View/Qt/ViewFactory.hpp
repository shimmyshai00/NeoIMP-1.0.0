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
#include "../../../AbstractModel/Create/IGetDocumentPrefabService.hpp"
#include "../../../AbstractModel/Create/IGetMemoryRequirementsService.hpp"
#include "../../../AbstractModel/Create/ICreateDocumentService.hpp"
#include "../../../AbstractModel/Metrics/IConvertLengthService.hpp"
#include "../../../AbstractModel/Metrics/IConvertResolutionService.hpp"
#include "../../../AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../AbstractModel/Storage/IGetDocumentFileInfoService.hpp"
#include "../../../AbstractModel/Storage/ISaveDocumentService.hpp"
#include "../../../AbstractModel/Viewing/IAddViewService.hpp"
#include "../../../AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../../AbstractModel/Viewing/ISetViewXCoordinateService.hpp"
#include "../../../AbstractModel/Viewing/ISetViewYCoordinateService.hpp"
#include "../../../AbstractModel/Viewing/ISetViewCoordinatesService.hpp"
#include "../../../AbstractModel/Viewing/IRenderingService.hpp"
#include "../../../AbstractModel/Editing/IGetActiveDocumentService.hpp"
#include "../../../AbstractModel/Editing/ISetActiveDocumentService.hpp"
#include "../../IViewManager.hpp"
#include "../EViewType.hpp"

#include "MainWindow.hpp"
#include "NewDocumentDialog.hpp"
#include "FileChooserDialog.hpp"
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
      AbstractModel::Create::IGetDocumentPrefabService *getDocumentPrefabService,
      AbstractModel::Create::IGetMemoryRequirementsService *getMemoryRequirementsService,
      AbstractModel::Create::ICreateDocumentService *createDocumentSerivce,
      AbstractModel::Metrics::IConvertLengthService *convertLengthService,
      AbstractModel::Metrics::IConvertResolutionService *convertResolutionService,
      AbstractModel::Metrics::IGetDocumentDimensionsService *getDocumentDimensionsService,
      AbstractModel::Storage::IGetDocumentFileInfoService *getDocumentFileInfoService,
      AbstractModel::Storage::ISaveDocumentService *saveDocumentService,
      AbstractModel::Viewing::IAddViewService *addViewService,
      AbstractModel::Viewing::IGetViewCoordinatesService *getViewCoordinatesService,
      AbstractModel::Viewing::ISetViewXCoordinateService *setViewXCoordinateService,
      AbstractModel::Viewing::ISetViewYCoordinateService *setViewYCoordinateService,
      AbstractModel::Viewing::ISetViewCoordinatesService *setViewCoordinatesService,
      AbstractModel::Viewing::IRenderingService *renderingService,
      AbstractModel::Editing::IGetActiveDocumentService *getActiveDocumentService,
      AbstractModel::Editing::ISetActiveDocumentService *setActiveDocumentService
    ));

    void
    setViewManager(IViewManager<EViewType> *viewManager);

    MainWindow *
    createMainWindow(QWidget *parent = nullptr);

    NewDocumentDialog *
    createNewDocumentDialog(QWidget *parent = nullptr);

    FileChooserDialog *
    createSaveDocumentDialog(QWidget *parent = nullptr);

    DocumentView *
    createDocumentView(Common::Handle documentHandle, QWidget *parent = nullptr);
  private:
    AbstractModel::Create::IGetDocumentPrefabService *m_getDocumentPrefabService;
    AbstractModel::Create::IGetMemoryRequirementsService *m_getMemoryRequirementsService;
    AbstractModel::Create::ICreateDocumentService *m_createDocumentService;
    AbstractModel::Metrics::IConvertLengthService *m_convertLengthService;
    AbstractModel::Metrics::IConvertResolutionService *m_convertResolutionService;
    AbstractModel::Metrics::IGetDocumentDimensionsService *m_getDocumentDimensionsService;
    AbstractModel::Storage::IGetDocumentFileInfoService *m_getDocumentFileInfoService;
    AbstractModel::Storage::ISaveDocumentService *m_saveDocumentService;
    AbstractModel::Viewing::IAddViewService *m_addViewService;
    AbstractModel::Viewing::IGetViewCoordinatesService *m_getViewCoordinatesService;
    AbstractModel::Viewing::ISetViewXCoordinateService *m_setViewXCoordinateService;
    AbstractModel::Viewing::ISetViewYCoordinateService *m_setViewYCoordinateService;
    AbstractModel::Viewing::ISetViewCoordinatesService *m_setViewCoordinatesService;
    AbstractModel::Viewing::IRenderingService *m_renderingService;
    AbstractModel::Editing::IGetActiveDocumentService *m_getActiveDocumentService;
    AbstractModel::Editing::ISetActiveDocumentService *m_setActiveDocumentService;

    IViewManager<EViewType> *m_viewManager;
  };
}

#endif
