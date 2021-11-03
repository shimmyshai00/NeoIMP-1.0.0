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

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  Image<GilImageT>::Image(std::string name,
                          std::string fileSpec,
                          std::size_t widthPx,
                          std::size_t heightPx,
                          float resolutionPpi
                         )
    : m_uid(Uid::next()),
      m_name(name),
      m_fileSpec(fileSpec),
      m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_resolutionPpi(resolutionPpi)
  {
    m_layers.push_back(Layer<GilImageT>(widthPx, heightPx));
  }

  template<class GilImageT>
  Uid
  Image<GilImageT>::getUid() const {
    return m_uid;
  }

  template<class GilImageT>
  Image<GilImageT> &
  Image<GilImageT>::getObject() {
    return *this;
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
}

#endif
