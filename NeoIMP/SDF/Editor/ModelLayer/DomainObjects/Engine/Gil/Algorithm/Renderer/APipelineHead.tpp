#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_APIPELINEHEAD_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_APIPELINEHEAD_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    APipelineHead.tpp
 * PURPOSE: Implements the APipelineHead base template.
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

#include "../../../../Exceptions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Renderer {
  template<class InBufferT, class OutBufferT>
  IPipelineBufferReceiver<OutBufferT> *
  APipelineHead<InBufferT, OutBufferT>::attachNext(
    std::unique_ptr<IPipelineBufferReceiver<OutBufferT>> next
  ) {
    m_next = std::move(next);

    return m_next.get();
  }

  template<class InBufferT, class OutBufferT>
  void
  APipelineHead<InBufferT, OutBufferT>::activateNextStage(
    std::unique_ptr<OutBufferT> outBuffer,
    RenderCtx &renderCtx
  ) {
    if(m_next) {
      m_next->process(std::move(outBuffer), renderCtx);
    } else {
      throw BrokenPipelineException();
    }
  }
}

#endif