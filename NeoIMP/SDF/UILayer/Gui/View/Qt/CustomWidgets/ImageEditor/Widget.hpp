#ifndef SDF_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_WIDGET_HPP
#define SDF_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_WIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Widget.hpp
 * PURPOSE: Defines the Widget class.
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

#include "../../../../../../Common/Handle.hpp"
#include "../../../../../../Common/IConnection.hpp"
#include "../../../../../AbstractModel/IRenderingService.hpp"
#include "../../../../../AbstractModel/IGetViewCoordinatesService.hpp"
#include "Impl/RulerWidget.hpp"
#include "Impl/RenderDisplayWidget.hpp"

#include <QWidget>
#include <QGridLayout>
#include <QSize>
#include <QScrollBar>

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor {
  // Class:      Widget
  // Purpose:    Defines the full image-editor custom widget. This is the one you should use in
  //             user code.
  // Parameters: None.
  class Widget : public QWidget {
    Q_OBJECT
  public:
    Widget(AbstractModel::IRenderingService *renderingService,
           AbstractModel::IGetViewCoordinatesService *getViewCoordinatesService,
           QWidget *parent = nullptr
          );

    ~Widget();

    // Function:   setEditedImage
    // Purpose:    Set the image to edit.
    // Parameters: imageHandle - The handle for the image request.
    // Returns:    None.
    void
    setEditedImage(Common::Handle imageHandle);

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
  private:
    AbstractModel::IGetViewCoordinatesService *m_getViewCoordinatesService;

    QGridLayout *m_gridLayout;

    Impl::RulerWidget *m_horizontalRuler;
    Impl::RulerWidget *m_verticalRuler;
    Impl::RenderDisplayWidget *m_renderDisplayWidget;

    QScrollBar *m_horizontalScroll;
    QScrollBar *m_verticalScroll;

    Common::PIConnection m_viewportUpdateConn;
  };
}

#endif
