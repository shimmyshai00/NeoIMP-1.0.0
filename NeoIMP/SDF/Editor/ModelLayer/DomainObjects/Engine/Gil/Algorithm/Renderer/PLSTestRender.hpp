#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_PLSTESTRENDER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_PLSTESTRENDER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PLSTestRender.hpp
 * PURPOSE: Defines the PLSTestRender template.
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

#include "../../../Image/Image.hpp"
#include "../../../Buffers/GridRendering.hpp"
#include "APipelineHead.hpp"

#include "RenderCtx.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Renderer {
  // Class:      PLSTestRender
  // Purpose:    Defines a very basic "for-now" testing-only render pipe stage that just renders the
  //             whole background of an image. No optimization; no NOTHING. Just to start the system
  //             off.
  // Parameters: GilSpecT - The Boost.GIL image spec being rendered.
  template<class GilSpecT>
  class PLSTestRender : public APipelineHead<Image::Image<GilSpecT>, Buffers::GridRendering> {
  public:
    // Function:   PLSTestRender
    // Purpose:    Constructs a new test render head.
    // Parameters: None.
    PLSTestRender();

    void
    beginProcessing(const Image::Image<GilSpecT> &a_inputData);
  private:
    RenderCtx m_ctx;
  };
}

#include "PLSTestRender.tpp"

#endif
