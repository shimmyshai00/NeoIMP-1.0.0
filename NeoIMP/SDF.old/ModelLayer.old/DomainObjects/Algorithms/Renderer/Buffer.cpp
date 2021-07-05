/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Buffer.cpp
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

#include <Buffer.hpp>

namespace SDF::ModelLayer::DomainObjects::Algorithms::Renderer {
  Buffer::Buffer(int id,
                 std::size_t width,
                 std::size_t height
                )
    : m_id(id),
      m_width(width),
      m_height(height),
      m_data(nullptr)
  {
    m_data = new unsigned char[4*width*height];
  }

  Buffer::~Buffer() {
    delete m_data;
  }

  int
  Buffer::getId() const {
    return m_id;
  }

  std::size_t
  Buffer::getWidth() const {
    return m_width;
  }

  std::size_t
  Buffer::getHeight() const {
    return m_height;
  }

  std::size_t
  Buffer::getElementSize() const {
    return 4;
  }

  unsigned char *
  Buffer::getData() {
    return m_data;
  }
}
