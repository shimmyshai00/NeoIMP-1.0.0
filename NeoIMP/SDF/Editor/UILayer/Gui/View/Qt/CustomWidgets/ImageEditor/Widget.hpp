#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_WIDGET_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_WIDGET_HPP

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

#include "../../../../../../../Common/Handle.hpp"
#include "../../../../../../../Common/IConnection.hpp"
#include "../../../../../AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../../../AbstractModel/Viewing/IAddViewService.hpp"
#include "../../../../../AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../../../../AbstractModel/Viewing/IRenderingService.hpp"
#include "../../../IController.hpp"
#include "../../QtEvent.hpp"
#include "Impl/RulerWidget.hpp"
#include "Impl/RenderDisplayWidget.hpp"
#include "Impl/ViewSlideCalc.hpp"

#include <QWidget>
#include <QGridLayout>
#include <QSize>
#include <QScrollBar>
#include <QResizeEvent>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor {
  // Class:      Widget
  // Purpose:    Defines the full image-editor custom widget. This is the one you should use in
  //             user code. Note that this also acts in part like a view in that it can hook
  //             controllers to manipulate the model layer.
  // Parameters: None.
  class Widget : public QWidget {
    Q_OBJECT
  public:
    Widget(
      AbstractModel::Metrics::IGetDocumentDimensionsService *getDocumentDimensionsService,
      AbstractModel::Viewing::IAddViewService *addViewService,
      AbstractModel::Viewing::IGetViewCoordinatesService *getViewCoordinatesService,
      AbstractModel::Viewing::IRenderingService *renderingService,
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

    Common::PIConnection
    hookOnHScroll(std::unique_ptr<IController<Common::Handle, float>> controller);

    Common::PIConnection
    hookOnVScroll(std::unique_ptr<IController<Common::Handle, float>> controller);
  protected:
    void
    resizeEvent(QResizeEvent *event) override;
  private:
    AbstractModel::Metrics::IGetDocumentDimensionsService *m_getDocumentDimensionsService;
    AbstractModel::Viewing::IAddViewService *m_addViewService;
    AbstractModel::Viewing::IGetViewCoordinatesService *m_getViewCoordinatesService;
    AbstractModel::Viewing::IRenderingService *m_renderingService;

    QGridLayout *m_gridLayout;

    Impl::RulerWidget *m_horizontalRuler;
    Impl::RulerWidget *m_verticalRuler;
    Impl::RenderDisplayWidget *m_renderDisplayWidget;

    QScrollBar *m_horizontalScroll;
    QScrollBar *m_verticalScroll;

    Common::PIConnection m_viewportUpdateConn;

    QtEvent<Common::Handle, float> m_hScrollEvent;
    QtEvent<Common::Handle, float> m_vScrollEvent;

    Common::Handle m_documentHandle;
    Common::Handle m_documentViewDataHandle;

    Impl::ViewSlideCalc m_hViewSlideCalc;
    Impl::ViewSlideCalc m_vViewSlideCalc;
  };
}

#endif
