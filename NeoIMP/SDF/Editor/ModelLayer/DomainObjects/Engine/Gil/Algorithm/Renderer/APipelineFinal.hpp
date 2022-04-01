#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_APIPELINEFINAL_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_APIPELINEFINAL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    APipelineFinal.hpp
 * PURPOSE: Defines the APipelineFinal base template.
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
  // Class:      APipelineFinal
  // Purpose:    Defines an abstract base class for the terminal stage of a rendering pipeline.
  // Parameters: InBufferT - The input buffer type.
  //             OutBufferT - The output buffer type which is passed to the next stage.
  template<class InBufferT, class OutBufferT>
  class APipelineFinal : public IPipelineBufferReceiver<InBufferT> {
  public:
    // Function:   dispenseOutput
    // Purpose:    Tells the pipeline to dispense the output generated from this stage.
    // Parameters: None.
    // Returns:    An owning pointer to the final output buffer, which may be null if no output is
    //             waiting.
    std::unique_ptr<OutBufferT>
    dispenseOutput();
  protected:
    // Function:   readyOutput
    // Purpose:    Readies a buffer for dispensal.
    // Parameters: outBuffer - The buffer to dispense.
    // Returns:    None.
    void
    readyOutput(std::unique_ptr<OutBufferT> a_outBuffer);
  private:
    std::unique_ptr<OutBufferT> m_waitingBuffer;
  };
}

#include "APipelineFinal.tpp"

#endif
