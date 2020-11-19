/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.cpp
 * PURPOSE: Implementation of the NewDocumentController class.
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

#include <NewDocumentController.hpp>
#include <INewDocumentController.hpp>

namespace SDF::UILayer::Qt::Controller {
  class NewDocumentController : public INewDocumentController {
    INJECT(NewDocumentController()) {}
    ~NewDocumentController() {}

    View::IDocumentView *createNewDocument(
      int documentWidthPixels, int documentHeightPixels, float documentResolutionPpi,
      ModelLayer::DomainObjects::Color::ColorModel colorModel, ModelLayer::DomainObjects::Color::BitDepth bitDepth
    ) {
      // TBA
      return nullptr;
    }
  };
}

namespace SDF::UILayer::Qt::Controller {
  fruit::Component<INewDocumentController> getNewDocumentControllerComponent() {
    return fruit::createComponent()
      .bind<INewDocumentController, NewDocumentController>()
  }
}
