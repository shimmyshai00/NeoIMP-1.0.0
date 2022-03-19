#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_STATE_DOCUMENTVIEWSTATE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_STATE_DOCUMENTVIEWSTATE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewState.hpp
 * PURPOSE: Defines the DocumentViewState class.
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

#include "../../../../Common/ValueField.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::State {
  struct ViewCoordinates {
    float m_viewPosX;
    float m_viewPosY;
    float m_viewMagnification;

    ViewCoordinates(float viewPosX, float viewPosY, float viewMagnification)
      : m_viewPosX(viewPosX),
        m_viewPosY(viewPosY),
        m_viewMagnification(viewMagnification)
    {
    }
  };

  // Class:      DocumentViewState
  // Purpose:    Holds a shared application state variable describing the view parameters of a
  //             document.
  // Parameters: None.
  class DocumentViewState : public Common::ValueField<ViewCoordinates> {
  public:
    DocumentViewState(float viewPosX, float viewPosY, float viewMagnification)
      : ValueField(ViewCoordinates(viewPosX, viewPosY, viewMagnification))
    {}
  };
}

#endif
