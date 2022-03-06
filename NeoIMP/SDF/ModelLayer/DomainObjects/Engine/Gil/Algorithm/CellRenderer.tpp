#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_CELLRENDERER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_CELLRENDERER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CellRenderer.tpp
 * PURPOSE: Implements the CellRenderer template.
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

#include "../../ERenderPixelFormat.hpp"
#include "../ImageTypes.hpp"

#include <boost/variant2/variant.hpp>

#include <cmath>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  namespace Impl {
    // Renderers for each layer type.
    // NB: THIS CURRENT RENDERER IS VERY ROUGH FIRST DRAFT -- NO SUPPORT FOR MULTILAYER, NO SUPPORT
    //     FOR COLOR PROFILES, NO ANTIALIASING (flag is simply IGNORED).
    template<class GilViewT>
    bool renderLayerAtop(GilViewT layerView,
                         Math::Rect<std::size_t> layerViewImgRect,
                         RenderCell *atop,
                         Math::Rect<float> layerSrcRect,
                         Math::Rect<std::size_t> atopDstRect
                        );

    template<>
    bool renderLayerAtop<boost::gil::rgb8_view_t>(boost::gil::rgb8_view_t layerView,
                                                  Math::Rect<std::size_t> layerViewImgRect,
                                                  RenderCell *atop,
                                                  Math::Rect<float> layerSrcRect,
                                                  Math::Rect<std::size_t> atopDstRect
                                                 )
    {
      // Note: atopDstRect is not in image space, but in destination buffer space.
      Math::Rect<std::size_t> layerSrcRectPx(floor(layerSrcRect.getX1()),
        floor(layerSrcRect.getY1()), floor(layerSrcRect.getX2()), floor(layerSrcRect.getY2()));
      Math::Rect<std::size_t> clippedSrcRect(layerViewImgRect.intersect(layerSrcRectPx));

      ERenderPixelFormat outPixelFormat = atop->getPixelFormat();
      std::size_t outPixelSize = atop->getPixelWidth();

      unsigned char *outPixelPos = atop->getOrigin();
      std::size_t outRowStride = atop->getRowStride();
      switch(outPixelFormat) {
        case RENDERFMT_RGB32:
        {
          // We are essentially building a linear mapping from layerSrcRect into atopDstRect or,
          // better, the inverse of this mapping - from atopDstRect into layerSrcRect. This allows
          // us to compute a pre-image for every pixel in the rendering, in the original document,
          // and thus we can easily obtain a color value from the corresponding pixel. Scaling,
          // rotation, and/or other desired transformations are thus handled easily.
          unsigned char *outYPtr = outPixelPos;
          for(std::size_t y(atopDstRect.getY1()); y <= atopDstRect.getY2(); ++y) {
            unsigned char *outXPtr = outYPtr;
            for(std::size_t x(atopDstRect.getX1()); x <= atopDstRect.getX2(); ++x) {
              // The linear (inverse) mapping.
              float imageY =
                ((0.0f + y - atopDstRect.getY1())/(atopDstRect.getY2() - atopDstRect.getY1())) *
                (layerSrcRect.getY2() - layerSrcRect.getY1()) + layerSrcRect.getY1();
              float imageX =
                ((0.0f + x - atopDstRect.getX1())/(atopDstRect.getX2() - atopDstRect.getX1())) *
                (layerSrcRect.getX2() - layerSrcRect.getX1()) + layerSrcRect.getX1();

              std::size_t viewY = floor(imageY - layerViewImgRect.getY1());
              std::size_t viewX = floor(imageX - layerViewImgRect.getX1());

              boost::gil::rgb8_pixel_t imagePixel(*layerView.xy_at(viewX, viewY));
              unsigned int pixelCode = 0xFF000000U
                ^ ((unsigned int)boost::gil::at_c<0>(imagePixel) << 16)
                ^ ((unsigned int)boost::gil::at_c<1>(imagePixel) <<  8)
                ^ ((unsigned int)boost::gil::at_c<2>(imagePixel)      );

              memcpy(outXPtr, &pixelCode, 4);

              outXPtr += outPixelSize;
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
  CellRenderer<GilImageT>::CellRenderer(RenderCell *outCell,
                                        Math::Rect<std::size_t> outRect,
                                        bool antialias
                                       )
    : m_outCell(outCell),
      m_outRect(outRect),
      m_antialias(antialias)
  {
  }

  template<class GilImageT>
  bool
  CellRenderer<GilImageT>::performOperation(Image<GilImageT> &imageImpl,
                                            const std::vector<OpRegion> &regions,
                                            IProgressListener *progress
                                           )
  {
    // Right now, for simplistic purposes, just render the bottom layer.
    if(progress != nullptr) {
      progress->reportProgress(0.0f);
    }

    std::size_t layerNum(regions.at(0).layerNum);
    Math::Rect<std::size_t> layerViewRect(0, 0, imageImpl.getLayerWidthPx(layerNum)-1,
      imageImpl.getLayerHeightPx(layerNum)-1);
    Math::Rect<float> layerSrcRect(regions.at(0).rect);

    typename GilImageT::view_t layerView(imageImpl.getLayerView(layerNum));

    bool rv(Impl::renderLayerAtop(layerView, layerViewRect, m_outCell, layerSrcRect, m_outRect));

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
                       RenderCell *outCell,
                       Math::Rect<float> renderSrcRect,
                       Math::Rect<std::size_t> outRect,
                       bool antialias
                      )
        : m_viewSrcRect(viewSrcRect),
          m_outCell(outCell),
          m_renderSrcRect(renderSrcRect),
          m_outRect(outRect),
          m_antialias(antialias)
      {
      }

      template<class GilViewT>
      bool operator()(GilViewT &view) {
        return renderLayerAtop(view, m_viewSrcRect, m_outCell, m_renderSrcRect, m_outRect);
      }
    private:
      Math::Rect<std::size_t> m_viewSrcRect;
      RenderCell *m_outCell;
      Math::Rect<float> m_renderSrcRect;
      Math::Rect<std::size_t> m_outRect;
      bool m_antialias;
    };
  }

  template<class ... GilImageTs>
  CellRenderer<AnyImage<GilImageTs...>>::CellRenderer(RenderCell *outCell,
                                                      Math::Rect<std::size_t> outRect,
                                                      bool antialias
                                                     )
    : m_outCell(outCell),
      m_outRect(outRect),
      m_antialias(antialias)
  {
  }

  template<class ... GilImageTs>
  bool
  CellRenderer<AnyImage<GilImageTs...>>::performOperation(AnyImage<GilImageTs...> &imageImpl,
                                                          const std::vector<OpRegion> &regions,
                                                          IProgressListener *progress
                                                         )
  {
    // Right now, for simplistic purposes, just render the bottom layer.
    if(progress != nullptr) {
      progress->reportProgress(0.0f);
    }

    std::size_t layerNum(regions.at(0).layerNum);
    Math::Rect<std::size_t> layerViewRect(0, 0, imageImpl.getLayerWidthPx(layerNum)-1,
      imageImpl.getLayerHeightPx(layerNum)-1);
    Math::Rect<float> layerSrcRect(regions.at(0).rect);

    typename boost::gil::any_image<GilImageTs...>::view_t layerView(
      imageImpl.getLayerView(layerNum)
    );

    bool rv(false);
    rv = boost::variant2::visit(Impl::AnyRenderVisitor(layerViewRect, m_outCell, layerSrcRect,
      m_outRect, m_antialias), layerView);

    if(progress != nullptr) {
      progress->reportProgress(100.0f);
    }

    return rv;
  }
}

#endif
