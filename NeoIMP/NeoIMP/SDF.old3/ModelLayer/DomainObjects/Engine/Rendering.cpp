/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Rendering.cpp
 * PURPOSE: Implements the Rendering class.
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

#include "Rendering.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  Rendering::Rendering(std::size_t width,
                       std::size_t height,
                       ERenderPixelFormat pixFmt
                      )
    : m_uid(Uid::next()),
      m_width(width),
      m_height(height),
      m_pixFmt(pixFmt),
      m_renderBuffer(nullptr)
  {
    switch(m_pixFmt) {
      case RENDERFMT_RGB32:
        m_renderBuffer = new unsigned char[4*m_width*m_height];

        // Initialize the array.
        for(std::size_t i(0); i < m_width*m_height; ++i) {
          m_renderBuffer[4*i  ] = 0xFF;
          m_renderBuffer[4*i+1] = 0x00;
          m_renderBuffer[4*i+2] = 0x00;
          m_renderBuffer[4*i+3] = 0x00;
        }

        break;
      default:
        break;
    }
  }

  Rendering::~Rendering() {
    delete m_renderBuffer;
  }

  Uid
  Rendering::getUid() const {
    return m_uid;
  }

  Rendering &
  Rendering::getObject() {
    return *this;
  }

  std::size_t
  Rendering::getWidth() const {
    return m_width;
  }

  std::size_t
  Rendering::getWidth() const {
    return m_height;
  }

  ERenderPixelFormat
  Rendering::getPixelFormat() const {
    return m_pixFmt;
  }

  unsigned char *
  Rendering::getOrigin() {
    return m_renderBuffer;
  }

  std::size_t
  Rendering::getRowStride() {
    return getPixelWidth()*m_width*m_height;
  }

  std::size_t
  Rendering::getPixelWidth() {
    switch(m_pixFmt) {
      case RENDERFMT_RGB32: return 4;
      default: return 1;
    }
  }
}
