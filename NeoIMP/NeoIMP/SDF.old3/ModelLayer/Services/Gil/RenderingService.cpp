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

namespace SDF::ModelLayer::Services::Gil {
  RenderingService::RenderingService(
    Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *imageRepository,
    Repositories::IRepository<DomainObjects::Engine::Rendering> *renderingRepository
  )
    : m_imageRepository(imageRepository),
      m_renderingRepository(renderingRepository)
  {
  }

  Defs::Handle
  RenderingService::renderImage(Defs::Handle imageHandle) {

  }

  Defs::Handle
  RenderingService::renderSubregion(Defs::Handle imageHandle,
                                    std::size_t x1,
                                    std::size_t y1,
                                    std::size_t x2,
                                    std::size_t y2
                                   )
  {

  }

  void
  RenderingService::retrieveRenderData(Defs::Handle renderHandle,
                                       unsigned char * &originPtr,
                                       std::ptrdiff_t &rowStride,
                                       std::size_t &pixelWidth
                                      )
  {

  }
}
