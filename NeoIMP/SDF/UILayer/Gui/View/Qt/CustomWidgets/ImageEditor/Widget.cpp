/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Widget.cpp
 * PURPOSE: Implements the Widget class.
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

#include "Widget.hpp"

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor {
  Widget::Widget(AbstractModel::IRenderingService *renderingService,
                 QWidget *parent
                )
    : QWidget(parent),
      m_gridLayout(new QGridLayout(this)),
      m_horizontalRuler(new Impl::RulerWidget(::Qt::Horizontal, nullptr)),
      m_verticalRuler(new Impl::RulerWidget(::Qt::Vertical, nullptr)),
      m_renderDisplayWidget(new Impl::RenderDisplayWidget(renderingService, nullptr))
  {
    m_gridLayout->addWidget(m_horizontalRuler, 1, 0);
    m_gridLayout->addWidget(m_verticalRuler, 0, 1);
    m_gridLayout->addWidget(m_renderDisplayWidget, 1, 1);
  }

  Widget::~Widget() {
  }

  void
  Widget::setEditedImage(Common::Handle imageHandle) {
    printf("psize: %d %d\n", size().width(), size().height());
    m_renderDisplayWidget->setDisplayedImage(imageHandle);
    update();
  }

  float
  Widget::viewportX1() const {
    return m_renderDisplayWidget->viewportX1();
  }

  float
  Widget::viewportY1() const {
    return m_renderDisplayWidget->viewportY1();
  }

  float
  Widget::viewportX2() const {
    return m_renderDisplayWidget->viewportX2();
  }

  float
  Widget::viewportY2() const {
    return m_renderDisplayWidget->viewportY2();
  }
}
