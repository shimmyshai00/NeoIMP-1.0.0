#ifndef SDF_UILAYER_GUI_QT_VIEW_DOCUMENTVIEW_HPP
#define SDF_UILAYER_GUI_QT_VIEW_DOCUMENTVIEW_HPP

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

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/UILayer/Gui/IGuiElement.hpp>

#include <SDF/UILayer/AbstractModel/Events/ToolEvent.hpp>
#include <SDF/UILayer/AbstractModel/Events/ViewportEvent.hpp>

#include <SDF/UILayer/AbstractModel/IDocumentAccessService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentRenderService.hpp>
#include <SDF/UILayer/AbstractModel/IUiStateModelService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentViewConfigService.hpp>
#include <SDF/UILayer/AbstractModel/IToolApplicationService.hpp>
#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <SDF/UILayer/Gui/Qt/View/DocumentViewParams.hpp>

#include <SDF/UILayer/Gui/Qt/View/CustomWidgets/DocumentWidget.hpp>
#include <SDF/UILayer/Gui/Qt/View/CustomWidgets/IImageDataSource.hpp>

#include <QBoxLayout>

namespace SDF::UILayer::Gui::Qt::View {
  // Class:      DocumentView
  // Purpose:    Defines a Qt widget view for displaying and editing a document.
  // Parameters: None.
  class DocumentView : public QWidget,
                       public IGuiElement,
                       private Interfaces::IEventHandler<AbstractModel::Events::ToolEvent>,
                       private Interfaces::IEventHandler<AbstractModel::Events::ViewportEvent>
  {
    Q_OBJECT
  public:
    DocumentView(AbstractModel::IDocumentAccessService *documentAccessService,
                 AbstractModel::IDocumentRenderService *documentRenderService,
                 AbstractModel::IDocumentViewConfigService *documentViewConfigService,
                 AbstractModel::IToolApplicationService *toolApplicationService,
                 AbstractModel::Handle handleToView,
                 QWidget *parent = nullptr
                );
    ~DocumentView();

    IGuiElement *
    getParent();

    void
    show();

    void
    close();

    AbstractModel::Handle
    getViewedDocumentHandle() const;
  private:
    AbstractModel::IDocumentViewConfigService *m_documentViewConfigService;
    AbstractModel::IToolApplicationService *m_toolApplicationService;

    AbstractModel::Handle m_documentHandle;
    QBoxLayout *m_layout;

    CustomWidgets::DocumentWidget *m_documentWidget;
    CustomWidgets::IImageDataSource *m_imageDataSource;

    void
    handleEvent(std::shared_ptr<AbstractModel::Events::ToolEvent> event);

    void
    handleActiveToolChangedEvent(AbstractModel::Events::ActiveToolChangedEvent *event);

    void
    handleEvent(std::shared_ptr<AbstractModel::Events::ViewportEvent> event);

    void
    handleViewCenterChangedEvent(AbstractModel::Events::ViewCenterChangedEvent *event);

    void
    handleViewMagnificationChangedEvent(AbstractModel::Events::ViewMagnificationChangedEvent *event);
  };
}

#endif
