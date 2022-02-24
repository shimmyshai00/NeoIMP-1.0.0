/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderingService.cpp
 * PURPOSE: Implements the RenderingService class.
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

#include "RenderingService.hpp"

#include "../../DomainObjects/Engine/Gil/Algorithm/Render.hpp"

namespace SDF::ModelLayer::Services::Gil {
  RenderingService::RenderingService(
    Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *imageRepository,
    Repositories::IRepository<DomainObjects::Engine::Rendering> *renderingRepository
  )
    : m_imageRepository(imageRepository),
      m_renderingRepository(renderingRepository),
      m_nextRenderingHandle(0)
  {
  }

  Common::Handle
  RenderingService::renderImage(Common::Handle imageHandle) {
    using namespace DomainObjects;

    Engine::Rendering *rendering(findRenderingOrCreateFor(imageHandle));
    Common::Handle renderingHandle(m_renderingHandleMap[imageHandle]);

    Engine::Gil::Algorithm::Render<Engine::Gil::AnyGilImage> render(rendering);

    m_imageRepository->retrieve(imageHandle)->applyOperation(render, nullptr);

    return renderingHandle;
  }

  Common::Handle
  RenderingService::renderSubregion(Common::Handle imageHandle,
                                    std::size_t x1,
                                    std::size_t y1,
                                    std::size_t x2,
                                    std::size_t y2
                                   )
  {
    using namespace DomainObjects;

    if(m_renderingHandleMap.find(imageHandle) == m_renderingHandleMap.end()) {
      return renderImage(imageHandle);
    } else {
      Common::Handle renderingHandle(m_renderingHandleMap[imageHandle]);
      Engine::Rendering *rendering(m_renderingRepository->retrieve(renderingHandle));
      Engine::Gil::Algorithm::Render<Engine::Gil::AnyGilImage> render(rendering);
      m_imageRepository->retrieve(imageHandle)->applyOperation(render,
        Math::Rect<std::size_t>(x1, y1, x2, y2), nullptr);

      return renderingHandle;
    }
  }

  void
  RenderingService::retrieveRenderData(Common::Handle renderHandle,
                                       unsigned char * &originPtr,
                                       std::ptrdiff_t &rowStride,
                                       std::size_t &pixelWidth
                                      )
  {
    using namespace DomainObjects;

    Engine::Rendering *rendering(m_renderingRepository->retrieve(renderHandle));
    if(rendering != nullptr) {
      originPtr = rendering->getOrigin();
      rowStride = rendering->getRowStride();
      pixelWidth = rendering->getPixelWidth();
    } else {
      // TBA: throw
    }
  }
}

namespace SDF::ModelLayer::Services::Gil {
  // Private members.
  DomainObjects::Engine::Rendering *
  RenderingService::findRenderingOrCreateFor(Common::Handle imageHandle) {
    using namespace DomainObjects;

    Engine::Rendering *rendering(nullptr);

    if(m_renderingHandleMap.find(imageHandle) == m_renderingHandleMap.end()) {
      Common::Handle renderingHandle = m_nextRenderingHandle++;
      m_renderingHandleMap[imageHandle] = renderingHandle;

      Engine::Gil::AnyGilImage *image(m_imageRepository->retrieve(imageHandle));
      if(image == nullptr) {
        // TBA: throw
      }

      std::size_t imageWidth(image->getWidthPx());
      std::size_t imageHeight(image->getHeightPx());

      rendering = m_renderingRepository->insert(renderingHandle,
        std::make_unique<Engine::Rendering>(imageWidth, imageHeight, Engine::RENDERFMT_RGB32));
      m_renderingHandleMap[imageHandle] = renderingHandle;
    } else {
      rendering = m_renderingRepository->retrieve(m_renderingHandleMap[imageHandle]);
    }

    return rendering;
  }
}
