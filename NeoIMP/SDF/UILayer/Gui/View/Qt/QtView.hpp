#ifndef SDF_UILAYER_GUI_VIEW_QT_QTVIEW_HPP
#define SDF_UILAYER_GUI_VIEW_QT_QTVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtView.hpp
 * PURPOSE: Defines the QtView template.
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

#include "../../../../Patterns/IConnection.hpp"
#include "../../../Mvc/IController.hpp"
#include "IQtView.hpp"

#include "QtEvent.hpp"

#include <QObject>

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      QtView
  // Purpose:    Provides a general base for Qt-based MVC view widgets. This
  //             builds a coarser view hierarchy atop the Qt widget hierarchy
  //             that is widget system-agnostic, while still allowing Qt to do
  //             most of the hierarchy management.
  // Parameters: QWidgetT - The type of QWidget to build this view from.
  //                        Generally, we follow a CRTP pattern here.
  template<class QWidgetT>
  class QtView : public QWidgetT, public IQtView {
  public:
    QtView(IQtView *parent = nullptr);
    ~QtView();

    QWidget *
    getQWidget();

    void
    show();

    void
    destroyView();

    Patterns::PIConnection
    hookOnDestroy(std::unique_ptr<Mvc::IController<>> controller);
  private:
    QtEvent<> m_onDestroyEvent;
  };
}

#include "QtView.tpp"

#endif
