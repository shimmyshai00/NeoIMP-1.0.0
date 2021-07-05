#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IRENDERBUFFERFACTORY_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IRENDERBUFFERFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRenderBufferFactory.hpp
 * PURPOSE: Defines the IRenderBufferFactory interface.
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

#include <memory>
#include <cstddef>

namespace SDF::ModelLayer::Services::AbstractDomain {
  class IRenderBuffer;

  // Class:      IRenderBufferFactory
  // Purpose:    Defines a factory interface for creating render buffers.
  // Parameters: None.
  class IRenderBufferFactory {
  public:
    virtual ~IRenderBufferFactory() = default;

    // Function:   createRGB32Buffer
    // Purpose:    Create a new render buffer suitable for holding RGB32 format data.
    // Parameters: width - The desired width of the buffer in pixels.
    //             height - The desired height of the buffer in pixels.
    // Returns:    An owning pointer to the new buffer.
    virtual std::unique_ptr<IRenderBuffer>
    createRGB32Buffer(std::size_t width,
                      std::size_t height
                     ) = 0;
  };
}

#endif
