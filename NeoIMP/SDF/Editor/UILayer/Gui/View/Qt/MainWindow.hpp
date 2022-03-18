#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_MAINWINDOW_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_MAINWINDOW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.hpp
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

#include "../../../../../Common/IConnection.hpp"
#include "../../../../../Common/Handle.hpp"
#include "../../IViewManager.hpp"
#include "../EViewType.hpp"
#include "../IController.hpp"
#include "QtEvent.hpp"

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>
#include <QPointer>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // Class:      MainWindow
  // Purpose:    Implements the Qt GUI's main window.
  // Parameters: None.
  class MainWindow : public QMainWindow {
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void
    addTabPane(std::string tabName, QWidget *pane);

    void
    deleteTabPane(QWidget *pane);

    Common::PIConnection
    hookOnDocumentSelected(std::unique_ptr<IController<Common::Handle>> controller);

    Common::PIConnection
    hookOnNew(std::unique_ptr<IController<>> controller);

    Common::PIConnection
    hookOnSaveAs(std::unique_ptr<IController<>> controller);

    Common::PIConnection
    hookOnSave(std::unique_ptr<IController<>> controller);

    Common::PIConnection
    hookOnExit(std::unique_ptr<IController<>> controller);
  private:
    Ui::MainWindow *m_ui;
    QPointer<QTabWidget> m_tabWidget;

    QMetaObject::Connection m_tabSwitchHandlerConn;

    QtEvent<Common::Handle> m_onDocumentSelected;
    QtEvent<> m_onNew;
    QtEvent<> m_onSaveAs;
    QtEvent<> m_onSave;
    QtEvent<> m_onExit;

    void
    enableDocumentRequiringFeatures();

    void
    disableDocumentRequiringFeatures();
  };
}

#endif
