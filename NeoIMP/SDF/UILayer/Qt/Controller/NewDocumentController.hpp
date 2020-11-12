#ifndef SDF_UILAYER_QT_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP
#define SDF_UILAYER_QT_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.hpp
 * PURPOSE: Implementation of the new-document controller.
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

#include <SDF/ModelLayer/DomainObjects/Color/ColorModels.hpp>
#include <SDF/ModelLayer/DomainObjects/Color/BitDepths.hpp>
#include <SDF/UILayer/Qt/View/INewDocumentController.hpp>

namespace SDF::UILayer::AbstractModel {
  class IDocumentCreationService;
}

namespace SDF::UILayer::Qt::Controller {
  class IDocumentView;

  class NewDocumentController : public View::INewDocumentController {
  public:
    INJECT(NewDocumentController(AbstractModel::IDocumentCreationService *documentCreationService));
    void attachDocumentView(IDocumentView *documentView);

    void createNewDocument(
      float imageWidthPixels, float imageHeightPixels, float imageResolutionPpi,
      ModelLayer::DomainObjects::Color::ColorModel colorModel,
      ModelLayer::DomainObjects::Color::BitDepth bitDepth
    );
  private:
    AbstractModel::IDocumentCreationService *m_documentCreationService;
    IDocumentView *m_documentView;
  };
}

#endif
