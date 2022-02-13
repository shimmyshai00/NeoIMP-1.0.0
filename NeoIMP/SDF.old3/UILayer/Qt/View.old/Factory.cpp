/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.cpp
 * PURPOSE: Defines the Factory class.
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

#include "Factory.hpp"

#include "MainWindow.hpp"
#include "NewDocumentDialog.hpp"

namespace SDF::UILayer::Qt::View {
  Factory::Factory(AbstractModel::IMetricsService *metricsService,
                   IControllerFactory *controllerFactory
                  )
    : m_metricsService(metricsService),
      m_controllerFactory(controllerFactory)
  {
    m_controllerFactory->setViewFactory(this);
  }

  QMainWindow *
  Factory::createMainWindow() {
    MainWindow *rv(new MainWindow);

    rv->hookNewMenuItem(m_controllerFactory->makeNewMenuItemController(rv));
    rv->hookExitMenuItem(m_controllerFactory->makeExitMenuItemController(rv));

    return rv;
  }

  QDialog *
  Factory::createNewDocumentDialog(QWidget *parent) {
    NewDocumentDialog *rv(new NewDocumentDialog(m_metricsService, parent));

    return rv;
  }
}
