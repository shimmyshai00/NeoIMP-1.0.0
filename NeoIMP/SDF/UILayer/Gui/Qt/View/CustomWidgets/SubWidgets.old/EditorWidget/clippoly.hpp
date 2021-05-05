#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITORWIDGET_CLIPPOLY_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITORWIDGET_CLIPPOLY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    clippoly.hpp
 * PURPOSE: Helper function to clip a polygon to a rectangle.
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

#include <QPointF>
#include <QLineF>
#include <QRectF>

#include <vector>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditorWidget {
  // Function: clipPoly
  // Purpose:  Clip the contiguous polygon "poly" by the rectangle "rect" into a set of possibly non-contiguous
  //           segments, given as pairs of points in the return value.
  std::vector<QLine> clipPoly(const std::vector<QPoint> &poly, QRect rect);
}

#endif
