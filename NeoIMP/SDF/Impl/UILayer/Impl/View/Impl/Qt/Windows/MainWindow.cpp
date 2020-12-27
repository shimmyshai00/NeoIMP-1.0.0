/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.cpp
 * PURPOSE: Implementation of the MainWindow class.
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
#include "../QtResources/ui_MainWindow.h"

#include <QSizePolicy>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::Windows {
  MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  m_ui(new Ui::MainWindow)
  {
    m_ui->setupUi(this);

    connect(m_ui->action_New, &QAction::triggered, this, &MainWindow::newClicked);
    connect(m_ui->actionSave_As, &QAction::triggered, this, &MainWindow::saveAsClicked);
    connect(m_ui->actionE_xit, &QAction::triggered, this, &MainWindow::exitClicked);
  }

  MainWindow::~MainWindow() {}

  int MainWindow::addDocumentTab(QString title, QWidget *pageWidget) {
    if(!m_documentTabs) {
      m_documentTabs = new QTabWidget();
      m_documentTabs->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

      connect(m_documentTabs, &QTabWidget::currentChanged, this, &MainWindow::focusTabChanged);

      m_ui->tabLayout->addWidget(m_documentTabs, 0, 0);

      m_documentTabs->show();
    }

    return m_documentTabs->addTab(pageWidget, title);
  }

  void MainWindow::setTabTitle(int index, QString newTitle) {
    if(m_documentTabs) {
      m_documentTabs->setTabText(index, newTitle);
    }
  }

  int MainWindow::getFocusTab() {
    if(!m_documentTabs) {
      return -1; // no tabs available
    } else {
      return m_documentTabs->currentIndex();
    }
  }

  int MainWindow::getDocumentTabIndex(QWidget *pageWidget) {
    return m_documentTabs->indexOf(pageWidget);
  }
  
  QString MainWindow::getDocumentTabTitle(int index) {
    if(!m_documentTabs) {
      return "*** ERROR ***";
    } else {
      return m_documentTabs->tabText(index);
    }
  }

  QWidget *MainWindow::getDocumentTabWidget(int index) {
    if(!m_documentTabs) {
      return nullptr;
    } else {
      return m_documentTabs->widget(index);
    }
  }
}
