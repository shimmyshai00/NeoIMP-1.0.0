#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_BUFFERS_GRIDRENDERING_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_BUFFERS_GRIDRENDERING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GridRendering.hpp
 * PURPOSE: Defines the GridRendering class.
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

#include "../../../Math/Rect.hpp"
#include "../ERenderPixelFormat.hpp"
#include "RenderCell.hpp"

#include <cstddef>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Buffers {
  // Class:      GridRendering
  // Purpose:    Defines a large rendering as a grid of one or more uniformly-sized rendering cells.
  // Parameters: None.
  class GridRendering {
  public:
    // Function:   GridRendering
    // Purpose:    Create a new grid rendering. By default, all cells will be unallocated (return
    //             nullptr when their pointers are fetched via getCell).
    // Parameters: numCellsX - The number of cells in the X-direction.
    //             numCellsY - The number of cells in the Y-direction.
    //             cellWidth - The width of a single cell in pixels.
    //             cellHeight - The height of a single cell in pixels.
    //             pixelFormat - The pixel format to use.
    GridRendering(std::size_t numCellsX,
                  std::size_t numCellsY,
                  std::size_t cellWidth,
                  std::size_t cellHeight,
                  ERenderPixelFormat pixelFormat
                 );

    ~GridRendering();

    // Function:   getNumCellsX
    // Purpose:    Get the number of cells in the X-direction in this grid.
    // Parameters: None.
    // Returns:    The number of cells in the X-direction in the grid.
    std::size_t
    getNumCellsX() const;

    // Function:   getNumCellsY
    // Purpose:    Get the number of cells in the Y-direction in this grid.
    // Parameters: None.
    // Returns:    The number of cells in the Y-direction in the grid.
    std::size_t
    getNumCellsY() const;

    // Function:   getCellWidth
    // Purpose:    Get the width of a cell in pixels.
    // Parameters: None.
    // Returns:    The width of a cell in pixels.
    std::size_t
    getCellWidth() const;

    // Function:   getCellHeight
    // Purpose:    Get the height of a cell in pixels.
    // Parameters: None.
    // Returns:    The height of a cell in pixels.
    std::size_t
    getCellHeight() const;

    // Function:   getPixelFormat
    // Purpose:    Get the pixel format stored in this rendering.
    // Parameters: None.
    // Returns:    The stored pixel format.
    ERenderPixelFormat
    getPixelFormat() const;

    // Function:   getTotalWidth
    // Purpose:    Get the total width of the rendering in pixels.
    // Parameters: None.
    // Returns:    The total width in pixels.
    std::size_t
    getTotalWidth() const;

    // Function:   getTotalHeight
    // Purpose:    Get the total height of the rendering in pixels.
    // Parameters: None.
    // Returns:    The total height in pixels.
    std::size_t
    getTotalHeight() const;

    // Function:   allocateCell
    // Purpose:    Allocates memory for a cell at a given grid position. Does nothing if the cell
    //             is already allocated.
    // Parameters: cellX - The cell's grid X-coordinate.
    //             cellY - The cell's grid Y-coordinate.
    // Returns:    None.
    void
    allocateCell(std::size_t cellX,
                 std::size_t cellY
                );

    // Function:   freeCell
    // Purpose:    Frees the memory associated with a cell at the given position, i.e. deallocates
    //             that cell.
    // Parameters: cellX - The cell's grid X-coordinate.
    //             cellY - The cell's grid Y-coordinate.
    // Returns:    None.
    void
    freeCell(std::size_t cellX,
             std::size_t cellY
            );

    // Function:   isCellAllocated
    // Purpose:    Returns if the cell at a given position is allocated. Same as
    //             evaluating getCell(...) != nullptr.
    // Parameters: cellX - The cell's grid X-coordinate.
    //             cellY - The cell's grid Y-coordinate.
    // Returns:    None.
    bool
    isCellAllocated(std::size_t cellX,
                    std::size_t cellY
                   );

    // Function:   findCell
    // Purpose:    Finds the cell containing a given pixel coordinate.
    // Parameters: x - The X-coordinate of the pixel.
    //             y - The Y-coordinate of the pixel.
    // Returns:    The cell so found (or nullptr if none).
    RenderCell *
    findCell(std::size_t x,
             std::size_t y
            );

    // Function:   getCellRect
    // Purpose:    Gets the bounding rectangle for a given cell.
    // Parameters: cellX - The cell's grid X-coordinate.
    //             cellY - The cell's grid Y-coordinate.
    // Returns:    The bounding rectangle.
    Math::Rect<std::size_t>
    getCellRect(std::size_t cellX,
                std::size_t cellY
               ) const;

    // Function:   arePointsInSameCell
    // Purpose:    Finds if two points are in the same cell.
    // Parameters: x1, y1 - The coordinates of the first point.
    //             x2, y2 - The coordinates of the second point.
    // Returns:    Whether (x1, y1) and (x2, y2) are in the same cell.
    bool
    arePointsInSameCell(std::size_t x1,
                        std::size_t y1,
                        std::size_t x2,
                        std::size_t y2
                       ) const;

    // Function:   getCell
    // Purpose:    Get a pointer to the cell data for a given cell.
    // Parameters: cellX - The cell's grid X-coordinate.
    //             cellY - The cell's grid Y-coordinate.
    RenderCell *
    getCell(std::size_t cellX,
            std::size_t cellY
           );
  private:
    std::size_t m_numCellsX;
    std::size_t m_numCellsY;
    std::size_t m_cellWidth;
    std::size_t m_cellHeight;
    ERenderPixelFormat m_pixelFormat;

    RenderCell **m_cells;
  };
}

#endif
