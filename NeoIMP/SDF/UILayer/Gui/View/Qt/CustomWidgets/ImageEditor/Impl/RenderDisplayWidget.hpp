#ifndef SDF_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_RENDERDISPLAYWIDGET_HPP
#define SDF_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_RENDERDISPLAYWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderDisplayWidget.hpp
 * PURPOSE: Defines the RenderDisplayWidget class.
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

#include "../../../../../../../Common/Handle.hpp"
#include "../../../../../../AbstractModel/IRenderingService.hpp"

#include <QWidget>
#include <QPointer>
#include <QImage>

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  // Class:      RenderDisplayWidget
  // Purpose:    Defines a custom widget that displays part of an image rendering as computed by
  //             the rendering service in the model layer. Note that this widget is designed to fit
  //             a layout, and to form one of a composite layercake of widgets with others to put
  //             editing-related decals on top (all these are in this Impl folder). It is NOT
  //             intended for standalone use; instead, one should ONLY use the proper ImageEditor
  //             widget.
  // Parameters: None.
  class RenderDisplayWidget : public QWidget {
    Q_OBJECT
  public:
    RenderDisplayWidget(AbstractModel::IRenderingService *renderingService,
                        QWidget *parent = nullptr
                       );

    ~RenderDisplayWidget();

    // Function:   setDisplayedImage
    // Purpose:    Set the image to display.
    // Parameters: imageHandle - The handle for the image request.
    // Returns:    None.
    void
    setDisplayedImage(Common::Handle imageHandle);

    // Function:   viewportX1, viewportY1, viewportX2, viewportY2
    // Purpose:    Get the coordinates, *in image space*, of the viewport rectangle.
    // Parameters: None.
    // Returns:    The coordinates requested.
    float
    viewportX1() const;

    float
    viewportY1() const;

    float
    viewportX2() const;

    float
    viewportY2() const;
  protected:
    void
    paintEvent(QPaintEvent *event);
  private:
    AbstractModel::IRenderingService *m_renderingService;

    Common::Handle m_imageHandle;
    Common::Handle m_renderHandle;

    float m_viewUpperLeftX, m_viewUpperLeftY;
    float m_viewMagnification;
  };
}

#endif
