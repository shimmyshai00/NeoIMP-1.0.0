#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_ABSTRACTVIEWPORT_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_ABSTRACTVIEWPORT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AbstractViewport.hpp
 * PURPOSE: Defines the AbstractViewport class.
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

#include <SDF/UILayer/Gui/Qt/View/CustomWidgets/SubWidgets/EditViewWidget/QtViewportCalc.hpp>

#include <QWidget>
#include <QResizeEvent>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  // Class:      AbstractViewport
  // Purpose:    Provides an abstract base for widgets that give a viewport onto the image data.
  // Parameters: None.
  class AbstractViewport : public QWidget {
  public:
    // Function:   AbstractViewport
    // Purpose:    Constructs a new abstract viewport widget.
    // Parameters: parent - The QWidget parent of this abstract widget.
    AbstractViewport(QWidget *parent = nullptr);
    virtual ~AbstractViewport() = 0;

    // Function:   translateX
    // Purpose:    Gets the x-axis translation of this viewport widget.
    // Parameters: None.
    // Returns:    The amount of translation.
    float
    translateX() const;

    // Function:   translateY
    // Purpose:    Gets the y-axis translation of this viewport widget.
    // Parameters: None.
    // Returns:    The amount of translation.
    float
    translateY() const;

    // Function:   zoom
    // Purpose:    Gets the magnification of this viewport widget.
    // Parameters: None.
    // Returns:    The magnification used.
    float
    zoom() const;

    // Function:   getCenterXOnImage
    // Purpose:    Gets the X-coordinate of the viewport center on the image.
    // Parameters: None.
    // Returns:    The center's X-coordinate.
    float
    getCenterXOnImage() const;

    // Function:   getCenerYOnImage
    // Purpose:    Gets the Y-coordinate of the viewport center on the image.
    // Parameters: None.
    // Returns:    The center's Y-coordinate.
    float
    getCenterYOnImage() const;

    // Function:   setTranslateX
    // Purpose:    Sets the x-axis translation used by this viewport widget.
    // Parameters: translateX - The new value.
    // Returns:    None.
    void
    setTranslateX(float translateX);

    // Function:   setTranslateY
    // Purpose:    Sets the y-axis translation used by this viewport widget.
    // Parameters: translateY - The new value.
    // Returns:    None.
    void
    setTranslateY(float translateY);

    // Function:   setZoom
    // Purpose:    Sets the magnification factor used by this viewport widget.
    // Parameters: zoom - The new value.
    // Returns:    None.
    void
    setZoom(float zoom);

    // Function:   setCenterXOnImage
    // Purpose:    Sets the position of the viewport so as to center the given image x-coordinate.
    // Parameters: centerX - The new center X-coordinate on the image.
    // Returns:    None.
    void
    setCenterXOnImage(float centerX);

    // Function:   setCenterYOnImage
    // Purpose:    Sets the position of the viewport so as to center the given image y-coordinate.
    // Parameters: centerY - The new center Y-coordinate on the image.
    // Returns:    None.
    void
    setCenterYOnImage(float centerY);
  protected:
    // Function:   getImageToViewportTransform
    // Purpose:    Get the transform mapping image data to the viewport.
    // Parameters: None.
    // Returns:    The mapping transform.
    QTransform
    getImageToViewportTransform() const;

    // Qt methods.
    virtual void
    resizeEvent(QResizeEvent *event);
  private:
    QtViewportCalc m_viewport;
  };
}

#endif
