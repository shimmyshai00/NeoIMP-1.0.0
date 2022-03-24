#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_VIEWSLIDECALC_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_VIEWSLIDECALC_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewSlideCalc.hpp
 * PURPOSE: Defines the ViewSlideCalc class.
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

#include <cmath>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  // Class:      ViewSlideCalc
  // Purpose:    Calculates slider parameters for scrolling a viewport across an image. This
  //             handles one dimension only.
  // Parameters: None.
  class ViewSlideCalc {
  public:
    ViewSlideCalc();

    // Function:   setObjectLength
    // Purpose:    Sets the object length used in the calculations. Usually, this will be the
    //             width/height of the image.
    // Parameters: length - The length of the object viewed.
    // Returns:    None.
    void
    setObjectLength(float length);

    // Function:   setViewportLength
    // Purpose:    Sets the length of the sliding viewport used in the calculations.
    // Parameters: length - The new length of the sliding viewport.
    // Returns:    None.
    void
    setViewportLength(float length);

    // Function:   setMinScale
    // Purpose:    Sets the minimum scale level (basically, the size of a viewport pixel,
    //             presumably) used to correct the slider range.
    // Parameters: minScale - The new minimum scale.
    // Returns:    None.
    void
    setMinScale(float minScale);

    // Function:   setViewportByLengthAndMag
    // Purpose:    Sets the viewport by its length at a magnification of 1.0, and magnification.
    // Parameters: viewLength - The unmagnified viewport length.
    //             mag - The view magnification.
    // Returns:    None.
    void
    setViewportByLengthAndMag(float viewLength, float mag);

    // Function:   getSlideMin
    // Purpose:    Gets the minimum of the slide range, which is adjusted so that setMinScale() = 1.
    //             This helps maximize sliding precision.
    // Parameters: None.
    // Returns:    The range minimum.
    int
    getSlideMin();

    // Function:   getSlideMax
    // Purpose:    Gets the maximum of the slide range, subject to the same constraint.
    // Parameters: None.
    // Returns:    The range maximum.
    int
    getSlideMax();

    // Function:   getPageStep
    // Purpose:    Get the scroll bar page step for the sliding.
    // Parameters: None.
    // Returns:    The mage step.
    int
    getPageStep();

    // Function:   getSlidePosFromOnObj
    // Purpose:    Gets the slider position for a point on the object in object space.
    // Parameters: onObjPos - The on-object position to get for.
    // Returns:    The desired slider position equivalent.
    int
    getSlidePosFromOnObj(float onObjPos);

    // Function:   getOnObjPosFromSlide
    // Purpose:    Gets the on-object position from a slider position.
    // Parameters: sliderPos - The slider position to get for.
    // Returns:    The position on the object this slider position corresponds to.
    float
    getOnObjPosFromSlide(int sliderPos);
  private:
    // use double to maintain precision in intermediate calculations
    double m_objectLength;
    double m_viewportLength;
    double m_minScale;
  };
}

#endif
