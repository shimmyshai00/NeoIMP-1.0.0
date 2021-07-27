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

#include "../../../Metrics/DimensionlessQuantity.hpp"
#include "../../../Metrics/LengthQuantity.hpp"
#include "../../../Metrics/ResolutionQuantity.hpp"
#include "../../../Metrics/makeLength.hpp"
#include "../../../Metrics/makeResolution.hpp"
#include "../../../Metrics/lengthIn.hpp"
#include "../../../Metrics/resolutionIn.hpp"

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  template<class GilImageType, class GilRegionType, class GilPixelType>
  Image<GilImageType, GilRegionType, GilPixelType>::Image(int id,
                                                          std::string name,
                                                          std::size_t widthPx,
                                                          std::size_t heightPx,
                                                          float resolution,
                                                          Metrics::ResolutionUnit resolutionUnit
                                                         )
    : m_id(id),
      m_name(name),
      m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_resolution(Metrics::makeResolution(resolution, resolutionUnit))
  {
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  Image<GilImageType, GilRegionType, GilPixelType>::Image(int id,
                                                          std::string name,
                                                          float width,
                                                          Metrics::LengthUnit widthUnit,
                                                          float height,
                                                          Metrics::LengthUnit heightUnit,
                                                          float resolution,
                                                          Metrics::ResolutionUnit resolutionUnit
                                                         )
    : m_id(id),
      m_name(name),
      m_widthPx(0),
      m_heightPx(0),
      m_resolution(Metrics::makeResolution(resolution, resolutionUnit)),
      m_viewCenter(m_widthPx / 2.0f, m_heightPx / 2.0f),
      m_viewMagnification(1.0f)
  {
    m_widthPx = Metrics::dimensionless_quantity(Metrics::makeLength(width, widthUnit) * m_resolution).value();
    m_heightPx = Metrics::dimensionless_quantity(Metrics::makeLength(height, heightUnit) * m_resolution).value();

    m_layerStack.push_back(std::make_unique<Layer<GilImageType, GilRegionType, GilPixelType>>(m_widthPx, m_heightPx));
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  Image<GilImageType, GilRegionType, GilPixelType>::Image(int id,
                                                          std::string name,
                                                          const GilImageType &gilImage,
                                                          float resolution,
                                                          Metrics::ResolutionUnit resolutionUnit
                                                         )
    : m_id(id),
      m_name(name),
      m_widthPx(gilImage.width()),
      m_heightPx(gilImage.height()),
      m_resolution(Metrics::makeResolution(resolution, resolutionUnit)),
      m_viewCenter(m_widthPx / 2.0f, m_heightPx / 2.0f),
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
  std::unique_ptr<AbstractData::Entity::ImageEntity>
  Image<GilImageType, GilRegionType, GilPixelType>::createEntity() const {
    return std::unique_ptr<AbstractData::Entity::ImageEntity>(new AbstractData::Entity::ImageEntity);
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::string
  Image<GilImageType, GilRegionType, GilPixelType>::getName() const {
    return m_name;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getWidthPx() const {
    return m_widthPx;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  float
  Image<GilImageType, GilRegionType, GilPixelType>::getWidthPhys(Metrics::LengthUnit unit) const {
    if(unit == Metrics::LENGTH_UNIT_PIXEL) {
      return m_widthPx;
    } else {
      return Metrics::lengthIn(Metrics::dimensionless_quantity(m_widthPx) / m_resolution, unit);
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getHeightPx() const {
    return m_heightPx;
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  float
  Image<GilImageType, GilRegionType, GilPixelType>::getHeightPhys(Metrics::LengthUnit unit) const {
    if(unit == Metrics::LENGTH_UNIT_PIXEL) {
      return m_heightPx;
    } else {
      return Metrics::lengthIn(Metrics::dimensionless_quantity(m_heightPx) / m_resolution, unit);
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  float
  Image<GilImageType, GilRegionType, GilPixelType>::getResolution(Metrics::ResolutionUnit unit) const {
    return Metrics::resolutionIn(m_resolution, unit);
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
  Image<GilImageType, GilRegionType, GilPixelType>::getRawLayerWidthPx(std::size_t layerNum) const {
    if(layerNum >= m_layerStack.size()) {
      throw ModelLayer::Exceptions::InvalidLayerException(layerNum);
    } else {
      return m_layerStack[layerNum]->getWidthPx();
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Image<GilImageType, GilRegionType, GilPixelType>::getRawLayerHeightPx(std::size_t layerNum) const {
    if(layerNum >= m_layerStack.size()) {
      throw ModelLayer::Exceptions::InvalidLayerException(layerNum);
    } else {
      return m_layerStack[layerNum]->getHeightPx();
    }
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Image<GilImageType, GilRegionType, GilPixelType>::acceptImageDataVisitor(std::size_t layerNum,
                                                                           Math::Rect<std::size_t> rect,
                                                                           IImageDataVisitor &visitor
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
