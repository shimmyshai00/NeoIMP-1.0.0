#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_PLSTESTRENDER_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDERER_PLSTESTRENDER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PLSTestRender.tpp
 * PURPOSE: Implements the PLSTestRender template.
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
#include "../../../Dimensions.hpp"
#include "../../Components/Content/Background.hpp"
#include "CellRender.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Renderer {
  template<class GilSpecT>
  PLSTestRender<GilSpecT>::PLSTestRender() {
  }

  template<class GilSpecT>
  void
  PLSTestRender<GilSpecT>::beginProcessing(const Image::Image<GilSpecT> &inputData) {
    // Just render the entirety of the background layer to one cell.
    std::unique_ptr<Buffers::GridRendering> gridBuffer(new Buffers::GridRendering(1, 1,
      inputData.getWidthPx(), inputData.getHeightPx(), RENDERFMT_RGB32));

    // Adapted old code from the previous rendering system without pipeline. This contains a stub
    // for a more localized render that may be useful later on.
    if((inputData.getWidthPx() < 0) || (inputData.getHeightPx() < 0)) {
      // Shouldn't happen
      throw InvalidDimensionsException(inputData.getWidthPx(), inputData.getHeightPx());
    }

    Math::Rect<std::size_t> dstRect(0, 0, inputData.getWidthPx(), inputData.getHeightPx());
    ImageRect srcRect(0, 0, inputData.getWidthPx(), inputData.getHeightPx());

    // For now, only render the background layer.
    typedef typename GilSpecT::bkg_view_t View;
    auto contentComponent = inputData.getLayer(0)
      .template getContentComponentAs<Components::Content::Background<GilSpecT>>();

    if(contentComponent == nullptr) {
      return; // nothing to render!
    }

    typename View::const_t src = contentComponent->getView(srcRect);

    // Figure out a mapping from the rectangle src into m_destRect (actually, again, the inverse
    // mapping). We can then intersect the cell rectangles with m_destRect and map them to
    // rectangles in src to cut it up into smaller views and then render them into each cell.
    auto invMapping = [=](Math::Point2D<std::size_t> pt) {
      float mapX = ((0.0f + pt.x() - dstRect.x1()) / dstRect.getWidth()) * src.width();
      float mapY = ((0.0f + pt.y() - dstRect.y1()) / dstRect.getHeight()) * src.height();

      return typename View::point_t(floor(mapX + 0.5f), floor(mapY + 0.5f));
    };

    for(std::size_t yCell(0); yCell < gridBuffer->getNumCellsY(); ++yCell) {
      for(std::size_t xCell(0); xCell < gridBuffer->getNumCellsX(); ++xCell) {
        Math::Rect<std::size_t> cellRect(gridBuffer->getCellRect(xCell, yCell));
        if(cellRect.intersectsWith(dstRect)) {
          Math::Rect<std::size_t> cellDestIntersect(cellRect.intersect(dstRect));
          if(!gridBuffer->isCellAllocated(xCell, yCell)) {
            gridBuffer->allocateCell(xCell, yCell);
          }

          typename View::point_t ulPoint = invMapping(cellDestIntersect.getUpperLeft());
          typename View::point_t lrPoint = invMapping(cellDestIntersect.getLowerRight());
          typename View::point_t dims(lrPoint.x - ulPoint.x, lrPoint.y - ulPoint.y);

          typename View::const_t subView = boost::gil::subimage_view(src, ulPoint, dims);

          Buffers::RenderCell *cell = gridBuffer->findCell(xCell, yCell);
          renderOntoCell(cell, cellDestIntersect, subView);
        }
      }
    }

    // Pass on to the next pipeline stage.
    this->activateNextStage(std::move(gridBuffer), m_ctx);
  }
}

#endif
