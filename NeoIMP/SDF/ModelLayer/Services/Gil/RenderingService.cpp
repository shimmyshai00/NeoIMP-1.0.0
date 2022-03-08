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

#include "../../Math/Rect.hpp"
//#include "../../DomainObjects/Engine/Gil/Algorithm/CellRenderer.hpp"
#include "../../Exceptions.hpp"

namespace SDF::ModelLayer::Services::Gil {
  namespace Impl {
    class RenderRegion : public UILayer::AbstractModel::Defs::IRenderRegion {
    public:
      RenderRegion(DomainObjects::Engine::Buffers::GridRendering *rendering,
                   std::size_t x1,
                   std::size_t y1,
                   std::size_t x2,
                   std::size_t y2
                  )
        : m_rendering(rendering),
          m_x1(x1),
          m_y1(y1),
          m_x2(x2),
          m_y2(y2)
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
      getElementContaining(std::size_t x, std::size_t y) {
        UILayer::AbstractModel::Defs::IRenderRegion::TileElement rv;

        rv.xOrigin = 0;
        rv.yOrigin = 0;
        rv.width = 0;
        rv.height = 0;
        rv.originPtr = nullptr;
        rv.rowStride = 0;

        std::size_t cellX(x / m_rendering->getCellWidth());
        std::size_t cellY(y / m_rendering->getCellHeight());

        // The region bounded is the intersection between this cell's rectangle and the region
        // rectangle.
        if(m_rendering->isCellAllocated(cellX, cellY)) {
          Math::Rect<std::size_t> cellRect(m_rendering->getCellRect(cellX, cellY));
          Math::Rect<std::size_t> regionRect(m_x1, m_y1, m_x2, m_y2);

          if(cellRect.intersectsWith(regionRect)) {
            Math::Rect<std::size_t> overlap(cellRect.intersect(regionRect));

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
      traverse(std::function<void (TileElement el)> op) {
        UILayer::AbstractModel::Defs::IRenderRegion::TileElement el;

        Math::Rect<std::size_t> regionRect(m_x1, m_y1, m_x2, m_y2);
        Math::Rect<std::size_t> tileRect(0, 0, 0, 0);

        std::size_t curX(m_x1);
        std::size_t curY(m_y1);

        while(curY < m_y2) {
          while(curX < m_x2) {
            std::size_t cellX(curX / m_rendering->getCellWidth());
            std::size_t cellY(curY / m_rendering->getCellHeight());

            Math::Rect<std::size_t> cellRect(m_rendering->getCellRect(cellX, cellY));
            tileRect = regionRect.intersect(cellRect);

            if(m_rendering->isCellAllocated(cellX, cellY)) {
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

            op(el);

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
    Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *imageRepository,
    Repositories::IRepository<DomainObjects::Engine::Buffers::GridRendering> *renderingRepository
  )
    : m_imageRepository(imageRepository),
      m_renderingRepository(renderingRepository),
      m_nextRenderingHandle(0)
  {
  }

  Common::Handle
  RenderingService::createStaticRendering(Common::Handle imageHandle) {
    // NB: shift this complex rendering logic down into a new DomainObject?
    using namespace DomainObjects;

    Engine::Gil::AnyGilImage *image(m_imageRepository->retrieve(imageHandle));
    if(image != nullptr) {
      std::size_t imageWidth(image->getWidthPx());
      std::size_t imageHeight(image->getHeightPx());

      Common::Handle renderingHandle(m_nextRenderingHandle++);
      std::unique_ptr<Engine::Buffers::GridRendering> rendering(
        new Engine::Buffers::GridRendering(1, 1, imageWidth, imageHeight, Engine::RENDERFMT_RGB32));
      rendering->allocateCell(0, 0);

      Engine::Buffers::RenderCell *renderCell = rendering->getCell(0, 0);
      Math::Rect<std::size_t> outRect(0, 0, imageWidth-1, imageHeight-1);
      Math::Rect<float> renderRect(0.0f, 0.0f, imageWidth - 1.0f, imageHeight - 1.0f);

      /*
      Engine::Gil::Algorithm::CellRenderer<Engine::Gil::AnyGilImage> renderer(renderCell, outRect,
        false);
      image->applyOperation(renderer, renderRect, nullptr);
      */

      m_renderingRepository->insert(renderingHandle, std::move(rendering));

      return renderingHandle;
    } else {
      throw ImageNotFoundException(imageHandle);
    }
  }

  std::shared_ptr<UILayer::AbstractModel::Defs::IRenderRegion>
  RenderingService::getRegion(Common::Handle renderHandle,
                              std::size_t x1,
                              std::size_t y1,
                              std::size_t x2,
                              std::size_t y2
                             )
  {
    using namespace UILayer;
    using namespace DomainObjects;

    Engine::Buffers::GridRendering *rendering(m_renderingRepository->retrieve(renderHandle));
    if(rendering != nullptr) {
      // Right now, we only support static renderings with 1 cell.
      return std::shared_ptr<AbstractModel::Defs::IRenderRegion>(
        new Impl::RenderRegion(rendering, x1, y1, x2, y2)
      );
    } else {
      throw ImageNotFoundException(renderHandle);
    }
  }

  void
  RenderingService::deleteRendering(Common::Handle renderHandle) {
    m_renderingRepository->erase(renderHandle);
  }
}
