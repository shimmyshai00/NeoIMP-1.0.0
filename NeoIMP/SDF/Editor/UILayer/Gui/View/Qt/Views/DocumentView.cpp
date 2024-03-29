/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.cpp
 * PURPOSE: Implements the DocumentView class.
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

#include "DocumentView.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  using namespace Common;
  using namespace CustomWidgets;
  using namespace AbstractModel::Metrics;
  using namespace AbstractModel::Viewing;

  DocumentView::DocumentView(deps_t a_deps, Handle a_documentHandle, QWidget *a_parent)
    : QWidget(a_parent),
      m_renderingService(a_deps.get<IRenderingService>()),
      m_documentHandle(a_documentHandle),
      m_layout(new QGridLayout(this)),
      m_imageEditorWidget(new ImageEditor::Widget(
        a_deps.get<IGetDocumentDimensionsService>(),
        a_deps.get<IAddViewService>(),
        a_deps.get<IGetViewCoordinatesService>(),
        a_deps.get<IRenderingService>(),
        this
      ))
  {
    m_layout->addWidget(m_imageEditorWidget, 0, 0);
    m_imageEditorWidget->setEditedImage(a_documentHandle);
  }

  Handle
  DocumentView::getDocumentHandle() const {
    return m_documentHandle;
  }

  PIConnection
  DocumentView::hookOnHScroll(std::unique_ptr<IController<Handle, float>> a_controller) {
    return m_imageEditorWidget->hookOnHScroll(std::move(a_controller));
  }

  PIConnection
  DocumentView::hookOnVScroll(std::unique_ptr<IController<Handle, float>> a_controller) {
    return m_imageEditorWidget->hookOnVScroll(std::move(a_controller));
  }
}
