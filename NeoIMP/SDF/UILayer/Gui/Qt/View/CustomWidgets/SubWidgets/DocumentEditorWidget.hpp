#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentEditorWidget.hpp
 * PURPOSE: Headers for the custom Qt UI widget that provides the interactive pane for editing the document. This
 *          layers the image together with various editing decals.
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

#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <QWidget>

#include <QStackedLayout>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  class IImageDataSource;

  namespace SubWidgets {
    namespace EditorWidget {
      class BoxDecalWidget;
      class ImageDisplayWidget;
    }

    class DocumentEditorWidget : public QWidget {
      Q_OBJECT
    public:
      DocumentEditorWidget(QWidget *parent = nullptr);
      ~DocumentEditorWidget() {}

      QSize sizeHint() const;

      void setDataSource(IImageDataSource *dataSource);

      float magnification() const;
      void setMagnification(float newMagnification);

      void setCursorByTool(AbstractModel::Properties::Tool tool);
    private:
      EditorWidget::BoxDecalWidget *m_temporaryRectangleDecal;
      EditorWidget::ImageDisplayWidget *m_imageDisplayWidget;

      QStackedLayout *m_stackedLayout;
    };
  }
}

#endif
