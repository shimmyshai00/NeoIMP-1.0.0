#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Render.tpp
 * PURPOSE: Implements the Render algorithm.
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

#include "../Components/Content/Background.hpp"
#include "Impl/CellRender.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  template<class GilSpecT>
  void Render::operator()(Image<GilSpecT> &image) {
    // For now, only render the background layer.
    typedef typename GilSpecT::bkg_view_t View;
    auto contentComponent = image.getLayer(0)
      .template findComponentById<Components::Content::Background<GilSpecT>>(
        Layer<GilSpecT>::c_contentComponentId
      );

    if(contentComponent == nullptr) {
      return; // nothing to render!
    }

    View src = contentComponent->getView(m_srcRect);

    // Figure out a mapping from the rectangle src into m_destRect (actually, again, the inverse
    // mapping). We can then intersect the cell rectangles with m_destRect and map them to
    // rectangles in src to cut it up into smaller views and then render them into each cell.
    auto invMapping = [=](Math::Point2D<std::size_t> pt) {
      float mapX = ((0.0f + pt.x() - m_dstRect.x1()) / m_dstRect.getWidth()) * src.width();
      float mapY = ((0.0f + pt.x() - m_dstRect.y1()) / m_dstRect.getHeight()) * src.height();

      return typename View::point_t(floor(mapX + 0.5f), floor(mapY + 0.5f));
    };

    for(std::size_t yCell(0); yCell < m_gridBuffer->getNumCellsY(); ++yCell) {
      for(std::size_t xCell(0); xCell < m_gridBuffer->getNumCellsX(); ++xCell) {
        Math::Rect<std::size_t> cellRect(m_gridBuffer->getCellRect(xCell, yCell));
        if(cellRect.intersectsWith(m_dstRect)) {
          Math::Rect<std::size_t> cellDestIntersect(cellRect.intersect(m_dstRect));
          if(!m_gridBuffer->isCellAllocated(xCell, yCell)) {
            m_gridBuffer->allocateCell(xCell, yCell);
          }

          typename View::point_t ulPoint = invMapping(cellDestIntersect.getUpperLeft());
          typename View::point_t lrPoint = invMapping(cellDestIntersect.getLowerRight());
          typename View::point_t dims(lrPoint.x - ulPoint.x, lrPoint.y - ulPoint.y);

          View subView = boost::gil::subimage_view(src, ulPoint, dims);

          Buffers::RenderCell *cell = m_gridBuffer->findCell(xCell, yCell);
          Impl::renderOntoCell(cell, cellDestIntersect, subView);
        }
      }
    }
  }
}

#endif
