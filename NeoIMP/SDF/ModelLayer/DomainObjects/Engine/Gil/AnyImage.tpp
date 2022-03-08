#ifndef SDF_MODELLAYER_DOMAINOBJECTS_GIL_ANYIMAGE_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_GIL_ANYIMAGE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AnyImage.tpp
 * PURPOSE: Implements the AnyImage template.
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

#include "TraitExtender.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class ... GilImageTs>
  template<class GilBkgImageT, class GilImageT>
  AnyImage<GilImageTs...>::AnyImage(const Image<GilBkgImageT, GilImageT> &image)
    : m_name(image.m_name),
      m_fileSpec(image.m_fileSpec),
      m_widthPx(image.m_widthPx),
      m_heightPx(image.m_heightPx),
      m_resolutionPpi(image.m_resolutionPpi),
      m_bkgColorModel(&ExtTraits<GilBkgImageT>::color_model),
      m_colorModel(&ExtTraits<GilImageT>::color_model),
      m_backgroundLayer(AnyLayer<GilImageTs...>(image.m_backgroundLayer))
  {
    for(const auto &layer : image.m_layers) {
      m_layers.push_back(AnyLayer<GilImageTs...>(layer));
    }
  }

  template<class ... GilImageTs>
  template<class GilBkgImageT, class GilImageT>
  AnyImage<GilImageTs...>::AnyImage(Image<GilBkgImageT, GilImageT> &&image)
    : m_name(std::move(image.m_name)),
      m_fileSpec(std::move(image.m_fileSpec)),
      m_widthPx(std::move(image.m_widthPx)),
      m_heightPx(std::move(image.m_heightPx)),
      m_resolutionPpi(std::move(image.m_resolutionPpi)),
      m_bkgColorModel(&ExtTraits<GilBkgImageT>::color_model),
      m_colorModel(&ExtTraits<GilImageT>::color_model),
      m_backgroundLayer(AnyLayer<GilImageTs...>(std::move(image.m_backgroundLayer)))
  {
    for(const auto &layer : image.m_layers) {
      m_layers.push_back(AnyLayer<GilImageTs...>(std::move(layer)));
    }
  }

  template<class ... GilImageTs>
  std::string
  AnyImage<GilImageTs...>::getName() const {
    return m_name;
  }

  template<class ... GilImageTs>
  std::string
  AnyImage<GilImageTs...>::getFileSpec() const {
    return m_fileSpec;
  }

  template<class ... GilImageTs>
  ImageMeasure
  AnyImage<GilImageTs...>::getWidthPx() const {
    return m_widthPx;
  }

  template<class ... GilImageTs>
  ImageMeasure
  AnyImage<GilImageTs...>::getHeightPx() const {
    return m_heightPx;
  }

  template<class ... GilImageTs>
  float
  AnyImage<GilImageTs...>::getResolutionPpi() const {
    return m_resolutionPpi;
  }

  template<class ... GilImageTs>
  IColorModel &
  AnyImage<GilImageTs...>::getBkgColorModel() const {
    // TBA
    static ColorModels::RGB24_888 cm;
    return cm;
  }

  template<class ... GilImageTs>
  IColorModel &
  AnyImage<GilImageTs...>::getColorModel() const {
    // TBA
    static ColorModels::RGB24_888 cm;
    return cm;
  }

  template<class ... GilImageTs>
  std::size_t
  AnyImage<GilImageTs...>::getNumLayers() const {
    return 1 + m_layers.size();
  }

  template<class ... GilImageTs>
  ImageMeasure
  AnyImage<GilImageTs...>::getLayerWidthPx(std::size_t which) const {
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

  template<class ... GilImageTs>
  ImageMeasure
  AnyImage<GilImageTs...>::getLayerHeightPx(std::size_t which) const {
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

  template<class ... GilImageTs>
  ImageRect
  AnyImage<GilImageTs...>::getLayerRect(std::size_t which) const {
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

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyImage<GilImageTs...>::getBkgLayerView() {
    return m_backgroundLayer.getView();
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyImage<GilImageTs...>::getBkgLayerView() const {
    return m_backgroundLayer.getView();
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum) {
    if((layerNum == 0) || (layerNum > m_layers.size())) {
      // Oops
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum-1].getView();
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum) const {
    if((layerNum == 0) || (layerNum > m_layers.size())) {
      // Oops
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum-1].getView();
    }
  }
}

#endif
