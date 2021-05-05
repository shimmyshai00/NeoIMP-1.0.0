/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    clippoly.cpp
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

#include <clippoly.hpp>

#include <cmath>
#include <iostream>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditorWidget {
  // Helper function to clip a line to the left region of a vertical line.
  QLine clipLineToLeftOfVertical(QLine line, int verticalX) {
    // Preparation.
    if(line.isNull()) {
      return QLine();
    } else if(line.x2() < line.x1()) {
      // This routine requires x1 <= x2.
      QLine revLine(line.p2(), line.p1());
      QLine revClip(clipLineToLeftOfVertical(revLine, verticalX));
      return QLine(revClip.p2(), revClip.p1());
    }

    if((line.x1() <= line.x2()) && (line.x2() <= verticalX)) {
      // No clipping.
      return line;
    } else if((line.x1() < verticalX) && (verticalX < line.x2())) {
      // Nontrivial clipping.
      // Get the intersection point.
      // The equation of the line is:
      //     y - y_1 = m(x - x_1)
      //
      // so with the vertical as x = verticalX, we need
      //     y - y_1 = m(verticalX - x_1)
      //
      // thus
      //     y = m(verticalX - x_1) + y_1.
      //
      float slope((0.0f + line.y2() - line.y1())/(0.0f + line.x2() - line.x1()));
      float isectY(slope * (verticalX - line.x1()) + line.y1());
      return QLine(line.p1(), QPoint(verticalX, floor(isectY + 0.5f)));
    } else if((verticalX <= line.x1()) && (line.x1() <= line.x2())) {
      // Complete clipping.
      return QLine();
    }
  }

  // Helper function to clip a line to the right region of a vertical line.
  QLine clipLineToRightOfVertical(QLine line, int verticalX) {
    // This is effectively the mirror image of the preceding case.
    QLine mirrorLine(QPoint(-line.x1(), line.y1()), QPoint(-line.x2(), line.y2()));
    QLine mirrorClip(clipLineToLeftOfVertical(mirrorLine, -verticalX));
    return QLine(QPoint(-mirrorClip.x1(), mirrorClip.y1()), QPoint(-mirrorClip.x2(), mirrorClip.y2()));
  }

  // Helper function to clip a line to the bottom of a horizontal line.
  QLine clipLineToBottomOfHorizontal(QLine line, int horizontalY) {
    // Do this as 90-degree rotation of one of the preceding cases.
    QLine rotatedLine(QPoint(-line.y1(), line.x1()), QPoint(-line.y2(), line.x2()));
    QLine rotatedClip(clipLineToLeftOfVertical(rotatedLine, -horizontalY));
    return QLine(QPoint(rotatedClip.y1(), -rotatedClip.x1()), QPoint(rotatedClip.y2(), -rotatedClip.x2()));
  }

  // Helper function to clip a line to the top of a horizontal line.
  QLine clipLineToTopOfHorizontal(QLine line, int horizontalY) {
    // Do this as 90-degree rotation of one of the preceding cases.
    QLine rotatedLine(QPoint(line.y1(), -line.x1()), QPoint(line.y2(), -line.x2()));
    QLine rotatedClip(clipLineToRightOfVertical(rotatedLine, -horizontalY));
    return QLine(QPoint(-rotatedClip.y1(), rotatedClip.x1()), QPoint(-rotatedClip.y2(), rotatedClip.x2()));
  }

  // Helper function to clip a line to a rectangle.
  QLine clipLine(QLine line, QRect rect) {
    // Clip to each side of the rectangle in turn.
    QLine rv(line);

    rv = clipLineToLeftOfVertical(rv, rect.right());
    rv = clipLineToTopOfHorizontal(rv, rect.bottom());
    rv = clipLineToRightOfVertical(rv, rect.left());
    rv = clipLineToBottomOfHorizontal(rv, rect.top());

    return rv;
  }

  std::vector<QLine> clipPoly(const std::vector<QPoint> &poly, QRect rect) {
    std::vector<QLine> rv;

    for(std::size_t i(0); i < poly.size(); ++i) {
      QPoint p1(poly[i]);
      QPoint p2(poly[(i + 1) % poly.size()]);
      QLine edge(p1, p2);

      // Clip this line to the rectangle.
      QLine edgeClipped(clipLine(edge, rect));
      if(!edgeClipped.isNull()) {
        // Leave off null lines
        rv.push_back(edgeClipped);
      }
    }

    return rv;
  }
}
