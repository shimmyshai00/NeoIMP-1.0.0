#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_VIEWPORTCALCULATOR_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_VIEWPORTCALCULATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewportCalculator.hpp
 * PURPOSE: Defines the ViewportCalculator class.
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

#include <memory>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  class ViewportTransform;

  // Class:      ViewportCalculator
  // Purpose:    Calculates the relations between a viewport onto a 2D space and the underlying 2D space itself, e.g.
  //             how to translate between viewport coordinates and space coordinates (Both are notionally measured in
  //             pixels, however the viewport can be transformed in different ways.).
  // Parameters: None.
  class ViewportCalculator {
  public:
    // Function:   ViewportCalculator
    // Purpose:    Creates a new viewport calculator. When started, the upper-left viewport corner will correspond with
    //             space coordinates (0, 0).
    // Parameters: viewportWidth - The width of the viewport in pixels.
    //             viewportHeight - The height of the viewport in pixels.
    ViewportCalculator(float viewportWidth,
                       float viewportHeight
                      );

    // Function:   getWidth
    // Purpose:    Get the untransformed width of the viewport.
    // Parameters: None.
    // Returns:    The width value.
    float
    getWidth() const;

    // Function:   getHeight
    // Purpose:    Get the untransformed height of the viewport.
    // Parameters: None.
    // Returns:    The height value.
    float
    getHeight() const;

    // Function:   setWidth
    // Purpose:    Changes the width of the untransformed viewport.
    // Parameters: width - The new width to set.
    // Returns:    None.
    void
    setWidth(float width);

    // Function:   setHeight
    // Purpose:    Changes the height of the untransformed viewport.
    // Parameters: height - The new height to set.
    // Returns:    None.
    void
    setHeight(float height);

    // Function:   addTransform
    // Purpose:    Adds a viewport transform to the calculator.
    // Parameters: transform - The transform to add.
    // Returns:    None.
    void
    addTransform(std::unique_ptr<ViewportTransform> transform);

    // Function:   clearActiveTransforms
    // Purpose:    Clear all active viewport transforms.
    // Parameters: None.
    // Returns:    None.
    void
    clearActiveTransforms();

    // Function:   getSpaceCoord
    // Purpose:    Get the space coordinates corresponding to a particular point in the viewport.
    // Parameters: viewportX - The X-coordinate of the viewport point.
    //             viewportY - The Y-coordinate of the viewport point.
    // Returns:    The space coordinate values as a pair.
    std::pair<float, float>
    getSpaceCoord(float viewportX, float viewportY);
  private:
    float m_viewportWidth;
    float m_viewportHeight;

    std::unique_ptr<ViewportTransform> m_aggregateTransform;
  };
}

#endif
