#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_IMPL_CELLRENDER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_IMPL_CELLRENDER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CellRender.hpp
 * PURPOSE: Defines the CellRender algorithm.
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

#include "../../../../../Math/Rect.hpp"
#include "../../../Buffers/RenderCell.hpp"
#include "../../../Dimensions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Algorithm::Impl {
  // Provides implementation detail for rendering onto a single buffer cell.
  template<class View>
  void renderOntoCell(Engine::Buffers::RenderCell *dstCell,
                      Math::Rect<std::size_t> dstRect,
                      const View &view
                     );
}

#endif
