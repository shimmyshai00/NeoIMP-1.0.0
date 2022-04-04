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

#include "producer_ids.hpp"

#include "../../../Controller/MainWindow/OnDocumentSelected.hpp"
#include "../../../Controller/MainWindow/OnNew.hpp"
#include "../../../Controller/MainWindow/OnOpen.hpp"
#include "../../../Controller/MainWindow/OnSaveAs.hpp"
#include "../../../Controller/MainWindow/OnSave.hpp"
#include "../../../Controller/MainWindow/OnExit.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  // Listening facilities.
  class MainWindowProducer::DocumentAddedListener : public Common::IListener<Common::Handle> {
  public:
    DocumentAddedListener(MainWindowProducer *a_outer) : m_outer(a_outer) {}

    void
    notify(Common::Handle a_handle) {
      if(a_handle != Common::HANDLE_INVALID) {
        auto documentViewProducer = new DocumentViewProducer(m_outer->m_services,
          MAIN_WINDOW_DOCUMENT_VIEW_PRODUCERS_BEGIN + a_handle, m_outer, a_handle);

        documentViewProducer->produceView();
      }
    }
  private:
    MainWindowProducer *m_outer;
  };
}

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  MainWindowProducer::MainWindowProducer(deps_t a_deps)
    : AProducerNode(MAIN_WINDOW_PRODUCER, nullptr),
      m_services(a_deps)
  {
    using namespace AbstractModel::DocumentMgmt;

    // Create producers for the new-document dialog, document views
    auto *newDocumentDialogProducer = new NewDocumentDialogProducer(m_services,
      MAIN_WINDOW_NEW_DOCUMENT_DIALOG_PRODUCER, this);
    auto *fileOpenDialogProducer = new FileDialogProducer(m_services,
      MAIN_WINDOW_OPEN_DIALOG_PRODUCER, this, FileDialogProducer::MODE_OPEN);
    auto *fileSaveAsDialogProducer = new FileDialogProducer(m_services,
      MAIN_WINDOW_SAVE_AS_DIALOG_PRODUCER, this, FileDialogProducer::MODE_SAVE);

    m_documentAddedListenerConn = m_services.get<IDocumentAddedService>()->addListener(
      std::make_unique<DocumentAddedListener>(this));
    m_documentAddedListenerConn->connect();
  }

  MainWindowProducer::~MainWindowProducer() {
    m_documentAddedListenerConn->disconnect();
  }

  QWidget *
  MainWindowProducer::getViewWidget() {
    return m_mainWindow;
  }

  void
  MainWindowProducer::produceView() {
    using namespace Controller::MainWindow;

    if(!m_mainWindow) {
      m_mainWindow = new Views::MainWindow();

      auto *newDocumentDialogProducer = findChildById<NewDocumentDialogProducer>(
        MAIN_WINDOW_NEW_DOCUMENT_DIALOG_PRODUCER);
      auto *fileOpenDialogProducer = findChildById<FileDialogProducer>(
        MAIN_WINDOW_OPEN_DIALOG_PRODUCER);
      auto *fileSaveAsDialogProducer = findChildById<FileDialogProducer>(
        MAIN_WINDOW_SAVE_AS_DIALOG_PRODUCER);

      auto onDocumentSelectedController = std::make_unique<OnDocumentSelected>(m_services);
      auto onNewController = std::make_unique<OnNew>(newDocumentDialogProducer);
      auto onOpenController = std::make_unique<OnOpen>(fileOpenDialogProducer);
      auto onSaveAsController = std::make_unique<OnSaveAs>(fileSaveAsDialogProducer);
      auto onSaveController = std::make_unique<OnSave>(m_services, fileSaveAsDialogProducer);
      auto onExitController = std::make_unique<OnExit>(this);

      m_mainWindow->hookOnDocumentSelected(std::move(onDocumentSelectedController))->connect();
      m_mainWindow->hookOnNew(std::move(onNewController))->connect();
      m_mainWindow->hookOnOpen(std::move(onOpenController))->connect();
      m_mainWindow->hookOnSaveAs(std::move(onSaveAsController))->connect();
      m_mainWindow->hookOnSave(std::move(onSaveController))->connect();
      m_mainWindow->hookOnExit(std::move(onExitController))->connect();

      m_mainWindow->show();
    }
  }

  void
  MainWindowProducer::dismissGui() {
    m_mainWindow->close();
  }
}
