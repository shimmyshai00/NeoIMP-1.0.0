/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewSlideCalc.cpp
 * PURPOSE: Implements the ViewSlideCalc class.
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

#include "ViewSlideCalc.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  ViewSlideCalc::ViewSlideCalc()
    : m_objectLength(0.0),
      m_viewportLength(0.0),
      m_minScale(1.0)
  {
  }

  void
  ViewSlideCalc::setObjectLength(float length) {
    m_objectLength = length;
  }

  void
  ViewSlideCalc::setViewportLength(float length) {
    m_viewportLength = length;
  }

  void
  ViewSlideCalc::setMinScale(float minScale) {
    m_minScale = minScale;
  }

  void
  ViewSlideCalc::setViewportByLengthAndMag(float viewLength, float mag) {
    m_viewportLength = (0.0 + viewLength) / mag;
    m_minScale = 1.0 / mag;
  }

  int
  ViewSlideCalc::getSlideMin() {
    return 0;
  }

  int
  ViewSlideCalc::getSlideMax() {
    return floor((m_objectLength - m_viewportLength) / m_minScale + 0.5);
  }

  int
  ViewSlideCalc::getPageStep() {
    return floor((m_viewportLength / m_minScale) + 0.5);
  }

  int
  ViewSlideCalc::getSlidePosFromOnObj(float onObjPos) {
    return floor((0.0 + onObjPos / m_minScale) + 0.5);
  }

  float
  ViewSlideCalc::getOnObjPosFromSlide(int sliderPos) {
    return (0.0f + sliderPos) * m_minScale;
  }
}
