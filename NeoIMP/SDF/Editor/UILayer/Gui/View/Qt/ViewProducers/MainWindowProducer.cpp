/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindowProducer.cpp
 * PURPOSE: Implements the MainWindowProducer class.
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

#include "MainWindowProducer.hpp"

#include "../../../Controller/MainWindow/OnNew.hpp"
#include "../../../Controller/MainWindow/OnExit.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  MainWindowProducer::MainWindowProducer(
    ProducerFactory<NewDocumentDialogProducer, QWidget *> a_newDocumentDialogProducerFactory
  )
    : m_newDocumentDialogProducerFactory(a_newDocumentDialogProducerFactory)
  {
  }

  void
  MainWindowProducer::produceView() {
    using namespace Controller::MainWindow;

    if(!m_mainWindow) {
      m_mainWindow = new Views::MainWindow();

      m_newDocumentDialogProducer = m_newDocumentDialogProducerFactory(m_mainWindow);

      auto onNewController = std::make_unique<OnNew>(m_newDocumentDialogProducer.get());
      auto onExitController = std::make_unique<OnExit>(this);

      m_mainWindow->hookOnNew(std::move(onNewController))->connect();
      m_mainWindow->hookOnExit(std::move(onExitController))->connect();

      m_mainWindow->show();
    }
  }

  void
  MainWindowProducer::dismissGui() {
    m_mainWindow->close();
  }
}
