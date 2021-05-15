/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomToolConfigPane.cpp
 * PURPOSE: Implements the ZoomToolConfigPane class.
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

#include "ZoomToolConfigPane.hpp"

namespace SDF::UILayer::Gui::Qt::View {
  ZoomToolConfigPane::ZoomToolConfigPane(QWidget *parent)
    : QtGuiElement<QWidget>(parent),
      m_gridLayout(nullptr),
      m_zoomPowerLabel(nullptr),
      m_zoomPowerSlider(nullptr)
  {
    // Create the widget layout.
    m_gridLayout = new QGridLayout(this);
    m_zoomPowerLabel = new QLabel("Zoom Power:", nullptr);
    m_zoomPowerSlider = new CustomWidgets::EditableSlider(10, 100, 1, ::Qt::Horizontal, nullptr);
    m_zoomPowerSlider->setDenom(10);

    m_gridLayout->addWidget(m_zoomPowerLabel, 0, 0);
    m_gridLayout->addWidget(m_zoomPowerSlider, 0, 1);
  }
}
