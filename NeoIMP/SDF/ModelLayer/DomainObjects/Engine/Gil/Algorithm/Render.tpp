#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Render.tpp
 * PURPOSE: Implements the Render template.
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

#include "../../Rendering.hpp"
#include "../ImageTypes.hpp"

#include <boost/variant2/variant.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  namespace Impl {
    // Renderers for each layer type.
    // NB: THIS CURRENT RENDERER IS VERY ROUGH FIRST DRAFT -- NO SUPPORT FOR MULTILAYER, NO SUPPORT
    //     FOR COLOR PROFILES.
    template<class GilViewT>
    bool renderLayerAtop(GilViewT view,
                         Math::Rect<std::size_t> viewSrcRect,
                         Rendering *atop,
                         Math::Rect<std::size_t> thisRect
                        );

    template<>
    bool renderLayerAtop<boost::gil::rgb8_view_t>(boost::gil::rgb8_view_t view,
                                                  Math::Rect<std::size_t> viewSrcRect,
                                                  Rendering *atop,
                                                  Math::Rect<std::size_t> thisRect
                                                 )
    {
      // Remember: viewSrcRect and thisRect are in image space
      Math::Rect<std::size_t> imgSpaceSrcRect(viewSrcRect.intersect(thisRect));

      std::size_t outPixelSize = atop->getPixelWidth();
      std::size_t outRowStride = atop->getRowStride();
      unsigned char *outPixelPos = atop->getOrigin() +
        ((outRowStride*thisRect.getUpperLeft().getY()) +
          (outPixelSize*thisRect.getUpperLeft().getX()));
      switch(atop->getPixelFormat()) {
        case RENDERFMT_RGB32:
        {
          unsigned char *outYPtr = outPixelPos;
          for(std::size_t y(imgSpaceSrcRect.getUpperLeft().getY());
            y <= imgSpaceSrcRect.getLowerRight().getY(); ++y)
          {
            unsigned char *outXPtr = outYPtr;
            boost::gil::rgb8_view_t::x_iterator viewXPos(view.row_begin(y));
            for(std::size_t x(imgSpaceSrcRect.getUpperLeft().getX());
              x <= imgSpaceSrcRect.getLowerRight().getX(); ++x)
            {
              boost::gil::rgb8_pixel_t imagePixel(*viewXPos);
              unsigned int pixelCode = 0xFF000000U
                ^ ((unsigned int)boost::gil::at_c<0>(imagePixel) << 16)
                ^ ((unsigned int)boost::gil::at_c<1>(imagePixel) <<  8)
                ^ ((unsigned int)boost::gil::at_c<2>(imagePixel)      );

              // ensures correct endian format for this machine
              *((unsigned int *)outXPtr) = pixelCode;

              outXPtr += outPixelSize;
              viewXPos++;
            }

            outYPtr += outRowStride;
          }
          break;
        }
        default:
          // TBA
          return false;
      }

      return true;
    }
  }

  template<class GilImageT>
  Render<GilImageT>::Render(Rendering *outBuffer)
    : m_outBuffer(outBuffer)
  {
  }

  template<class GilImageT>
  bool
  Render<GilImageT>::performOperation(Image<GilImageT> &imageImpl,
                                      const std::vector<std::size_t> &layerNums,
                                      const std::vector<Math::Rect<std::size_t>> &layerRects,
                                      IProgressListener *progress
                                     )
  {
    // Right now, for simplistic purposes, just render the bottom layer.
    if(progress != nullptr) {
      progress->reportProgress(0.0f);
    }

    std::size_t renderLayerNum(layerNums.at(0));
    Math::Rect<std::size_t> renderRect(layerRects.at(0));
    typename GilImageT::view_t layerView(imageImpl.getLayerView(renderLayerNum, renderRect));

    bool rv(Impl::renderLayerAtop(layerView, renderRect, m_outBuffer, renderRect));

    if(progress != nullptr) {
      progress->reportProgress(100.0f);
    }

    return rv;
  }
}

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  namespace Impl {
    class AnyRenderVisitor {
    public:
      AnyRenderVisitor(Math::Rect<std::size_t> viewSrcRect,
                       Rendering *outBuffer,
                       Math::Rect<std::size_t> renderRect
                      )
        : m_viewSrcRect(viewSrcRect),
          m_outBuffer(outBuffer),
          m_renderRect(renderRect)
      {
      }

      template<class GilViewT>
      bool operator()(GilViewT &view) {
        return renderLayerAtop(view, m_viewSrcRect, m_outBuffer, m_renderRect);
      }
    private:
      Math::Rect<std::size_t> m_viewSrcRect;
      Rendering *m_outBuffer;
      Math::Rect<std::size_t> m_renderRect;
    };
  }

  template<class ... GilImageTs>
  Render<AnyImage<GilImageTs...>>::Render(Rendering *outBuffer)
    : m_outBuffer(outBuffer)
  {
  }

  template<class ... GilImageTs>
  bool
  Render<AnyImage<GilImageTs...>>::performOperation(AnyImage<GilImageTs...> &imageImpl,
                                                    const std::vector<std::size_t> &layerNums,
                                                    const std::vector<Math::Rect<std::size_t>> &
                                                      layerRects,
                                                    IProgressListener *progress
                                                   )
  {
    // Right now, for simplistic purposes, just render the bottom layer.
    if(progress != nullptr) {
      progress->reportProgress(0.0f);
    }

    std::size_t renderLayerNum(layerNums.at(0));
    Math::Rect<std::size_t> renderWholeLayerRect(imageImpl.getLayerRect(renderLayerNum));
    Math::Rect<std::size_t> renderRect(layerRects.at(0));
    typename boost::gil::any_image<GilImageTs...>::view_t layerView(
      imageImpl.getLayerView(renderLayerNum));

    bool rv(false);
    rv = boost::variant2::visit(Impl::AnyRenderVisitor(renderWholeLayerRect, m_outBuffer,
      renderRect), layerView);

    if(progress != nullptr) {
      progress->reportProgress(100.0f);
    }

    return rv;
  }
}

#endif
