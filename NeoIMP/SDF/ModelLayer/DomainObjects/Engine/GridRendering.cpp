/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GridRendering.cpp
 * PURPOSE: Implements the GridRendering class.
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

#include "GridRendering.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  GridRendering::GridRendering(std::size_t numCellsX,
                               std::size_t numCellsY,
                               std::size_t cellWidth,
                               std::size_t cellHeight,
                               ERenderPixelFormat pixelFormat
                              )
    : m_numCellsX(numCellsX),
      m_numCellsY(numCellsY),
      m_cellWidth(cellWidth),
      m_cellHeight(cellHeight),
      m_pixelFormat(pixelFormat),
      m_cells(nullptr)
  {
    m_cells = new RenderCell *[m_cellWidth*m_cellHeight];
    for(std::size_t i(0); i < m_cellWidth*m_cellHeight; ++i) {
      m_cells[i] = nullptr;
    }
  }

  GridRendering::~GridRendering() {
    for(std::size_t i(0); i < m_cellWidth*m_cellHeight; ++i) {
      if(m_cells[i] != nullptr) {
        delete m_cells[i];
        m_cells[i] = nullptr;
      }
    }

    delete[] m_cells;
    m_cells = nullptr;
  }

  std::size_t
  GridRendering::getNumCellsX() const {
    return m_numCellsX;
  }

  std::size_t
  GridRendering::getNumCellsY() const {
    return m_numCellsY;
  }

  std::size_t
  GridRendering::getCellWidth() const {
    return m_cellWidth;
  }

  std::size_t
  GridRendering::getCellHeight() const {
    return m_cellHeight;
  }

  ERenderPixelFormat
  GridRendering::getPixelFormat() const {
    return m_pixelFormat;
  }

  std::size_t
  GridRendering::getTotalWidth() const {
    return m_numCellsX*m_cellWidth;
  }

  std::size_t
  GridRendering::getTotalHeight() const {
    return m_numCellsY*m_cellHeight;
  }

  void
  GridRendering::allocateCell(std::size_t cellX,
                              std::size_t cellY
                             )
  {
    // TBA: throw on OoB?
    if((cellX < m_numCellsX) && (cellY < m_numCellsY)) {
      std::size_t offs = cellY*m_numCellsX + cellX;
      if(m_cells[offs] == nullptr) {
        // NB: probably should use some kind of pool allocator here to make these more efficient
        m_cells[offs] = new RenderCell(m_cellWidth, m_cellHeight, m_pixelFormat);
      }
    }
  }

  void
  GridRendering::freeCell(std::size_t cellX,
                          std::size_t cellY
                         )
  {
    // TBA: throw on OoB?
    if((cellX < m_numCellsX) && (cellY < m_numCellsY)) {
      std::size_t offs = cellY*m_numCellsX + cellX;
      if(m_cells[offs] != nullptr) {
        // NB: probably should use some kind of pool allocator here to make these more efficient
        delete m_cells[offs];
        m_cells[offs] = nullptr;
      }
    }
  }

  bool
  GridRendering::isCellAllocated(std::size_t cellX,
                                 std::size_t cellY
                                )
  {
    if((cellX < m_numCellsX) && (cellY < m_numCellsY)) {
      std::size_t offs = cellY*m_numCellsX + cellX;
      return (m_cells[offs] != nullptr);
    } else {
      // TBA: throw on OoB?
      return false;
    }
  }

  RenderCell *
  GridRendering::findCell(std::size_t x,
                          std::size_t y
                         )
  {
    return getCell(x / m_cellWidth, y / m_cellHeight);
  }

  Math::Rect<std::size_t>
  GridRendering::getCellRect(std::size_t cellX,
                             std::size_t cellY
                            ) const
  {
    std::size_t cellRectX1(cellX * m_cellWidth);
    std::size_t cellRectY1(cellY * m_cellHeight);

    Math::Rect<std::size_t> rect(cellRectX1, cellRectY1,
      cellRectX1 + m_cellWidth - 1, cellRectY1 + m_cellHeight - 1);

    return rect;
  }

  bool
  GridRendering::arePointsInSameCell(std::size_t x1,
                                     std::size_t y1,
                                     std::size_t x2,
                                     std::size_t y2
                                    ) const
  {
    return ((x1 / m_cellWidth) == (x2 / m_cellWidth)) &&
           ((y1 / m_cellHeight) == (y2 / m_cellHeight));
  }

  RenderCell *
  GridRendering::getCell(std::size_t cellX,
                         std::size_t cellY
                        )
  {
    if((cellX < m_numCellsX) && (cellY < m_numCellsY)) {
      std::size_t offs = cellY*m_numCellsX + cellX;
      return m_cells[offs];
    } else {
      // TBA: throw on OoB?
      return nullptr;
    }
  }
}
