/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolButtonWidget.cpp
 * PURPOSE: Implements the ToolButtonWidget class.
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

#include "ToolButtonWidget.hpp"

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  ToolButtonWidget::ToolButtonWidget(QWidget *parent)
    : QToolButton(parent),
      m_toolMode(-1),
      m_menu(new QMenu)
  {
  }

  void
  ToolButtonWidget::addToolMode(int modeId,
                                const QIcon &icon,
                                const QString &text
                               )
  {
    if(m_actions.find(modeId) == m_actions.end()) {
      m_actions[modeId] = m_menu->addAction(icon, text, this, [=]() { modeSelected(modeId); });
      if(m_actions.size() == 1) { // first mode added
        m_toolMode = modeId;
        setMenu(m_menu);
        setPopupMode(QToolButton::DelayedPopup);
      }
    }
  }

  int
  ToolButtonWidget::toolMode() const {
    return m_toolMode;
  }

  void
  ToolButtonWidget::setToolMode(int modeId) {
    if(m_actions.find(modeId) != m_actions.end()) {
      m_toolMode = modeId;

      // Set the icon accordingly.
      setIcon(m_actions[modeId]->icon());
    }
  }
}
