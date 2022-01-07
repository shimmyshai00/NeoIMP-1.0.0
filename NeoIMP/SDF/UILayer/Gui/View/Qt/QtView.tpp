#ifndef SDF_UILAYER_GUI_VIEW_QT_QTVIEW_TPP
#define SDF_UILAYER_GUI_VIEW_QT_QTVIEW_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtView.tpp
 * PURPOSE: Implements the QtView template.
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

namespace SDF::UILayer::Gui::View::Qt {
  template<class QWidgetT>
  QtView<QWidgetT>::QtView(IQtView *parent)
    : QWidgetT((parent != nullptr) ? parent->getQWidget() : nullptr)
  {
    if(parent != nullptr) {
      parent->registerChild(this);
    }

    QWidgetT::connect(this, &QWidgetT::destroyed, [&]() { m_onDestroyEvent.trigger(); });
  }

  template<class QWidgetT>
  QtView<QWidgetT>::~QtView() {
    // Excise from the widget system-agnostic view hierarchy.
    unregisterSelf();
  }

  template<class QWidgetT>
  QWidget *
  QtView<QWidgetT>::getQWidget() {
    return this;
  }

  template<class QWidgetT>
  void
  QtView<QWidgetT>::show() {
    QWidgetT::show();
  }

  template<class QWidgetT>
  void
  QtView<QWidgetT>::destroyView() {
    QWidgetT::close();
  }

  template<class QWidgetT>
  Patterns::PIConnection
  QtView<QWidgetT>::hookOnDestroy(std::unique_ptr<Mvc::IController<>> controller) {
    return m_onDestroyEvent.hook(std::move(controller));
  }
}

#endif
