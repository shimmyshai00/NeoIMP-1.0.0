#ifndef SDF_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_IMAGEDISPLAYWIDGET_HPP
#define SDF_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_IMAGEEDITOR_IMPL_IMAGEDISPLAYWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageDisplayWidget.hpp
 * PURPOSE: Defines the ImageDisplayWidget class.
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

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  // Class:      ImageDisplayWidget
  // Purpose:    Provides a custom widget to display loaded images. This interfaces directly with
  //             the image rendering subsystem in the model layer to view an image document.
  // Parameters: None.
  class ImageDisplayWidget : public QWidget {
    Q_OBJECT
  public:
    ImageDisplayWidget(AbstractModel::IRenderingService *renderingService,
                       Common::Handle documentHandle,
                       QWidget *parent = nullptr
                      );

    double
    viewportX1() const;

    double
    viewportY1() const;

    void
    setViewportX1(double newX1);

    void
    setViewportY1(double newY1);
  private:
    AbstractModel::IRenderingService *m_renderingService;
    Common::Handle m_documentHandle;
    Common::Handle m_renderingHandle;

    // Viewport parameters.
    double m_viewportX1, m_viewportY1;
  };
}

#endif
