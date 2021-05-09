#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_TOOLBUTTONWIDGET_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_TOOLBUTTONWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolButtonWidget.hpp
 * PURPOSE: Defines the ToolButtonWidget class.
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

#include <QWidget>
#include <QToolButton>
#include <QMenu>
#include <QIcon>
#include <QString>
#include <QAction>

#include <map>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  // Class:      ToolButtonWidget
  // Purpose:    Modifies the QToolButton to consolidate code for changing the shown icon based upon the tool's
  //             action mode.
  // Parameters: None.
  class ToolButtonWidget : public QToolButton {
    Q_OBJECT
  public:
    ToolButtonWidget(QWidget *parent = nullptr);

    void
    addToolMode(int modeId,
                const QIcon &icon,
                const QString &text
               );

    int
    toolMode() const;

    void
    setToolMode(int modeId);
  signals:
    void
    modeSelected(int modeId);
  private:
    int m_toolMode;

    QMenu *m_menu;
    std::map<int, QAction *> m_actions;
  };
}

#endif
