#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_QTVIEWPORTCALC_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_QTVIEWPORTCALC_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtViewportCalc.hpp
 * PURPOSE: Defines the QtViewportCalc class.
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

#include <QSize>
#include <QPointF>
#include <QTransform>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  // Class:      QtViewportCalc
  // Purpose:    Performs calculations related to convert coordinates to and from image space and a screen viewport.
  // Parameters: None.
  class QtViewportCalc {
  public:
    // Function:   QtViewportCalc
    // Purpose:    Construct the viewport with a given screen width and height.
    // Parameters: width - The width of the viewport in pixels.
    //             height - The height of the viewport in pixels.
    QtViewportCalc(int width, int height);
    QtViewportCalc(const QSize &size);

    // Function:   getTranslateX
    // Purpose:    Get the horizontal translation of the viewport in image space.
    // Parameters: None.
    // Returns:    The translation amount.
    float
    getTranslateX() const;

    // Function:   getTranslateY
    // Purpose:    Get the vertical translation of the viewport in image space.
    // Parameters: None.
    // Returns:    The translation amount.
    float
    getTranslateY() const;

    // Function:   getZoom
    // Purpose:    Get the magnification factor of the viewport.
    // Parameters: None.
    // Returns:    The magnification factor.
    float
    getZoom() const;

    // Function:   setTranslateX
    // Purpose:    Sets the horizontal translation of the viewport in image space.
    // Parameters: xDisp - The x-axis displacement.
    // Returns:    None.
    void
    setTranslateX(float xDisp);

    // Function:   setTranslateY
    // Purpose:    Sets the vertical translation of the viewport in image space.
    // Parameters: yDisp - The y-axis displacement.
    // Returns:    None.
    void
    setTranslateY(float yDisp);

    // Function:   setTranslate
    // Purpose:    Sets the translation of the viewport in image space.
    // Parameters: xDisp - The x-axis displacement.
    //             yDisp - The y-axis displacement.
    // Returns:    None.
    void
    setTranslate(float xDisp, float yDisp);

    // Function:   setZoom
    // Purpose:    Sets the magnification (or zoom factor) of the viewport.
    // Parameters: magnif - The magnification to use.
    // Returns:    None.
    void
    setZoom(float magnif);

    // Function:   viewportToImage
    // Purpose:    Transforms an object from viewport space to image space.
    // Parameters: object - The object to transform.
    // Returns:    The transformed object.
    QPointF
    viewportToImage(const QPointF &object) const;

    QPolygonF
    viewportToImage(const QRectF &object) const;

    // Function:   imageToViewport
    // Purpose:    Transforms an object from image space to viewport space.
    // Parameters: object - The object to transform.
    // Returns:    The transformed object.
    QPointF
    imageToViewport(const QPointF &object) const;

    QPolygonF
    imageToViewport(const QRectF &object) const;
    
    // Function:    getViewportToImageTransform
    // Purpose:     Get the transform mapping the viewport space to image space.
    // Paramaeters: None.
    // Returns:     A QTransform representing this transform.
    QTransform
    getViewportToImageTransform() const;

    // Function:    getImageToViewportTransform
    // Purpose:     Get the transform mapping the image space to viewport space.
    // Paramaeters: None.
    // Returns:     A QTransform representing this transform.
    QTransform
    getImageToViewportTransform() const;
  private:
    int m_width;
    int m_height;

    float m_translateX;
    float m_translateY;
    float m_zoom;

    QTransform m_translateXXfm;
    QTransform m_translateYXfm;
    QTransform m_translateXfm;
    QTransform m_zoomXfm;
  };
}

#endif
