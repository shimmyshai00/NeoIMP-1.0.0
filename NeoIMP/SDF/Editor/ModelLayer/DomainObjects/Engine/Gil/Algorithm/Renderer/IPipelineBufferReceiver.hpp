#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_IPIPELINEBUFFERRECEIVER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_IPIPELINEBUFFERRECEIVER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IPipelineBufferReceiver.hpp
 * PURPOSE: Defines the IPipelineBufferReceiver interface.
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

#include "RenderCtx.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Renderer {
  // Class:      IPipelineBufferReceiver
  // Purpose:    Defines the interface with which a pipeline intermediate stage receives a buffer.
  // Parameters: InBufferT - The type of input buffer accepted.
  template<class InBufferT>
  class IPipelineBufferReceiver {
  public:
    virtual ~IPipelineBufferReceiver() = default;

    // Function:   process
    // Purpose:    Processes the given buffer before passing another to the next pipeline stage, if
    //             appropriate.
    // Parameters: buffer - The buffer to process. Note here that ownership is transferred.
    //             ctx - The renedering context to pass through the whole process.
    // Returns:    None.
    virtual void
    process(std::unique_ptr<InBufferT> buffer, RenderCtx &ctx) = 0;
  };
}

#endif
