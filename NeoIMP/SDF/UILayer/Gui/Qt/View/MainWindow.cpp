/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.cpp
 * PURPOSE: Defines the MainWindow class.
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

#include <MainWindow.hpp>

#include <Events/MainWindowEvent.hpp>

#include <safeConnect.hpp>

#include <AbstractModel/IDocumentAccessService.hpp>
#include <AbstractModel/IUiStateModelService.hpp>

#include <DocumentView.hpp>

#include <StateKeys.hpp>

#include "QtResources/ui_MainWindow.h"

#include <iostream>

namespace SDF::UILayer::Gui::Qt::View {
  MainWindow::MainWindow(AbstractModel::IDocumentAccessService *documentAccessService,
                         AbstractModel::IUiStateModelService<bool> *boolStateModelService,
                         std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string>>
                          dockablesFactory,
                         std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement,
                                                                      IGuiElement *,
                                                                      AbstractModel::Handle
                                                                     >>
                          documentViewFactory,
                         std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                         QWidget *parent
                        )
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_controller(std::move(controller)),
      m_documentAccessService(documentAccessService),
      m_boolStateModelService(boolStateModelService),
      m_dockablesFactory(std::move(dockablesFactory)),
      m_documentViewFactory(std::move(documentViewFactory)),
      m_toolchest(nullptr),
      m_tabs(nullptr)
  {
    m_ui->setupUi(this);

    m_ui->actionToolchest->setChecked(m_boolStateModelService->getStateElement(c_toolboxVisibleKey));
    if(m_boolStateModelService->getStateElement(c_toolboxVisibleKey)) {
      showToolchest();
    }

    safeConnect(m_ui->action_New, &QAction::triggered, [=](bool v) {
      m_controller->handleEvent(std::make_shared<Events::NewClickedEvent>());
    });

    safeConnect(m_ui->action_Open, &QAction::triggered, [=](bool v) {
      m_controller->handleEvent(std::make_shared<Events::OpenClickedEvent>());
    });

    safeConnect(m_ui->actionSave_As, &QAction::triggered, [=](bool v) {
      m_controller->handleEvent(std::make_shared<Events::SaveAsClickedEvent>());
    });

    safeConnect(m_ui->actionE_xit, &QAction::triggered, [=](bool v) {
      m_controller->handleEvent(std::make_shared<Events::ExitClickedEvent>());
    });

    safeConnect(m_ui->actionToolchest, &QAction::toggled, [=](bool checked) {
      std::shared_ptr<Events::ToolchestToggledEvent> event(new Events::ToolchestToggledEvent);
      event->toggleValue = checked;
      m_controller->handleEvent(event);
    });
  }

  MainWindow::~MainWindow() {
    delete m_ui;
  }

  IGuiElement *
  MainWindow::getParent() {
    if(auto p = dynamic_cast<IGuiElement *>(parentWidget())) {
      return p;
    } else {
      return nullptr;
    }
  }

  void
  MainWindow::show() {
    QMainWindow::show();
  }

  void
  MainWindow::close() {
    QMainWindow::close();
  }

  void
  MainWindow::handleEvent(std::shared_ptr<AbstractModel::Events::UiStateChangeEvent<bool>> event) {
    if(event->stateKey == c_toolboxVisibleKey) {
      if(event->newStateVal) {
        showToolchest();
      } else {
        hideToolchest();
      }
    }
  }

  void
  MainWindow::handleEvent(std::shared_ptr<AbstractModel::Events::DocumentEvent> event) {
    if(auto p = dynamic_cast<AbstractModel::Events::DocumentCreated *>(event.get())) { handleDocumentCreated(p); }
    else if(auto p = dynamic_cast<AbstractModel::Events::DocumentOpened *>(event.get())) { handleDocumentOpened(p); }
  }

  void
  MainWindow::showToolchest() {
    if(m_toolchest == nullptr) {
      m_toolchest = dynamic_cast<QDockWidget *>(m_dockablesFactory->create(nullptr, "Toolchest"));
      addDockWidget(::Qt::LeftDockWidgetArea, m_toolchest);
    }
  }

  void
  MainWindow::hideToolchest() {
    if(m_toolchest != nullptr) {
      removeDockWidget(m_toolchest);
      delete m_toolchest;
      m_toolchest = nullptr;
    }
  }

  void
  MainWindow::addDocumentTab(AbstractModel::Handle handle) {
    if(m_tabs == nullptr) {
      // create the tab widget
      m_tabs = new QTabWidget(this);
      m_ui->tabLayout->addWidget(m_tabs, 0, 0);

      safeConnect(m_tabs, &QTabWidget::currentChanged, [=](int index) {
        std::shared_ptr<Events::FocusDocumentChangedEvent> event(new Events::FocusDocumentChangedEvent);
        event->focusedHandle = static_cast<DocumentView *>(m_tabs->currentWidget())->getViewedDocumentHandle();

        m_controller->handleEvent(event);
      });

      // enable commands that require a document
      m_ui->action_Save->setEnabled(true);
      m_ui->actionSave_As->setEnabled(true);
    }

    // Add a new tab to the tab widget.
    std::string documentName(m_documentAccessService->getDocumentName(handle));
    m_tabs->addTab(dynamic_cast<QWidget *>(m_documentViewFactory->create(nullptr, handle)),
                   documentName.c_str()
                  );
  }

  void
  MainWindow::handleDocumentCreated(AbstractModel::Events::DocumentCreated *event) {
    addDocumentTab(event->handle);
  }


  void
  MainWindow::handleDocumentOpened(AbstractModel::Events::DocumentOpened *event) {
    addDocumentTab(event->handle);
  }
}
