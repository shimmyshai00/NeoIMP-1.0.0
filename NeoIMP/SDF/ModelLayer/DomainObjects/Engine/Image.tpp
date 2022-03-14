#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_TPP

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

#include "../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  Image<ImplSpecT>::Image(std::string name,
                          std::string fileSpec,
                          ImageMeasure widthPx,
                          ImageMeasure heightPx,
                          float resolutionPpi,
                          std::unique_ptr<Layer<ImplSpecT>> backgroundLayer
                         )
    : m_name(name),
      m_fileSpec(fileSpec),
      m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_resolutionPpi(resolutionPpi)
  {
    m_layers.push_back(std::move(backgroundLayer));
  }

  template<class ImplSpecT>
  std::shared_ptr<AbstractData::Entity::Image<typename ImplSpecT::entity_spec_t>>
  Image<ImplSpecT>::getEntity() const {
    auto entity = std::make_shared<AbstractData::Entity::Image<typename ImplSpecT::entity_spec_t>>(
      m_name, m_fileSpec, m_widthPx, m_heightPx, m_resolutionPpi);

    for(const auto &layer : m_layers) {
      layer->addToImageEntity(*entity);
    }

    return entity;
  }

  template<class ImplSpecT>
  std::string
  Image<ImplSpecT>::getName() const {
    return m_name;
  }

  template<class ImplSpecT>
  std::string
  Image<ImplSpecT>::getFileSpec() const {
    return m_fileSpec;
  }

  template<class ImplSpecT>
  ImageMeasure
  Image<ImplSpecT>::getWidthPx() const {
    return m_widthPx;
  }

  template<class ImplSpecT>
  ImageMeasure
  Image<ImplSpecT>::getHeightPx() const {
    return m_heightPx;
  }

  template<class ImplSpecT>
  ImageRect
  Image<ImplSpecT>::getRect() const {
    return ImageRect(0, 0, m_widthPx, m_heightPx);
  }

  template<class ImplSpecT>
  float
  Image<ImplSpecT>::getResolutionPpi() const {
    return m_resolutionPpi;
  }

  template<class ImplSpecT>
  std::size_t
  Image<ImplSpecT>::getNumLayers() const {
    return 1 + m_layers.size();
  }

  template<class ImplSpecT>
  Layer<ImplSpecT> &
  Image<ImplSpecT>::getLayer(std::size_t layerNum) {
    if(layerNum >= m_layers.size()) {
      // Oops
      throw OutOfRangeException();
    } else {
      return *m_layers[layerNum];
    }
  }

  template<class ImplSpecT>
  const Layer<ImplSpecT> &
  Image<ImplSpecT>::getLayer(std::size_t layerNum) const {
    if(layerNum >= m_layers.size()) {
      // Oops
      throw OutOfRangeException();
    } else {
      return *m_layers[layerNum];
    }
  }
}

#endif
