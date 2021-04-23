/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Visitor.cpp
 * PURPOSE: Implements the Visitor class.
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

#include <Services/AbstractDomain/IRenderBuffer.hpp>

namespace SDF::ModelLayer::DomainObjects::Algorithms::Renderer {
  // The rendering algorithms for the Boost::GIL implementation.
  class GilVisitor {
  public:
    GilVisitor(Services::AbstractDomain::IRenderBuffer *outputBuffer,
               Math::Rect<std::size_t> outputRect)
      : m_outputRect(outputRect),
        m_outputBuffer(outputBuffer)
    {
    }

    void
    operator()(boost::gil::rgb8_view_t regionView) {
      // Intersect the output and buffer rectangles to get a safe region.
      std::size_t bufferWidth(m_outputBuffer->getWidth());
      std::size_t bufferHeight(m_outputBuffer->getHeight());
      std::size_t elSize(m_outputBuffer->getElementSize());

      Math::Rect<std::size_t> bufRect(0, 0, bufferWidth-1, bufferHeight-1);
      Math::Rect<std::size_t> safeRect(bufRect.intersect(m_outputRect));

      // Move the result pointer to the location of the output rectangle.
      unsigned char *resultRowPtr(m_outputBuffer->getData());
      resultRowPtr += elSize * (safeRect.getY1() * bufferWidth + safeRect.getX1());
      auto renderRowItr = regionView.begin();

      for(std::size_t y(safeRect.getY1()); y <= safeRect.getY2(); ++y) {
        unsigned char *resultPtr(resultRowPtr);
        auto renderItr(renderRowItr);

        for(std::size_t x(safeRect.getX1()); x <= safeRect.getX2(); ++x) {
          (*(resultPtr + 3)) = 0xFF;
          (*(resultPtr + 2)) = boost::gil::semantic_at_c<0>(*renderItr);
          (*(resultPtr + 1)) = boost::gil::semantic_at_c<1>(*renderItr);
          (*(resultPtr    )) = boost::gil::semantic_at_c<2>(*renderItr);

          ++resultPtr;
          ++renderItr;
        }

        resultRowPtr += elSize * bufferWidth;
        renderRowItr += regionView.width();
      }
    }
  private:
    Math::Rect<std::size_t> m_outputRect;
    Services::AbstractDomain::IRenderBuffer *m_outputBuffer;
  };
}

namespace SDF::ModelLayer::DomainObjects::Algorithms::Renderer {
  Visitor::Visitor(int uid,
                   Services::AbstractDomain::IRenderBuffer *buffer
                  )
    : m_uid(uid),
      m_buffer(buffer)
  {
  }

  int
  Visitor::getId() const {
    return m_uid;
  }

  void
  Visitor::visitGilRegion(Math::Rect<std::size_t> rect,
                          Services::AbstractDomain::Defs::GilRegionType &gilRegion
                         )
  {
    boost::variant2::visit(GilVisitor(m_buffer, rect), gilRegion);
  }
}
