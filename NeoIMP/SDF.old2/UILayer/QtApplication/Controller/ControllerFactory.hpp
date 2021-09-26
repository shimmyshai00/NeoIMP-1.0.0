#ifndef SDF_UILAYER_QTAPPLICATION_CONTROLLER_CONTROLLERFACTORY_HPP
#define SDF_UILAYER_QTAPPLICATION_CONTROLLER_CONTROLLERFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerFactory.hpp
 * PURPOSE: Defines the ControllerFactory class.
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

#include "../../AbstractModel/Services/IMeasurementConversionService.hpp"
#include "../View/Events/MainWindowEvent.hpp"
#include "../View/IViewFactory.hpp"
#include "IControllerFactory.hpp"
#include "IController.hpp"

#include <QMainWindow>
#include <QDialog>
#include <fruit/fruit.h>
#include <memory>

namespace SDF::UILayer::QtApplication::Controller {
  // Class:      ControllerFactory
  // Purpose:    Creates new Qt MVC controllers.
  // Parameters: None.
  class ControllerFactory : public IControllerFactory {
  public:
    INJECT(ControllerFactory(AbstractModel::Services::IMeasurementConversionService *measurementConversionService));

    std::unique_ptr<IController<QMainWindow, View::Events::MainWindowEvent>>
    createMainWindowController(View::IViewFactory *viewFactory);

    std::unique_ptr<IController<QDialog, View::Events::DialogEvent>>
    createNewDocumentDialogController();
  private:
    AbstractModel::Services::IMeasurementConversionService *m_measurementConversionService;
  };
}

#endif
