#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IRENDERER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IRENDERER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRenderer.hpp
 * PURPOSE: Defines the IRenderer interface.
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

#include "IImage.hpp"
#include "GridRendering.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      IRenderer
  // Purpose:    Provides an interface for high-level image rendering operations.
  // Parameters: ImplT, ImplEntityT - same as for IImage.
  template<class ImplT, class ImplEntityT>
  class IRenderer {
  public:
    virtual ~IRenderer() = default;

    // Function:   staticRender
    // Purpose:    Renders an image entirely to a rendering buffer. That is, the rendering has all
    //             tiles allocated and containing render information. This is the most memory-
    //             expensive form of rendering.
    // Parameters: outBuffer - The output buffer to do the rendering to.
    //             image - The image to render.
    // Returns:    None.
    virtual void
    staticRender(GridRendering &outBuffer,
                 IImage<ImplT, ImplEntityT> &image
                ) = 0;
  };
}

#endif
