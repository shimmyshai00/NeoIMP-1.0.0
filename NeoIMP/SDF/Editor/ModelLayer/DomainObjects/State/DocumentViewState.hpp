#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_STATE_DOCUMENTVIEWSTATE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_STATE_DOCUMENTVIEWSTATE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewState.hpp
 * PURPOSE: Defines a struct holding the shared application state describing how a document is being
 *          viewed.
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

namespace SDF::Editor::ModelLayer::DomainObjects::State {
  struct DocumentViewState {
    float viewPosX;
    float viewPosY;
    float viewMagnification;

    DocumentViewState()
      : viewPosX(0.0f),
        viewPosY(0.0f),
        viewMagnification(1.0f)
    {}

    DocumentViewState(float a_viewPosX, float a_viewPosY, float a_viewMagnification)
      : viewPosX(a_viewPosX),
        viewPosY(a_viewPosY),
        viewMagnification(a_viewMagnification)
    {}
  };
}

#endif
