/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationController.cpp
 * PURPOSE: The concrete MVC application controller.
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

#include <ApplicationController.hpp>

#include <IMainWindowController.hpp>
#include <MainWindowController.hpp>

#include <View/Windows/MainWindow.hpp>

namespace SDF::UILayer::Qt::Controller {
  class ApplicationController : public IApplicationController {
  public:
    INJECT(ApplicationController(IMainWindowController *mainWindowController)) :
    m_mainWindowController(mainWindowController) {}

    ~ApplicationController() {}

    View::Windows::MainWindow *createMainWindow() {
      View::Windows::MainWindow *mainWindow(new View::Windows::MainWindow);
      mainWindow->setController(m_mainWindowController);

      return mainWindow;
    }
  private:
    IMainWindowController *m_mainWindowController;
  };
}

namespace SDF::UILayer::Qt::Controller {
  fruit::Component<IApplicationController> getApplicationControllerComponent() {
    return fruit::createComponent()
      .bind<IApplicationController, ApplicationController>()
      .install(getMainWindowControllerComponent);
  }
}
