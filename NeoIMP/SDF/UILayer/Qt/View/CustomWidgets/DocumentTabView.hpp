#ifndef SDF_UILAYER_QT_VIEW_CUSTOMWIDGETS_DOCUMENTTABVIEW_HPP
#define SDF_UILAYER_QT_VIEW_CUSTOMWIDGETS_DOCUMENTTABVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentTabView.hpp
 * PURPOSE: An implementation of a derived widget from the Qt tab view that serves as the "top level" for document
 *          display.
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

#include <SDF/UILayer/Qt/Controller/IDocumentView.hpp>
#include <SDF/ModelLayer/Handle.hpp>

#include <QTabWidget>
#include <QWidget>

namespace SDF::UILayer::Qt::View::CustomWidgets {
  class DocumentTabView : public QTabWidget, public Controller::IDocumentView {
    Q_OBJECT
  public:
    DocumentTabView(QWidget *parent = nullptr);
    ~DocumentTabView() {}

    void showDocument(ModelLayer::Handle documentHandle);
  };
}

#endif
