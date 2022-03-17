#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_RULERWIDGET_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_RULERWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RulerWidget.hpp
 * PURPOSE: Defines the RulerWidget class.
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

#include "../../../../../../../../Common/Handle.hpp"

#include <QWidget>
#include <QPaintEvent>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  // Class:      RulerWidget
  // Purpose:    Defines a sub-widget of the image editor widget that allows for the emplacement of
  //             a ruler on the sides of the image. This ruler is designed to align with a
  //             RenderDisplayWidget in that it measures a viewport specified in the same ways,
  //             though on one dimension only.
  // Parameters: None.
  class RulerWidget : public QWidget {
    Q_OBJECT
  public:
    RulerWidget(::Qt::Orientation orientation, QWidget *parent = nullptr);

    QSize
    sizeHint() const;

    // Function:   thickness
    // Purpose:    Gets the thickness of the ruler in pixels.
    // Parameters: None.
    // Returns:    The thickness in pixels.
    int
    thickness() const;

    // Function:   majorTickEvery
    // Purpose:    Indicates how many pixels there are between major ruler ticks.
    // Parameters: None.
    // Returns:    The number of pixels between major ticks.
    int
    majorTickEvery() const;

    // Function:   minorTickEvery
    // Purpose:    Indicates how many pixels there are between minor ruler ticks.
    // Parameters: None.
    // Returns:    The number of pixels between minor ticks.
    int
    minorTickEvery() const;

    // Function:   minorTickThickness
    // Purpose:    Indicates how many pixels high a minor tick is.
    // Parameters: None.
    // Returns:    The number of pixels in a minor tick.
    int
    minorTickThickness() const;

    // Function:   setThickness
    // Purpose:    Sets the thickness of the ruler.
    // Parameters: thickness - The new thickness in pixels.
    // Returns:    None.
    void
    setThickness(int thickness);

    // Function:   setMajorTickEvery
    // Purpose:    Sets the interval for the major ticks.
    // Parameters: interval - The new interval in pixels.
    // Returns:    None.
    void
    setMajorTickEvery(int interval);

    // Function:   setMinorTickEvery
    // Purpose:    Sets the interval for the minor ticks.
    // Parameters: interval - The new interval in pixels.
    // Returns:    None.
    void
    setMinorTickEvery(int interval);

    // Function:   setMinorTickThickness
    // Purpose:    Sets the thickness of a minor tick.
    // Parameters: thickness - The new thickness in pixels.
    // Returns:    None.
    void
    setMinorTickThickness(int thickness);

    // Function:   getViewportP1
    // Purpose:    Gets the position of the left/top of the viewport.
    // Parameters: None.
    // Returns:    The left/top position of the viewport in image space coordinates.
    float
    getViewportP1() const;

    // Function:   getViewport2
    // Purpose:    Gets the position of the right/bottom of the viewport.
    // Parameters: None.
    // Returns:    The right/bottom position of the viewport in image space coordinates.
    float
    getViewportP2() const;

    // Function:   setViewportP1
    // Purpose:    Sets the left/top of the viewport.
    // Parameters: p1 - The new coordinate.
    // Returns:    None.
    void
    setViewportP1(float p1);

    // Function:   setViewportMagnification
    // Purpose:    Sets the magnification of the viewport.
    // Parameters: mag - The new magnification.
    // Returns:    None.
    void
    setViewportMagnification(float mag);

    // Function:   setAll
    // Purpose:    Sets the whole viewport.
    // Parameters: p1 - The new position.
    //             mag - The new magnification.
    // Returns:    None.
    void
    setAll(float p1, float mag);
  protected:
    void
    paintEvent(QPaintEvent *event) override;
  private:
    ::Qt::Orientation m_orientation;

    int m_rulerThickness;
    int m_majorTickInterval;
    int m_minorTickInterval;
    int m_minorTickThickness;
    int m_labelMargin;
    int m_labelThickness;

    float m_viewP1;
    float m_viewMagnification;
  };
}

#endif
