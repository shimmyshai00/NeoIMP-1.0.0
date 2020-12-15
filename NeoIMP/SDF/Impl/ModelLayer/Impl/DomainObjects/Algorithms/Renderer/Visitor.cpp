/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Visitor.cpp
 * PURPOSE: Implementation of the renderer visitor.
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

#include <Visitor.hpp>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Algorithms::Renderer {
  Visitor::Visitor() {}

  const unsigned char *Visitor::getRenderData() {
    return &(m_renderBuffer[0]);
  }

  void Visitor::visitGilRegion(boost::gil::gray8_view_t regionView) {
    m_renderBuffer.resize(regionView.size() * 4);

    std::vector<unsigned char>::iterator resultIt(m_renderBuffer.begin());
    for(auto it = regionView.begin(); it != regionView.end(); ++it, resultIt += 4) {
      (*(resultIt + 3)) = 0xFF; // nb: endianness matters here; need to make this more portable
      (*(resultIt + 2)) = boost::gil::semantic_at_c<0>(*it);
      (*(resultIt + 1)) = boost::gil::semantic_at_c<0>(*it);
      (*(resultIt    )) = boost::gil::semantic_at_c<0>(*it);
    }
  }

  void Visitor::visitGilRegion(boost::gil::gray16_view_t regionView) {
    m_renderBuffer.resize(regionView.size() * 4);

    std::vector<unsigned char>::iterator resultIt(m_renderBuffer.begin());
    for(auto it = regionView.begin(); it != regionView.end(); ++it, resultIt += 4) {
      (*(resultIt + 3)) = 0xFF;
      (*(resultIt + 2)) = boost::gil::semantic_at_c<0>(*it) >> 8;
      (*(resultIt + 1)) = boost::gil::semantic_at_c<0>(*it) >> 8;
      (*(resultIt    )) = boost::gil::semantic_at_c<0>(*it) >> 8;
    }
  }

  void Visitor::visitGilRegion(boost::gil::rgb8_view_t regionView) {
    m_renderBuffer.resize(regionView.size() * 4);

    std::vector<unsigned char>::iterator resultIt(m_renderBuffer.begin());
    for(auto it = regionView.begin(); it != regionView.end(); ++it, resultIt += 4) {
      (*(resultIt + 3)) = 0xFF;
      (*(resultIt + 2)) = boost::gil::semantic_at_c<0>(*it);
      (*(resultIt + 1)) = boost::gil::semantic_at_c<1>(*it);
      (*(resultIt    )) = boost::gil::semantic_at_c<2>(*it);
    }
  }

  void Visitor::visitGilRegion(boost::gil::rgb16_view_t regionView) {
    m_renderBuffer.resize(regionView.size() * 4);

    std::vector<unsigned char>::iterator resultIt(m_renderBuffer.begin());
    for(auto it = regionView.begin(); it != regionView.end(); ++it, resultIt += 4) {
      (*(resultIt + 3)) = 0xFF; // TBA
      (*(resultIt + 2)) = 0xFF; // TBA
      (*(resultIt + 1)) = 0xFF; // TBA
      (*(resultIt    )) = 0xFF; // TBA
    }
  }

  void Visitor::visitGilRegion(boost::gil::cmyk8_view_t regionView) {
    m_renderBuffer.resize(regionView.size() * 4);

    std::vector<unsigned char>::iterator resultIt(m_renderBuffer.begin());
    for(auto it = regionView.begin(); it != regionView.end(); ++it, resultIt += 4) {
      (*(resultIt + 3)) = 0xFF; // TBA
      (*(resultIt + 2)) = 0xFF; // TBA
      (*(resultIt + 1)) = 0xFF; // TBA
      (*(resultIt    )) = 0xFF; // TBA
    }
  }

  void Visitor::visitGilRegion(boost::gil::cmyk16_view_t regionView) {
    m_renderBuffer.resize(regionView.size() * 4);

    std::vector<unsigned char>::iterator resultIt(m_renderBuffer.begin());
    for(auto it = regionView.begin(); it != regionView.end(); ++it, resultIt += 4) {
      (*(resultIt + 3)) = 0xFF; // TBA
      (*(resultIt + 2)) = 0xFF; // TBA
      (*(resultIt + 1)) = 0xFF; // TBA
      (*(resultIt    )) = 0xFF; // TBA
    }
  }
}
