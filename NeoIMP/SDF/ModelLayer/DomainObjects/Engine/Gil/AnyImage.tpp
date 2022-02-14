#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYIMAGE_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYIMAGE_TPP

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

#include "ImageTraits.hpp"

#include "../../../AbstractData/Entity/Gil/AnyLayer.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class ... GilImageTs>
  template<class T>
  AnyImage<GilImageTs...>::AnyImage(const Image<T> &img)
    : m_name(img.m_name),
      m_fileSpec(img.m_fileSpec),
      m_widthPx(img.m_widthPx),
      m_heightPx(img.m_heightPx),
      m_colorModel(ImageTraits<T>::colorModel),
      m_numChannels(ImageTraits<T>::numChannels),
      m_bitDepth(ImageTraits<T>::bitDepth)
  {
    for(auto &layer : img.m_layers) {
      m_layers.push_back(AnyLayer<GilImageTs...>(layer));
    }
  }

  template<class ... GilImageTs>
  template<class T>
  AnyImage<GilImageTs...>::AnyImage(Image<T> &&img)
    : m_name(std::move(img.m_name)),
      m_fileSpec(std::move(img.m_fileSpec)),
      m_widthPx(std::exchange(img.m_widthPx, 0)),
      m_heightPx(std::exchange(img.m_heightPx, 0)),
      m_colorModel(ImageTraits<T>::colorModel),
      m_numChannels(ImageTraits<T>::numChannels),
      m_bitDepth(ImageTraits<T>::bitDepth)
  {
    for(auto &layer : img.m_layers) {
      m_layers.push_back(AnyLayer<GilImageTs...>(std::move(layer)));
    }
  }

  template<class ... GilImageTs>
  std::shared_ptr<AbstractData::Entity::Gil::AnyImage<GilImageTs...>>
  AnyImage<GilImageTs...>::getEntity() const {
    using namespace AbstractData;

    std::shared_ptr<Entity::Gil::AnyImage<GilImageTs...>> rv(
      new Entity::Gil::AnyImage<GilImageTs...>);
    rv->widthPx = m_widthPx;
    rv->heightPx = m_heightPx;
    rv->resolutionPpi = m_resolutionPpi;

    for(std::size_t i(0); i < m_layers.size(); ++i) {
      Entity::Gil::AnyLayer<GilImageTs...> layer;
      layer.widthPx = m_layers[i].getWidthPx();
      layer.heightPx = m_layers[i].getHeightPx();
      layer.imageView = m_layers[i].getView();

      rv->layers.push_back(layer);
    }

    return rv;
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
  std::size_t
  AnyImage<GilImageTs...>::getWidthPx() const {
    return m_widthPx;
  }

  template<class ... GilImageTs>
  std::size_t
  AnyImage<GilImageTs...>::getHeightPx() const {
    return m_heightPx;
  }

  template<class ... GilImageTs>
  float
  AnyImage<GilImageTs...>::getResolutionPpi() const {
    return m_resolutionPpi;
  }

  template<class ... GilImageTs>
  UILayer::AbstractModel::Defs::EColorModel
  AnyImage<GilImageTs...>::getColorModel() const {
    return m_colorModel;
  }

  template<class ... GilImageTs>
  std::size_t
  AnyImage<GilImageTs...>::getNumChannels() const {
    return m_numChannels;
  }

  template<class ... GilImageTs>
  UILayer::AbstractModel::Defs::EBitDepth
  AnyImage<GilImageTs...>::getChannelBitDepth() const {
    return m_bitDepth;
  }

  template<class ... GilImageTs>
  std::size_t
  AnyImage<GilImageTs...>::getNumLayers() const {
    return m_layers.size();
  }

  template<class ... GilImageTs>
  std::size_t
  AnyImage<GilImageTs...>::getLayerWidthPx(std::size_t which) const {
    if(which >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[which].getWidthPx();
    }
  }

  template<class ... GilImageTs>
  std::size_t
  AnyImage<GilImageTs...>::getLayerHeightPx(std::size_t which) const {
    if(which >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[which].getHeightPx();
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum) {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getLayerView();
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum) const {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getLayerView();
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum,
                                        Math::Rect<std::size_t> rect
                                       )
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getLayerView(rect);
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum,
                                        Math::Rect<std::size_t> rect
                                       ) const
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getLayerView(rect);
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum,
                                        std::size_t x1,
                                        std::size_t y1,
                                        std::size_t x2,
                                        std::size_t y2
                                       )
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getLayerView(x1, y1, x2, y2);
    }
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyImage<GilImageTs...>::getLayerView(std::size_t layerNum,
                                        std::size_t x1,
                                        std::size_t y1,
                                        std::size_t x2,
                                        std::size_t y2
                                       ) const
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getLayerView(x1, y1, x2, y2);
    }
  }
}

#endif
