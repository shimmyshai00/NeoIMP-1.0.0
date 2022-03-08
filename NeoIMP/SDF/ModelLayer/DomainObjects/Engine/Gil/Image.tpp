#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGE_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Image.tpp
 * PURPOSE: Implements the Image template.
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

#include "../../../Exceptions.hpp"
#include "TraitExtender.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilBkgImageT, class GilImageT>
  Image<GilBkgImageT, GilImageT>::Image(std::string name,
                                        std::string fileSpec,
                                        ImageMeasure widthPx,
                                        ImageMeasure heightPx,
                                        float resolutionPpi,
                                        typename GilBkgImageT::value_type baseColor
                                       )
    : m_name(name),
      m_fileSpec(fileSpec),
      m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_resolutionPpi(resolutionPpi),
      m_backgroundLayer(widthPx, heightPx, baseColor)
  {
  }

  template<class GilBkgImageT, class GilImageT>
  std::string
  Image<GilBkgImageT, GilImageT>::getName() const {
    return m_name;
  }

  template<class GilBkgImageT, class GilImageT>
  std::string
  Image<GilBkgImageT, GilImageT>::getFileSpec() const {
    return m_fileSpec;
  }

  template<class GilBkgImageT, class GilImageT>
  ImageMeasure
  Image<GilBkgImageT, GilImageT>::getWidthPx() const {
    return m_widthPx;
  }

  template<class GilBkgImageT, class GilImageT>
  ImageMeasure
  Image<GilBkgImageT, GilImageT>::getHeightPx() const {
    return m_heightPx;
  }

  template<class GilBkgImageT, class GilImageT>
  float
  Image<GilBkgImageT, GilImageT>::getResolutionPpi() const {
    return m_resolutionPpi;
  }

  template<class GilBkgImageT, class GilImageT>
  IColorModelImpl<typename GilBkgImageT::value_type> &
  Image<GilBkgImageT, GilImageT>::getBkgColorModel() const {
    return ExtTraits<GilBkgImageT>::color_model;
  }

  template<class GilBkgImageT, class GilImageT>
  IColorModelImpl<typename GilImageT::value_type> &
  Image<GilBkgImageT, GilImageT>::getColorModel() const {
    return ExtTraits<GilImageT>::color_model;
  }

  template<class GilBkgImageT, class GilImageT>
  std::size_t
  Image<GilBkgImageT, GilImageT>::getNumLayers() const {
    return 1 + m_layers.size();
  }

  template<class GilBkgImageT, class GilImageT>
  ImageMeasure
  Image<GilBkgImageT, GilImageT>::getLayerWidthPx(std::size_t which) const {
    if(which == 0) {
      return m_backgroundLayer.getWidthPx();
    } else {
      if(which > m_layers.size()) {
        // Oops
        throw OutOfRangeException();
      } else {
        return m_layers[which-1].getWidthPx();
      }
    }
  }

  template<class GilBkgImageT, class GilImageT>
  ImageMeasure
  Image<GilBkgImageT, GilImageT>::getLayerHeightPx(std::size_t which) const {
    if(which == 0) {
      return m_backgroundLayer.getHeightPx();
    } else {
      if(which > m_layers.size()) {
        // Oops
        throw OutOfRangeException();
      } else {
        return m_layers[which-1].getHeightPx();
      }
    }
  }

  template<class GilBkgImageT, class GilImageT>
  ImageRect
  Image<GilBkgImageT, GilImageT>::getLayerRect(std::size_t which) const {
    if(which == 0) {
      return m_backgroundLayer.getRect();
    } else {
      if(which > m_layers.size()) {
        // Oops
        throw OutOfRangeException();
      } else {
        return m_layers[which-1].getRect();
      }
    }
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilBkgImageT::view_t
  Image<GilBkgImageT, GilImageT>::getBkgLayerView() {
    return m_backgroundLayer.getView();
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilBkgImageT::const_view_t
  Image<GilBkgImageT, GilImageT>::getBkgLayerView() const {
    return m_backgroundLayer.getView();
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilBkgImageT::view_t
  Image<GilBkgImageT, GilImageT>::getBkgLayerView(ImageRect rect) {
    return m_backgroundLayer.getView(rect);
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilBkgImageT::const_view_t
  Image<GilBkgImageT, GilImageT>::getBkgLayerView(ImageRect rect) const {
    return m_backgroundLayer.getView(rect);
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilImageT::view_t
  Image<GilBkgImageT, GilImageT>::getLayerView(std::size_t layerNum) {
    if((layerNum == 0) || (layerNum > m_layers.size())) {
      // Oops
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum-1].getView();
    }
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilImageT::const_view_t
  Image<GilBkgImageT, GilImageT>::getLayerView(std::size_t layerNum) const {
    if((layerNum == 0) || (layerNum > m_layers.size())) {
      // Oops
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum-1].getView();
    }
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilImageT::view_t
  Image<GilBkgImageT, GilImageT>::getLayerView(std::size_t layerNum,
                                               ImageRect rect
                                              )
  {
    if((layerNum == 0) || (layerNum > m_layers.size())) {
      // Oops
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum-1].getView(rect);
    }
  }

  template<class GilBkgImageT, class GilImageT>
  typename GilImageT::const_view_t
  Image<GilBkgImageT, GilImageT>::getLayerView(std::size_t layerNum,
                                               ImageRect rect
                                              ) const
  {
    if((layerNum == 0) || (layerNum > m_layers.size())) {
      // Oops
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum-1].getView(rect);
    }
  }
}

#endif
