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

#include "../../DomainObjects/Math/Rect.hpp"
#include "../../DomainObjects/Engine/Gil/Algorithm/Render.hpp"
#include "../../DomainObjects/Engine/Gil/Algorithm/Apply.hpp"

namespace SDF::Editor::ModelLayer::Services::Gil {
  namespace Impl {
    class RenderRegion : public UILayer::AbstractModel::Defs::IRenderRegion {
    public:
      RenderRegion(
        DomainObjects::Engine::Buffers::GridRendering *a_rendering,
        std::size_t a_x1,
        std::size_t a_y1,
        std::size_t a_x2,
        std::size_t a_y2
      )
        : m_rendering(a_rendering),
          m_x1(a_x1),
          m_y1(a_y1),
          m_x2(a_x2),
          m_y2(a_y2)
      {
      }

      std::size_t
      getRegionX1() const {
        return m_x1;
      }

      std::size_t
      getRegionY1() const {
        return m_y1;
      }

      std::size_t
      getRegionX2() const {
        return m_x2;
      }

      std::size_t
      getRegionY2() const {
        return m_y2;
      }

      UILayer::AbstractModel::Defs::IRenderRegion::TileElement
      getElementContaining(std::size_t a_x, std::size_t a_y) {
        using namespace UILayer::AbstractModel::Defs;
        using namespace DomainObjects::Math;

        IRenderRegion::TileElement rv;

        rv.xOrigin = 0;
        rv.yOrigin = 0;
        rv.width = 0;
        rv.height = 0;
        rv.originPtr = nullptr;
        rv.rowStride = 0;

        std::size_t cellX(a_x / m_rendering->getCellWidth());
        std::size_t cellY(a_y / m_rendering->getCellHeight());

        // The region bounded is the intersection between this cell's rectangle and the region
        // rectangle.
        if(m_rendering->isCellAllocated(cellX, cellY)) {
          Rect<std::size_t> cellRect(m_rendering->getCellRect(cellX, cellY));
          Rect<std::size_t> regionRect(m_x1, m_y1, m_x2, m_y2);

          if(cellRect.intersectsWith(regionRect)) {
            Rect<std::size_t> overlap(cellRect.intersect(regionRect));

            rv.xOrigin = overlap.x1();
            rv.yOrigin = overlap.y1();
            rv.width = overlap.getWidth();
            rv.height = overlap.getHeight();
            rv.originPtr = m_rendering->getCell(cellX, cellY)->getOrigin();
            rv.rowStride = m_rendering->getCell(cellX, cellY)->getRowStride();
            std::size_t pixelWidth = m_rendering->getCell(cellX, cellY)->getPixelWidth();

            rv.originPtr += ((rv.rowStride * overlap.y1()) + (pixelWidth * overlap.x1()));
          }
        }

        return rv;
      }

      void
      traverse(std::function<void (TileElement el)> a_op) {
        using namespace UILayer::AbstractModel::Defs;
        using namespace DomainObjects::Math;

        IRenderRegion::TileElement el;

        Rect<std::size_t> regionRect(m_x1, m_y1, m_x2, m_y2);
        Rect<std::size_t> tileRect(0, 0, 0, 0);

        std::size_t curX(m_x1);
        std::size_t curY(m_y1);

        while(curY < m_y2) {
          curX = m_x1;

          while(curX < m_x2) {
            std::size_t cellX(curX / m_rendering->getCellWidth());
            std::size_t cellY(curY / m_rendering->getCellHeight());

            Rect<std::size_t> cellRect(m_rendering->getCellRect(cellX, cellY));
            tileRect = regionRect.intersect(cellRect);

            if(((cellX < m_rendering->getNumCellsX()) && (cellY < m_rendering->getNumCellsY())) &&
              m_rendering->isCellAllocated(cellX, cellY))
            {
              el.xOrigin = tileRect.x1();
              el.yOrigin = tileRect.y1();
              el.width = tileRect.getWidth();
              el.height = tileRect.getHeight();
              el.originPtr = m_rendering->getCell(cellX, cellY)->getOrigin();
              el.rowStride = m_rendering->getCell(cellX, cellY)->getRowStride();
              std::size_t pixelWidth = m_rendering->getCell(cellX, cellY)->getPixelWidth();

              el.originPtr += ((el.rowStride * el.yOrigin) + (pixelWidth * el.xOrigin));
            } else {
              el.xOrigin = 0;
              el.yOrigin = 0;
              el.width = 0;
              el.height = 0;
              el.originPtr = nullptr;
              el.rowStride = 0;
            }

            a_op(el);

            curX += tileRect.getWidth();
          }

          curY += tileRect.getHeight();
        }
      }
    private:
      DomainObjects::Engine::Buffers::GridRendering *m_rendering;
      std::size_t m_x1, m_y1, m_x2, m_y2;
    };
  }

  RenderingService::RenderingService(
    AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *a_imageRepository,
    Common::Data::IOwningCrudable<Common::Handle, DomainObjects::Engine::Buffers::GridRendering> *
      a_renderingRepository
  )
    : m_imageRepository(a_imageRepository),
      m_renderingRepository(a_renderingRepository),
      m_nextRenderingHandle(0)
  {
  }

  Common::Handle
  RenderingService::createStaticRendering(Common::Handle a_imageHandle) {
    using namespace DomainObjects::Engine::Gil::Algorithm;
    using namespace DomainObjects::Engine::Gil;
    using namespace DomainObjects::Engine::Image;
    using namespace DomainObjects::Engine::Buffers;

    Any_Image *image(m_imageRepository->retrieve(a_imageHandle));

    Common::Handle renderingHandle(m_nextRenderingHandle++);

    // NB: should modify to not need creating a new buffer every time
    std::unique_ptr<GridRendering> resultRecv;
    Render render(&resultRecv);
    apply(render, *image);

    if(m_renderingRepository->has(renderingHandle)) {
      m_renderingRepository->deleteO(renderingHandle);
    }

    m_renderingRepository->create(renderingHandle, std::move(resultRecv));

    return renderingHandle;
  }

  std::shared_ptr<UILayer::AbstractModel::Defs::IRenderRegion>
  RenderingService::getRegion(Common::Handle a_renderHandle,
                              std::size_t a_x1,
                              std::size_t a_y1,
                              std::size_t a_x2,
                              std::size_t a_y2
                             )
  {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects;

    Engine::Buffers::GridRendering *rendering(m_renderingRepository->retrieve(a_renderHandle));

    // Right now, we only support static renderings with 1 cell.
    return std::shared_ptr<IRenderRegion>(
      new Impl::RenderRegion(rendering, a_x1, a_y1, a_x2, a_y2)
    );
  }

  void
  RenderingService::deleteRendering(Common::Handle a_renderHandle) {
    m_renderingRepository->deleteO(a_renderHandle);
  }
}
