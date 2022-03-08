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
#include "../../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  Image<GilImageT>::Image(std::string name,
                          std::string fileSpec,
                          ImageMeasure widthPx,
                          ImageMeasure heightPx,
                          float resolutionPpi,
                          typename GilImageT::value_type initialColor
                         )
    : m_name(name),
      m_fileSpec(fileSpec),
      m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_resolutionPpi(resolutionPpi)
  {
    m_layers.push_back(Layer<GilImageT>(widthPx, heightPx, initialColor));
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
  ImageMeasure
  Image<GilImageT>::getWidthPx() const {
    return m_widthPx;
  }

  template<class GilImageT>
  ImageMeasure
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
  ImageMeasure
  Image<GilImageT>::getLayerWidthPx(std::size_t which) const {
    if(which >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[which].getWidthPx();
    }
  }

  template<class GilImageT>
  ImageMeasure
  Image<GilImageT>::getLayerHeightPx(std::size_t which) const {
    if(which >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[which].getHeightPx();
    }
  }

  template<class GilImageT>
  ImageRect
  Image<GilImageT>::getLayerRect(std::size_t which) const {
    if(which >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return Math::Rect<std::size_t>(0, 0, m_layers[which].getWidthPx()-1,
        m_layers[which].getHeightPx()-1);
    }
  }

  template<class GilImageT>
  bool
  Image<GilImageT>::applyOperation(IImageOperation<Image<GilImageT>> &op,
                                   const std::vector<OpRegion> &regions,
                                   IProgressListener *progress
                                  )
  {
    return op.performOperation(*this, regions, progress);
  }

  template<class GilImageT>
  bool
  Image<GilImageT>::applyOperation(IImageOperation<Image<GilImageT>> &op,
                                   ImageRect rect,
                                   IProgressListener *progress
                                  )
  {
    std::vector<OpRegion> regions;

    for(std::size_t i(0); i < m_layers.size(); ++i) {
      regions.push_back(OpRegion(i, rect));
    }

    return op.performOperation(*this, regions, progress);
  }

  template<class GilImageT>
  bool
  Image<GilImageT>::applyOperation(IImageOperation<Image<GilImageT>> &op,
                                   IProgressListener *progress
                                  )
  {
    std::vector<OpRegion> regions;

    for(std::size_t i(0); i < m_layers.size(); ++i) {
      regions.push_back(OpRegion(i, getLayerRect(i)));
    }

    return op.performOperation(*this, regions, progress);
  }

  template<class GilImageT>
  typename GilImageT::view_t::value_type
  Image<GilImageT>::getLayerPixelAt(std::size_t layerNum,
                                    ImagePoint pos
                                   ) const
  {
    if(layerNum >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum].getPixelAt(pos);
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum) {
    if(layerNum >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum].getView();
    }
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum) const {
    if(layerNum >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum].getView();
    }
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum,
                                 ImageRect rect
                                )
  {
    if(layerNum >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum].getView(rect);
    }
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Image<GilImageT>::getLayerView(std::size_t layerNum,
                                 ImageRect rect
                                ) const
  {
    if(layerNum >= m_layers.size()) {
      throw OutOfRangeException();
    } else {
      return m_layers[layerNum].getView(rect);
    }
  }
}

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  std::size_t
  Image<GilImageT>::getMemorySizeForOneLayer(std::size_t width,
                                             std::size_t height
                                            )
  {
    return Layer<GilImageT>::getMemorySize(width, height);
  }
}

#endif
