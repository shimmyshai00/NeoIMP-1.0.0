#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_CELLRENDERER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_CELLRENDERER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CellRenderer.hpp
 * PURPOSE: Defines the CellRenderer template.
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

#include "../../Math/Rect.hpp"
#include "../../Dimensions.hpp"
#include "../../IImageOperation.hpp"
#include "../../RenderCell.hpp"
#include "../Image.hpp"
#include "../AnyImage.hpp"

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  // Class:      CellRenderer
  // Purpose:    Renders a GIL image view to a single rendering buffer cell.
  // Parameters: GilImageT - The type of GIL image to use.
  //             GilImageTs - The variant types to use.
  template<class GilImageT>
  class CellRenderer : public IImageOperation<Image<GilImageT>> {
  public:
    // Function:   CellRenderer
    // Purpose:    Construct the cell renderer.
    // Parameters: outCell - The rendering cell to render to.
    //             outRect - The rectangle in the output rendering cell to receive the rendering.
    //             antialias - Whether to use antialiasing for shrunken rectangles (i.e. when one
    //                         or more dimensions of outRect is larger than renderRect). TO BE
    //                         ADDED.
    CellRenderer(RenderCell *outCell,
                 Math::Rect<std::size_t> outRect,
                 bool antialias
                );

    bool
    performOperation(Image<GilImageT> &imageImpl,
                     const std::vector<OpRegion> &regions,
                     IProgressListener *progress
                    );
  private:
    RenderCell *m_outCell;
    Math::Rect<std::size_t> m_outRect;
    bool m_antialias;
  };
}

#include "CellRenderer.tpp"

#endif
