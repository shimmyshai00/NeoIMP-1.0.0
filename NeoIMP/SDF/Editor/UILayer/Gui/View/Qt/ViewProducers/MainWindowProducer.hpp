#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindowProducer.hpp
 * PURPOSE: Defines the MainWindowProducer class.
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

#include "../../../Controller/IViewProducer.hpp"
#include "../../../Controller/IGuiDismisser.hpp"

#include "../Views/MainWindow.hpp"

#include <fruit/fruit.h>

#include <QPointer>

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  // Class:      MainWindowProducer
  // Purpose:    Produces the main window. The view producers form a hierarchical structure which
  //             mirrors and encodes the compositional layout of the GUI, because each producer
  //             will need to satisfy the requirements of its dependent's controllers and such and
  //             thus the children producers which those controllers want must ultimately be spawned
  //             by the parent producer as well. The producer for the main window sits at the root
  //             of the hierarchy and thus must receive *all* the services the lower downs depend
  //             on in its INJECT constructor as well so they can percolate down as needed to ensure
  //             all those dependencies are satisfied. Generally, higher-up producers thus should
  //             expect more service dependencies than lower-down ones.
  // Parameters: None.
  class MainWindowProducer : public Controller::IViewProducer<>,
                             public Controller::IGuiDismisser
  {
  public:
    INJECT(MainWindowProducer());

    void
    produceView();

    void
    dismissGui();
  private:
    QPointer<Views::MainWindow> m_mainWindow;
  };
}

#endif
