#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_APIPELINEINTERMED_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_APIPELINEINTERMED_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    APipelineIntermed.hpp
 * PURPOSE: Defines the APipelineIntermed base template.
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

#include "IPipelineBufferReceiver.hpp"
#include "RenderCtx.hpp"

#include <memory>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Renderer {
  // Class:      APipelineIntermed
  // Purpose:    Defines an abstract base class for the intermediate stages of a rendering pipeline.
  // Parameters: InBufferT - The input buffer type.
  //             OutBufferT - The output buffer type which is passed to the next stage.
  template<class InBufferT, class OutBufferT>
  class APipelineIntermed : public IPipelineBufferReceiver<InBufferT> {
  public:
    // Function:   attachNext
    // Purpose:    Attaches a successor stage to this pipeline intermed.
    // Parameters: next - The next pipeline stage to attach.
    // Returns:    A non-owning reference to the passed stage.
    IPipelineBufferReceiver<OutBufferT> *
    attachNext(std::unique_ptr<IPipelineBufferReceiver<OutBufferT>> a_next);
  protected:
    // Function:   activateNextStage
    // Purpose:    Triggers the next stage in the pipeline.
    // Parameters: outBuffer - The buffer to pass in. Note the ownership change.
    //             renderCtx - The rendering context.
    // Returns:    None.
    void
    activateNextStage(std::unique_ptr<OutBufferT> a_outBuffer, RenderCtx &a_renderCtx);
  private:
    std::unique_ptr<IPipelineBufferReceiver<OutBufferT>> m_next;
  };
}

#include "APipelineIntermed.tpp"

#endif
