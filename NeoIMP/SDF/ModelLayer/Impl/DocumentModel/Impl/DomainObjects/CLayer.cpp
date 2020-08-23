/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CLayer.cpp
 * PURPOSE: Implementation of the CLayer class.
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

#include <CLayer.hpp>
#include <cassert>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects {
      CLayer::CLayer(int layerWidthPx, int layerHeightPx,
        SDF::ModelLayer::Iface::Param::EColorModel colorModel, SDF::ModelLayer::Iface::Param::EBitDepth bitDepth)
      : m_layerWidthPx(layerWidthPx),
        m_layerHeightPx(layerHeightPx),
        m_colorModel(colorModel),
        m_bitDepth(bitDepth)
        {
          using namespace SDF::Common;
          using namespace SDF::ModelLayer::Iface::Param;

          assert((0 < layerWidthPx));
          assert((0 < layerHeightPx));

          switch(bitDepth) {
            case BIT_DEPTH_8:
              m_alpha8Grid = std::make_unique<TGrid<Color::Alpha8>>(layerWidthPx, layerHeightPx);
              break;
            case BIT_DEPTH_10:
              m_alpha10Grid = std::make_unique<TGrid<Color::Alpha10>>(layerWidthPx, layerHeightPx);
              break;
            case BIT_DEPTH_12:
              m_alpha12Grid = std::make_unique<TGrid<Color::Alpha12>>(layerWidthPx, layerHeightPx);
              break;
            case BIT_DEPTH_16:
              m_alpha16Grid = std::make_unique<TGrid<Color::Alpha16>>(layerWidthPx, layerHeightPx);
              break;
          }

          if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_8)) {
            m_rgb24Grid = std::make_unique<TGrid<Color::RGB24>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_10)) {
            m_rgb30Grid = std::make_unique<TGrid<Color::RGB30>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_12)) {
            m_rgb36Grid = std::make_unique<TGrid<Color::RGB36>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_16)) {
            m_rgb48Grid = std::make_unique<TGrid<Color::RGB48>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_8)) {
            m_cmyk32Grid = std::make_unique<TGrid<Color::CMYK32>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_10)) {
            m_cmyk40Grid = std::make_unique<TGrid<Color::CMYK40>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_12)) {
            m_cmyk48Grid = std::make_unique<TGrid<Color::CMYK48>>(layerWidthPx, layerHeightPx);
          } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_16)) {
            m_cmyk64Grid = std::make_unique<TGrid<Color::CMYK64>>(layerWidthPx, layerHeightPx);
          }
        }

      int CLayer::getLayerWidthPx() const {
        return m_layerWidthPx;
      }

      int CLayer::getLayerHeightPx() const {
        return m_layerHeightPx;
      }

      void CLayer::operateOnAlpha(int x, int y, IAlphaOperation &op) {
        using namespace SDF::ModelLayer::Iface::Param;

        assert((0 <= x) && (x < m_layerWidthPx));
        assert((0 <= y) && (y < m_layerHeightPx));

        switch(m_bitDepth) {
          case BIT_DEPTH_8:
            (*m_alpha8Grid)(x, y) = op.processAlpha((*m_alpha8Grid)(x, y).get(), 255);
            break;
          case BIT_DEPTH_10:
            (*m_alpha10Grid)(x, y) = op.processAlpha((*m_alpha10Grid)(x, y).get(), 1023);
            break;
          case BIT_DEPTH_12:
            (*m_alpha12Grid)(x, y) = op.processAlpha((*m_alpha12Grid)(x, y).get(), 4095);
            break;
          case BIT_DEPTH_16:
            (*m_alpha16Grid)(x, y) = op.processAlpha((*m_alpha16Grid)(x, y).get(), 65535);
            break;
        }
      }

      void CLayer::operateOnColor(int x, int y, IColorOperation &op) {
        using namespace SDF::ModelLayer::Iface::Param;

        assert((0 <= x) && (x < m_layerWidthPx));
        assert((0 <= y) && (y < m_layerHeightPx));

        if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_8)) {
          int inR((*m_rgb24Grid)(x, y).getR());
          int inG((*m_rgb24Grid)(x, y).getG());
          int inB((*m_rgb24Grid)(x, y).getB());

          (*m_rgb24Grid)(x, y).setR(op.processR(inR, inG, inB, 255));
          (*m_rgb24Grid)(x, y).setG(op.processG(inR, inG, inB, 255));
          (*m_rgb24Grid)(x, y).setB(op.processB(inR, inG, inB, 255));
        } else if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_10)) {
          int inR((*m_rgb30Grid)(x, y).getR());
          int inG((*m_rgb30Grid)(x, y).getG());
          int inB((*m_rgb30Grid)(x, y).getB());

          (*m_rgb30Grid)(x, y).setR(op.processR(inR, inG, inB, 1023));
          (*m_rgb30Grid)(x, y).setG(op.processG(inR, inG, inB, 1023));
          (*m_rgb30Grid)(x, y).setB(op.processB(inR, inG, inB, 1023));
        } else if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_12)) {
          int inR((*m_rgb36Grid)(x, y).getR());
          int inG((*m_rgb36Grid)(x, y).getG());
          int inB((*m_rgb36Grid)(x, y).getB());

          (*m_rgb36Grid)(x, y).setR(op.processR(inR, inG, inB, 4095));
          (*m_rgb36Grid)(x, y).setG(op.processG(inR, inG, inB, 4095));
          (*m_rgb36Grid)(x, y).setB(op.processB(inR, inG, inB, 4095));
        } else if((m_colorModel == COLOR_MODEL_RGB) && (m_bitDepth == BIT_DEPTH_16)) {
          int inR((*m_rgb48Grid)(x, y).getR());
          int inG((*m_rgb48Grid)(x, y).getG());
          int inB((*m_rgb48Grid)(x, y).getB());

          (*m_rgb48Grid)(x, y).setR(op.processR(inR, inG, inB, 65535));
          (*m_rgb48Grid)(x, y).setG(op.processG(inR, inG, inB, 65535));
          (*m_rgb48Grid)(x, y).setB(op.processB(inR, inG, inB, 65535));
        } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_8)) {
          int inC((*m_cmyk32Grid)(x, y).getC());
          int inM((*m_cmyk32Grid)(x, y).getM());
          int inY((*m_cmyk32Grid)(x, y).getY());
          int inK((*m_cmyk32Grid)(x, y).getK());

          (*m_cmyk32Grid)(x, y).setC(op.processC(inC, inM, inY, inK, 255));
          (*m_cmyk32Grid)(x, y).setM(op.processM(inC, inM, inY, inK, 255));
          (*m_cmyk32Grid)(x, y).setY(op.processY(inC, inM, inY, inK, 255));
          (*m_cmyk32Grid)(x, y).setK(op.processK(inC, inM, inY, inK, 255));
        } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_10)) {
          int inC((*m_cmyk40Grid)(x, y).getC());
          int inM((*m_cmyk40Grid)(x, y).getM());
          int inY((*m_cmyk40Grid)(x, y).getY());
          int inK((*m_cmyk40Grid)(x, y).getK());

          (*m_cmyk40Grid)(x, y).setC(op.processC(inC, inM, inY, inK, 1023));
          (*m_cmyk40Grid)(x, y).setM(op.processM(inC, inM, inY, inK, 1023));
          (*m_cmyk40Grid)(x, y).setY(op.processY(inC, inM, inY, inK, 1023));
          (*m_cmyk40Grid)(x, y).setK(op.processK(inC, inM, inY, inK, 1023));
        } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_12)) {
          int inC((*m_cmyk48Grid)(x, y).getC());
          int inM((*m_cmyk48Grid)(x, y).getM());
          int inY((*m_cmyk48Grid)(x, y).getY());
          int inK((*m_cmyk48Grid)(x, y).getK());

          (*m_cmyk48Grid)(x, y).setC(op.processC(inC, inM, inY, inK, 4095));
          (*m_cmyk48Grid)(x, y).setM(op.processM(inC, inM, inY, inK, 4095));
          (*m_cmyk48Grid)(x, y).setY(op.processY(inC, inM, inY, inK, 4095));
          (*m_cmyk48Grid)(x, y).setK(op.processK(inC, inM, inY, inK, 4095));
        } else if((m_colorModel == COLOR_MODEL_CMYK) && (m_bitDepth == BIT_DEPTH_16)) {
          int inC((*m_cmyk64Grid)(x, y).getC());
          int inM((*m_cmyk64Grid)(x, y).getM());
          int inY((*m_cmyk64Grid)(x, y).getY());
          int inK((*m_cmyk64Grid)(x, y).getK());

          (*m_cmyk64Grid)(x, y).setC(op.processC(inC, inM, inY, inK, 65535));
          (*m_cmyk64Grid)(x, y).setM(op.processM(inC, inM, inY, inK, 65535));
          (*m_cmyk64Grid)(x, y).setY(op.processY(inC, inM, inY, inK, 65535));
          (*m_cmyk64Grid)(x, y).setK(op.processK(inC, inM, inY, inK, 65535));
        }
      }
    }
  }
}
