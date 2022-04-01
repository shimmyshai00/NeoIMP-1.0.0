#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_PLSNOOPFINALIZER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_PLSNOOPFINALIZER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PLSNoOpFinalizer.hpp
 * PURPOSE: Defines the PLSNoOpFinalizer template.
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

#include "APipelineFinal.hpp"
#include "RenderCtx.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Renderer {
  // Class:      PLSNoOpFinalizer
  // Purpose:    Provides a "no-op" finalizer stage for a pipeline that does no post-processing and
  //             simply emits the buffer it was passed.
  // Parameters: InBufferT - The type of buffer received.
  template<class InBufferT>
  class PLSNoOpFinalizer : public APipelineFinal<InBufferT, InBufferT> {
  public:
    void
    process(std::unique_ptr<InBufferT> a_buffer, RenderCtx &a_ctx);
  };
}

#include "PLSNoOpFinalizer.tpp"

#endif
