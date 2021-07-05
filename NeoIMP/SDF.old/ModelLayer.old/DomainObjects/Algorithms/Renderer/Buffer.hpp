#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_RENDERER_BUFFER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_RENDERER_BUFFER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Buffer.hpp
 * PURPOSE: Defines the Buffer class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IRenderBuffer.hpp>

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Algorithms::Renderer {
  // Class:      Buffer
  // Purpose:    Stores the data for a rendered image. Right now this buffer only is meant to hold RGB32 data.
  // Parameters: None.
  class Buffer : public Services::AbstractDomain::IRenderBuffer {
  public:
    // Function:   Buffer
    // Purpose:    Construct a new buffer of the given width and height in pixels.
    // Parameters: id - The entity ID for this domain object.
    //             width - The desired width of the buffer in pixels.
    //             height - The desired height of the buffer in pixels.
    Buffer(int id,
           std::size_t width,
           std::size_t height
          );

    ~Buffer();

    int
    getId() const;

    std::size_t
    getWidth() const;

    std::size_t
    getHeight() const;

    std::size_t
    getElementSize() const;

    unsigned char *
    getData();
  private:
    int m_id;

    std::size_t m_width;
    std::size_t m_height;

    unsigned char *m_data;
  };
}

#endif
