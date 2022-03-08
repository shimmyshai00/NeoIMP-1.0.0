#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_RENDERER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_RENDERER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Renderer.hpp
 * PURPOSE: Defines the Renderer template.
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

#include "../../../AbstractData/Entity/Gil/Image.hpp"
#include "../IRenderer.hpp"
#include "../GridRendering.hpp"
#include "Image.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Renderer
  // Purpose:    Provides the high-level rendering class for rendering images in the GIL framework.
  // Parameters: GilImageT - The type of GIL image rendered.
  template<class GilImageT>
  class Renderer : public IRenderer<Image<GilImageT>, AbstractData::Entity::Gil::Image<GilImageT>> {
  public:
    Renderer();

    void
    staticRender(GridRendering &outBuffer,
                 IImage<ImplT, ImplEntityT> &image
                );
  };
}

#include "Renderer.tpp"

#endif
