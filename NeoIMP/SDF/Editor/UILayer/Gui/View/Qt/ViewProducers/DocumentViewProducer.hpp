#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_DOCUMENTVIEWPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_DOCUMENTVIEWPRODUCER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewProducer.hpp
 * PURPOSE: Defines the DocumentViewProducer class.
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

#include "../../../../../../Common/Model/ServicePack.hpp"
#include "../../../../../../Common/Handle.hpp"

#include "../../../../AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../../AbstractModel/Editing/IGetDocumentNameService.hpp"
#include "../../../../AbstractModel/Viewing/IAddViewService.hpp"
#include "../../../../AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../../../AbstractModel/Viewing/ISetViewXCoordinateService.hpp"
#include "../../../../AbstractModel/Viewing/ISetViewYCoordinateService.hpp"
#include "../../../../AbstractModel/Viewing/IRenderingService.hpp"

#include "../../../Controller/IViewProducer.hpp"

#include "../Views/DocumentView.hpp"

#include "AProducerNode.hpp"

#include <QPointer>

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  // Class:      DocumentViewProducer
  // Purpose:    Produces an editor view on an image document. Note that the parent must have a
  //             Views::MainWindow view widget.
  // Parameters: None.
  class DocumentViewProducer : public AProducerNode,
                               public Controller::IViewProducer<>
  {
  public:
    typedef Common::Model::ServicePack<
      AbstractModel::Metrics::IGetDocumentDimensionsService,
      AbstractModel::Editing::IGetDocumentNameService,
      AbstractModel::Viewing::IAddViewService,
      AbstractModel::Viewing::IGetViewCoordinatesService,
      AbstractModel::Viewing::ISetViewXCoordinateService,
      AbstractModel::Viewing::ISetViewYCoordinateService,
      AbstractModel::Viewing::IRenderingService
    > deps_t;
  public:
    DocumentViewProducer(
      deps_t a_deps,
      Common::Handle a_id,
      AProducerNode *a_parent,
      Common::Handle a_documentHandle
    );

    QWidget *
    getViewWidget();

    void
    produceView();
  private:
    deps_t m_services;

    Common::Handle m_documentHandle;

    QPointer<Views::DocumentView> m_documentView;
  };
}

#endif
