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

#include "ImageTraits.hpp"

#include "../../../AbstractData/Entity/Gil/Layer.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  Image<GilImageT>::Image(std::string name,
                          std::string fileSpec,
                          std::size_t widthPx,
                          std::size_t heightPx,
                          float resolutionPpi
                         )
    : m_name(name),
      m_fileSpec(fileSpec),
      m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_resolutionPpi(resolutionPpi)
  {
    m_layers.push_back(Layer<GilImageT>(widthPx, heightPx));
  }

  template<class GilImageT>
  std::shared_ptr<AbstractData::Entity::Gil::Image<GilImageT>>
  Image<GilImageT>::getEntity() const {
    using namespace AbstractData;

    std::shared_ptr<Entity::Gil::Image<GilImageT>> rv(new Entity::Gil::Image<GilImageT>);
    rv->widthPx = m_widthPx;
    rv->heightPx = m_heightPx;
    rv->resolutionPpi = m_resolutionPpi;

    rv->colorModel = getColorModel();
    rv->bitDepth = getChannelBitDepth();

    for(std::size_t i(0); i < m_layers.size(); ++i) {
      Entity::Gil::Layer<GilImageT> layer;
      layer.widthPx = m_layers[i].getWidthPx();
      layer.heightPx = m_layers[i].getHeightPx();
      layer.imageView = m_layers[i].getView();

      rv->layers.push_back(layer);
    }

    return rv;
  }

  template<class GilImageT>
  std::string
  Image<GilImageT>::getName() const {
    return m_name;
  }

  template<class GilImageT>
  std::string
  Image<GilImageT>::getFileSpec() const {
    return m_fileSpec;
  }

  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getWidthPx() const {
    return m_widthPx;
  }

  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getHeightPx() const {
    return m_heightPx;
  }

  template<class GilImageT>
  float
  Image<GilImageT>::getResolutionPpi() const {
    return m_resolutionPpi;
  }

  template<class GilImageT>
  UILayer::AbstractModel::Defs::EColorModel
  Image<GilImageT>::getColorModel() const {
    return ImageTraits<GilImageT>::colorModel;
  }

  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getNumChannels() const {
    return ImageTraits<GilImageT>::numChannels;
  }

  template<class GilImageT>
  UILayer::AbstractModel::Defs::EBitDepth
  Image<GilImageT>::getChannelBitDepth() const {
    return ImageTraits<GilImageT>::bitDepth;
  }

  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getNumLayers() const {
    return m_layers.size();
  }

  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getLayerWidthPx(std::size_t which) const {
    if(which >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[which].getWidthPx();
    }
  }

  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getLayerHeightPx(std::size_t which) const {
    if(which >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[which].getHeightPx();
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t::value_type
  Image<GilImageT>::getLayerPixelAt(std::size_t layerNum,
                                    Math::Coord<std::size_t> pos
                                   ) const
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getPixelAt(pos);
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t::value_type
  Image<GilImageT>::getLayerPixelAt(std::size_t layerNum,
                                    std::size_t x,
                                    std::size_t y
                                   ) const
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getPixelAt(x, y);
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum) {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getView();
    }
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum) const {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getView();
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum,
                                 Math::Rect<std::size_t> rect
                                )
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getView(rect);
    }
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum,
                                 Math::Rect<std::size_t> rect
                                ) const
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getView(rect);
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum,
                                 std::size_t x1,
                                 std::size_t y1,
                                 std::size_t x2,
                                 std::size_t y2
                                )
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getView(x1, y1, x2, y2);
    }
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum,
                                 std::size_t x1,
                                 std::size_t y1,
                                 std::size_t x2,
                                 std::size_t y2
                                ) const
  {
    if(layerNum >= m_layers.size()) {
      // TBA
    } else {
      return m_layers[layerNum].getView(x1, y1, x2, y2);
    }
  }
}

#endif
