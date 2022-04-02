#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_DOCUMENTVIEW_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_DOCUMENTVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.hpp
 * PURPOSE: Defines the DocumentView class.
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
#include "../../../../AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../../AbstractModel/Viewing/IAddViewService.hpp"
#include "../../../../AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../../../AbstractModel/Viewing/IRenderingService.hpp"
#include "../CustomWidgets/ImageEditor/Widget.hpp"

#include <QWidget>
#include <QGridLayout>

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  // Class:      DocumentView
  // Purpose:    Implements the Qt GUI's document view.
  // Parameters: None.
  class DocumentView : public QWidget {
    Q_OBJECT;
  public:
    DocumentView(
      AbstractModel::Metrics::IGetDocumentDimensionsService *getDocumentDimensionsService,
      AbstractModel::Viewing::IAddViewService *addViewService,
      AbstractModel::Viewing::IGetViewCoordinatesService *getViewCoordinatesService,
      AbstractModel::Viewing::IRenderingService *renderingService,
      Common::Handle documentHandle,
      QWidget *parent = nullptr
    );

    Common::Handle
    getDocumentHandle() const;

    Common::PIConnection
    hookOnHScroll(std::unique_ptr<IController<Common::Handle, float>> controller);

    Common::PIConnection
    hookOnVScroll(std::unique_ptr<IController<Common::Handle, float>> controller);
  private:
    AbstractModel::Viewing::IRenderingService *m_renderingService;
    Common::Handle m_documentHandle;

    QGridLayout *m_layout;
    CustomWidgets::ImageEditor::Widget *m_imageEditorWidget;
  };
}

#endif
