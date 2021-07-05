#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IRENDERBUFFER_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IRENDERBUFFER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRenderBuffer.hpp
 * PURPOSE: Defines the IRenderBuffer interface.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IDomainObject.hpp>

#include <cstddef>

namespace SDF::ModelLayer::Services::AbstractDomain {
  // Class:      IRenderBuffer
  // Purpose:    Defines an interface for objects that hold rendered images. The rendered data, accessible through the
  //             getData() method, should be in a form suitable to be directly used by a user interface display package.
  // Parameters: None.
  class IRenderBuffer : public IDomainObject<IRenderBuffer> {
  public:
    virtual ~IRenderBuffer() = default;

    // Function:   getWidth
    // Purpose:    Get the width of the render buffer in pixels.
    // Parameters: None.
    // Returns:    The width of the render buffer in pixels.
    virtual std::size_t
    getWidth() const = 0;

    // Function:   getHeight
    // Purpose:    Get the height of the render buffer in pixels.
    // Parameters: None.
    // Returns:    The height of the render buffer in pixels.
    virtual std::size_t
    getHeight() const = 0;

    // Function:   getElementSize
    // Purpose:    Get the size of each pixel element in the data in bytes.
    // Parameters: None.
    // Returns:    The pixel element size in bytes.
    virtual std::size_t
    getElementSize() const = 0;

    // Function:   getData
    // Purpose:    Access the buffer data. Note that this returns an unsafe raw pointer for speed: the size of the
    //             buffer is getElementSize()*getWidth()*getHeight() bytes, but is not bounds-checked.
    // Parameters: None.
    // Returns:    The pointer to the beginning of the upper-left pixel of the buffer.
    virtual unsigned char *
    getData() = 0;
  };
}

#endif
