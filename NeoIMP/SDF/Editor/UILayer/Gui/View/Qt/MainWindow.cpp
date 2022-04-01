/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.cpp
 * PURPOSE: Implements the MainWindow class.
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

#include "MainWindow.hpp"

#include "../../Controller/MainWindow/OnExit.hpp"
#include "../../state_keys.hpp"
#include "DocumentView.hpp"

#include "Resources/ui_MainWindow.h"

#include <QGridLayout>

namespace SDF::Editor::UILayer::Gui::View::Qt {
  MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow)
  {
    m_ui->setupUi(this);

    connect(m_ui->action_New, &QAction::triggered, [&](){ m_onNew.trigger(); });
    connect(m_ui->action_Open, &QAction::triggered, [&](){ m_onOpen.trigger(); });
    connect(m_ui->actionSave_As, &QAction::triggered, [&](){ m_onSaveAs.trigger(); });
    connect(m_ui->action_Save, &QAction::triggered, [&](){ m_onSave.trigger(); });
    connect(m_ui->actionE_xit, &QAction::triggered, [&](){ m_onExit.trigger(); });
  }

  MainWindow::~MainWindow() {
    delete m_ui;
  }

  void
  MainWindow::addTabPane(std::string tabName, QWidget *pane) {
    bool firstTab(false);

    if(!m_tabWidget) {
      m_tabWidget = new QTabWidget(nullptr);
      m_ui->gridLayout_2->addWidget(m_tabWidget, 0, 0);
      m_tabWidget->show();

      m_tabSwitchHandlerConn = connect(m_tabWidget, &QTabWidget::tabBarClicked,
        [=](int index) {
          if(auto p = dynamic_cast<DocumentView *>(m_tabWidget->widget(index))) {
            this->m_onDocumentSelected.trigger(p->getDocumentHandle());
          }
        }
      );

      firstTab = true;
      enableDocumentRequiringFeatures();
    }

    m_tabWidget->addTab(pane, QString(tabName.c_str()));
    if(firstTab) {
      if(auto p = dynamic_cast<DocumentView *>(pane)) {
        m_onDocumentSelected.trigger(p->getDocumentHandle());
      }
    }
  }

  void
  MainWindow::deleteTabPane(QWidget *pane) {
    if(m_tabWidget) {
      m_tabWidget->removeTab(m_tabWidget->indexOf(pane));
      if(m_tabWidget->count() == 0) {
        // all tabs gone - destroy the tab widget!
        m_tabWidget->hide();
        disconnect(m_tabSwitchHandlerConn);
        m_ui->gridLayout_2->removeWidget(m_tabWidget);
        disableDocumentRequiringFeatures();
      }
    }
  }

  Common::PIConnection
  MainWindow::hookOnDocumentSelected(std::unique_ptr<IController<Common::Handle>> controller) {
    return m_onDocumentSelected.hook(std::move(controller));
  }

  Common::PIConnection
  MainWindow::hookOnNew(std::unique_ptr<IController<>> controller) {
    return m_onNew.hook(std::move(controller));
  }

  Common::PIConnection
  MainWindow::hookOnOpen(std::unique_ptr<IController<>> controller) {
    return m_onOpen.hook(std::move(controller));
  }

  Common::PIConnection
  MainWindow::hookOnSaveAs(std::unique_ptr<IController<>> controller) {
    return m_onSaveAs.hook(std::move(controller));
  }

  Common::PIConnection
  MainWindow::hookOnSave(std::unique_ptr<IController<>> controller) {
    return m_onSave.hook(std::move(controller));
  }

  Common::PIConnection
  MainWindow::hookOnExit(std::unique_ptr<IController<>> controller) {
    return m_onExit.hook(std::move(controller));
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // Private members.
  void
  MainWindow::enableDocumentRequiringFeatures() {
    m_ui->actionSave_As->setEnabled(true);
    m_ui->action_Save->setEnabled(true);
  }

  void
  MainWindow::disableDocumentRequiringFeatures() {
    m_ui->actionSave_As->setEnabled(false);
    m_ui->action_Save->setEnabled(false);
  }
}
