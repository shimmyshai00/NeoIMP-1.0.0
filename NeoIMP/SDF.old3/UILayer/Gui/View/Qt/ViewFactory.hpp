#ifndef SDF_UILAYER_GUI_VIEW_QT_VIEWFACTORY_HPP
#define SDF_UILAYER_GUI_VIEW_QT_VIEWFACTORY_HPP

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

#include "../../../AbstractModel/IMetricsService.hpp"
#include "../../../AbstractModel/ICreateImageService.hpp"

#include "../../Controller/IGuiController.hpp"
#include "IQtView.hpp"

#include "MainWindow.hpp"
#include "NewDocumentDialog.hpp"

#include <fruit/fruit.h>

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      ViewFactory
  // Purpose:    Centralizes the construction of views.
  // Parameters: None.
  class ViewFactory {
  public:
    INJECT(ViewFactory(AbstractModel::IMetricsService *metricsService,
                       AbstractModel::ICreateImageService *createImageService
                      )
          );

    MainWindow *
    createMainWindow(IQtView *parent,
                     Controller::IGuiController *guiController
                    );

    NewDocumentDialog *
    createNewDocumentDialog(IQtView *parent);
  private:
    AbstractModel::IMetricsService *m_metricsService;
    AbstractModel::ICreateImageService *m_createImageService;
  };
}

#endif
