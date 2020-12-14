/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilLayer.tpp
 * PURPOSE: The layer glue template for the Boost GIL.
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Image/ImageDataVisitor.hpp>

#include <boost/gil/point.hpp>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Image::Gil {
  template<class GilAlphaType, class GilImageType>
  GilLayer<GilAlphaType, GilImageType>::GilLayer(std::size_t layerWidthPx, std::size_t layerHeightPx)
    : m_alpha(layerWidthPx, layerHeightPx),
      m_image(layerWidthPx, layerHeightPx)
  {}

  template<class GilAlphaType, class GilImageType>
  std::size_t GilLayer<GilAlphaType, GilImageType>::getLayerWidth() const {
    return m_alpha.width();
  }

  template<class GilAlphaType, class GilImageType>
  std::size_t GilLayer<GilAlphaType, GilImageType>::getLayerHeight() const {
    return m_alpha.height();
  }

  template<class GilAlphaType, class GilImageType>
  void GilLayer<GilAlphaType, GilImageType>::acceptAlphaVisitor(
    Math::Rect<std::size_t> rect,
    ImageDataVisitor *visitor
  ) {
    typename GilAlphaType::view_t masterView(boost::gil::view(m_alpha));
    typename GilAlphaType::view_t view(
      rect.getWidth(), rect.getHeight(),
      masterView.xy_at(rect.getX1(), rect.getY1())
    );

    visitor->visitGilRegion(view);
  }

  template<class GilAlphaType, class GilImageType>
  void GilLayer<GilAlphaType, GilImageType>::acceptPixelVisitor(
    Math::Rect<std::size_t> rect,
    ImageDataVisitor *visitor
  ) {
    typename GilImageType::view_t masterView(boost::gil::view(m_image));
    typename GilImageType::view_t view(
      rect.getWidth(), rect.getHeight(),
      masterView.xy_at(rect.getX1(), rect.getY1())
    );

    visitor->visitGilRegion(view);
  }
}
