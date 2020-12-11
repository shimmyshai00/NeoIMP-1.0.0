/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilImage.tpp
 * PURPOSE: The image glue template for the Boost GIL.
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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/ImageDataVisitor.hpp>

#include <SDF/Impl/ModelLayer/Exception/Exceptions.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image::Gil {
  template<class GilAlphaType, class GilImageType>
  GilImage<GilAlphaType, GilImageType>::GilImage(
    std::size_t imageWidthPx,
    std::size_t imageHeightPx,
    float imageResolutionPpi
  )
    : m_imageWidthPx(imageWidthPx),
      m_imageHeightPx(imageHeightPx),
      m_imageResolutionPpi(imageResolutionPpi)
  {
    addNewLayer(0);
  }

  template<class GilAlphaType, class GilImageType>
  GilImage<GilAlphaType, GilImageType>::~GilImage() {}

  template<class GilAlphaType, class GilImageType>
  std::size_t GilImage<GilAlphaType, GilImageType>::getImageWidth() const {
    return m_imageWidthPx;
  }

  template<class GilAlphaType, class GilImageType>
  std::size_t GilImage<GilAlphaType, GilImageType>::getImageHeight() const {
    return m_imageHeightPx;
  }

  template<class GilAlphaType, class GilImageType>
  Math::Rect<std::size_t> GilImage<GilAlphaType, GilImageType>::getImageRect() const {
    return Math::Rect<std::size_t>(0, 0, m_imageWidthPx-1, m_imageHeightPx-1);
  }

  template<class GilAlphaType, class GilImageType>
  float GilImage<GilAlphaType, GilImageType>::getImageResolutionPpi() const {
    return m_imageResolutionPpi;
  }

  template<class GilAlphaType, class GilImageType>
  ModelLayer::Color::ColorModel GilImage<GilAlphaType, GilImageType>::getColorModel() const {
    // TBA until figuring out a good way to integrate this w/Boost templates
    return ModelLayer::Color::COLOR_MODEL_MAX;
  }

  template<class GilAlphaType, class GilImageType>
  ModelLayer::Color::BitDepth GilImage<GilAlphaType, GilImageType>::getBitDepth() const {
    // TBA
    return ModelLayer::Color::BIT_DEPTH_MAX;
  }

  template<class GilAlphaType, class GilImageType>
  std::size_t GilImage<GilAlphaType, GilImageType>::getNumImageLayers() const {
    return m_layers.size();
  }

  template<class GilAlphaType, class GilImageType>
  void GilImage<GilAlphaType, GilImageType>::addNewLayer(std::size_t layerNumToInsertBefore) {
    m_layers.push_back(std::make_unique<GilLayer<GilAlphaType, GilImageType>>(m_imageWidthPx, m_imageHeightPx));
  }

  template<class GilAlphaType, class GilImageType>
  void GilImage<GilAlphaType, GilImageType>::deleteLayer(std::size_t layerNum) {
    if(layerNum >= m_layers.size()) {
      throw ModelLayer::Exception::NonexistentLayerException(layerNum);
    }

    //m_layers.erase(layerNum);
  }

  template<class GilAlphaType, class GilImageType>
  void GilImage<GilAlphaType, GilImageType>::acceptLayerAlphaVisitor(
    std::size_t layerNum,
    Math::Rect<std::size_t> rect,
    ImageDataVisitor *visitor
  ) {
    if(layerNum >= m_layers.size()) {
      throw ModelLayer::Exception::NonexistentLayerException(layerNum);
    }

    m_layers[layerNum]->acceptAlphaVisitor(rect, visitor);
  }

  template<class GilAlphaType, class GilImageType>
  void GilImage<GilAlphaType, GilImageType>::acceptLayerPixelVisitor(
    std::size_t layerNum,
    Math::Rect<std::size_t> rect,
    ImageDataVisitor *visitor
  ) {
    if(layerNum >= m_layers.size()) {
      throw ModelLayer::Exception::NonexistentLayerException(layerNum);
    }

    m_layers[layerNum]->acceptPixelVisitor(rect, visitor);
  }
}
