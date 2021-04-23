#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_RENDERER_BUFFERFACTORY_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_RENDERER_BUFFERFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BufferFactory.hpp
 * PURPOSE: Defines the BufferFactory class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IRenderBufferFactory.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <cstddef>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IRenderBuffer;
  }

  namespace DomainObjects::Algorithms::Renderer {
    // Class:      BufferFactory
    // Purpose:    Creates new rendering buffers.
    // Parameters: None.
    class BufferFactory : public Services::AbstractDomain::IRenderBufferFactory {
    public:
      INJECT(BufferFactory());

      std::unique_ptr<Services::AbstractDomain::IRenderBuffer>
      createRGB32Buffer(std::size_t width,
                        std::size_t height
                      );
    private:
      int m_nextUid;
    };
  }
}

#endif
