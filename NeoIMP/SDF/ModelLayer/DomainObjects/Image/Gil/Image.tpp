#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_IMAGE_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_IMAGE_TPP

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

#include <SDF/ModelLayer/Exceptions/Exceptions.hpp>

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  template<class GilImageType, class GilRegionType, class GilPixelType>
  Image<GilImageType, GilRegionType, GilPixelType>::Image(int id,
                                                          std::string name,
                                                          std::size_t width,
                                                          std::size_t height
                                                         )
    : m_id(id),
      m_name(name),
      m_width(width),
      m_height(height),
      m_viewCenter(m_width / 2.0f, m_height / 2.0f),
      m_viewMagnification(1.0f)
  {
    m_layerStack.push_back(std::make_unique<Layer<GilImageType, GilRegionType, GilPixelType>>(m_width, m_height));
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  Image<GilImageType, GilRegionType, GilPixelType>::Image(int id,
                                                          std::string name,
                                                          const GilImageType &gilImage
                                                         )
    : m_id(id),
      m_name(name),
      m_width(gilImage.width()),
      m_height(gilImage.height()),
      m_viewCenter(m_width / 2.0f, m_height / 2.0f),
      m_viewMagnification(1.0f)
  {
    m_layerStack.push_back(std::make_unique<Layer<GilImageType, GilRegionType, GilPixelType>>(gilImage));
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  int
  Image<GilImageType, GilRegionType, GilPixelType>::getId() const {
    return m_id;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::string
  Image<GilImageType, GilRegionType, GilPixelType>::getName() const {
    return m_name;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getWidth() const {
    return m_width;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getHeight() const {
    return m_height;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getNumLayers() const {
    return m_layerStack.size();
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  Math::Coord<float>
  Image<GilImageType, GilRegionType, GilPixelType>::getViewCenter() const {
    return m_viewCenter;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  float
  Image<GilImageType, GilRegionType, GilPixelType>::getViewMagnification() const {
    return m_viewMagnification;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::setName(std::string name) {
    m_name = name;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::setViewCenter(Math::Coord<float> viewCenter) {
    m_viewCenter = viewCenter;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::setViewMagnification(float viewMagnification) {
    m_viewMagnification = viewMagnification;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::addLayerBefore(std::size_t pos,
                                                                   std::size_t width,
                                                                   std::size_t height
                                                                  )
  {
    if(pos > m_layerStack.size()) {
      // TBA
    } else {
      // TBA
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::removeLayer(std::size_t pos) {
    if(pos >= m_layerStack.size()) {
      throw ModelLayer::Exceptions::InvalidLayerException(pos);
    } else {
      // TBA
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getRawLayerWidth(std::size_t layerNum) const {
    if(layerNum >= m_layerStack.size()) {
      throw ModelLayer::Exceptions::InvalidLayerException(layerNum);
    } else {
      return m_layerStack[layerNum]->getWidth();
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getRawLayerHeight(std::size_t layerNum) const {
    if(layerNum >= m_layerStack.size()) {
      throw ModelLayer::Exceptions::InvalidLayerException(layerNum);
    } else {
      return m_layerStack[layerNum]->getHeight();
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::acceptImageDataVisitor(std::size_t layerNum,
                                                                           Math::Rect<std::size_t> rect,
                                                                           Services::AbstractDomain::IImageDataVisitor &visitor
                                                                          )
  {
    if(layerNum >= m_layerStack.size()) {
      throw ModelLayer::Exceptions::InvalidLayerException(layerNum);
    } else {
      m_layerStack[layerNum]->acceptLayerDataVisitor(rect, visitor);
    }
  }
}

#endif
