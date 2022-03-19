#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_EDITOR_VIEWANCHOR_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_EDITOR_VIEWANCHOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewAnchor.hpp
 * PURPOSE: Defines the ViewAnchor struct.
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

#include "../../../../Common/Handle.hpp"
#include "../Engine/Dimensions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  struct ViewAnchor {
    Common::Handle m_document;
    Engine::ImagePoint m_position;
    float m_magnification;

    ViewAnchor()
      : m_document(Common::HANDLE_INVALID),
        m_position(0.0f, 0.0f),
        m_magnification(1.0f)
    {
    }

    ViewAnchor(Common::Handle document)
      : m_document(document)
        m_position(0.0f, 0.0f),
        m_magnification(1.0f)
    {
    }

    ViewAnchor(Common::Handle document, Engine::ImagePoint pos)
      : m_document(document)
        m_position(pos),
        m_magnification(1.0f)
    {
    }

    ViewAnchor(Common::Handle document, Engine::ImagePoint pos, float mag)
      : m_document(document),
        m_position(pos),
        m_magnification(mag)
    {
    }
  };
}

#endif
