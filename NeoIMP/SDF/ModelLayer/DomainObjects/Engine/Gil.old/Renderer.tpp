#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_RENDERER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_RENDERER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Renderer.tpp
 * PURPOSE: Implements the Renderer template.
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

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  Renderer::Renderer() {
  }

  void
  Renderer::staticRender(GridRendering &outBuffer,
                         IImage<ImplT, ImplEntityT> &image
                        )
  {
    using namespace DomainObjects;

    ImageMeasure imageWidth(image.getWidthPx());
    ImageMeasure imageHeight(image.getHeightPx());

    Engine::RenderCell *renderCell = outBuffer.getCell(0, 0);
    Math::Rect<std::size_t> outRect(0, 0, imageWidth, imageHeight);
    ImageRect renderRect(0.0f, 0.0f, imageWidth, imageHeight);

    Engine::Gil::Algorithm::CellRenderer<Engine::Gil::AnyGilImage> renderer(renderCell, outRect,
      false);
    image->applyOperation(renderer, renderRect, nullptr);

    m_renderingRepository->insert(renderingHandle, std::move(rendering));

    return renderingHandle;
  }
}

#endif
