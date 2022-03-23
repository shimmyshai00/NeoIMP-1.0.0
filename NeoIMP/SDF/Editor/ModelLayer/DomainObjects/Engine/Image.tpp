#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_TPP

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

#include "../../../../Error/GeneralException.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  Image<ImplSpecT>::Image()
    : m_name("Unnamed"),
      m_resolutionPpi(120.0f)
  {
  }

  template<class ImplSpecT>
  Image<ImplSpecT>::Image(std::string name, float resolutionPpi)
    : m_name(name),
      m_resolutionPpi(resolutionPpi)
  {
  }

  template<class ImplSpecT>
  std::string
  Image<ImplSpecT>::getName() const {
    return m_name;
  }

  template<class ImplSpecT>
  ImageMeasure
  Image<ImplSpecT>::getWidthPx() const {
    if(m_layers.size() == 0) {
      return 0;
    } else {
      return m_layers[0]->getContentWidth();
    }
  }

  template<class ImplSpecT>
  ImageMeasure
  Image<ImplSpecT>::getHeightPx() const {
    if(m_layers.size() == 0) {
      return 0;
    } else {
      return m_layers[0]->getContentHeight();
    }
  }

  template<class ImplSpecT>
  ImageRect
  Image<ImplSpecT>::getRect() const {
    if(m_layers.size() == 0) {
      return ImageRect(0, 0, 0, 0);
    } else {
      return m_layers[0]->getContentRect();
    }
  }

  template<class ImplSpecT>
  float
  Image<ImplSpecT>::getResolutionPpi() const {
    return m_resolutionPpi;
  }

  template<class ImplSpecT>
  std::size_t
  Image<ImplSpecT>::getNumLayers() const {
    return m_layers.size();
  }

  template<class ImplSpecT>
  Layer<ImplSpecT> &
  Image<ImplSpecT>::getLayer(std::size_t layerNum) {
    if(layerNum >= m_layers.size()) {
      throw Error::OutOfBoundsException();
    } else {
      return *m_layers[layerNum];
    }
  }

  template<class ImplSpecT>
  const Layer<ImplSpecT> &
  Image<ImplSpecT>::getLayer(std::size_t layerNum) const {
    if(layerNum >= m_layers.size()) {
      throw Error::OutOfBoundsException();
    } else {
      return *m_layers[layerNum];
    }
  }

  template<class ImplSpecT>
  void
  Image<ImplSpecT>::setName(std::string name) {
    m_name = name;
  }

  template<class ImplSpecT>
  void
  Image<ImplSpecT>::setResolutionPpi(float resolutionPpi) {
    m_resolutionPpi = resolutionPpi;
  }

  template<class ImplSpecT>
  void
  Image<ImplSpecT>::addLayer(std::unique_ptr<Layer<ImplSpecT>> layer) {
    m_layers.push_back(std::move(layer));
  }
}

#endif
