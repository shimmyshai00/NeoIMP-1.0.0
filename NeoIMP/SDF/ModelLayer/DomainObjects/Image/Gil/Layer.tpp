#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_LAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_LAYER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Layer.tpp
 * PURPOSE: Implements the Layer template.
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

#include <boost/gil/image.hpp>

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  template<class GilImageType, class GilRegionType, class GilPixelType>
  Layer<GilImageType, GilRegionType, GilPixelType>::Layer(std::size_t width, std::size_t height)
    : m_layerPixelData(width, height)
  {
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Layer<GilImageType, GilRegionType, GilPixelType>::getWidth() const {
    return m_layerPixelData.width();
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  std::size_t
  Layer<GilImageType, GilRegionType, GilPixelType>::getHeight() const {
    return m_layerPixelData.height();
  }

  template<class GilImageType, class GilRegionType, class GilPixelType>
  void
  Layer<GilImageType, GilRegionType, GilPixelType>::acceptLayerDataVisitor(Math::Rect<std::size_t> rect,
                                                                           Services::AbstractDomain::IImageDataVisitor &visitor
                                                                          )
  {
    GilRegionType masterView(boost::gil::view(m_layerPixelData));
    GilRegionType view(rect.getWidth(), rect.getHeight(), masterView.xy_at(rect.getX1(), rect.getY1()));
    Services::AbstractDomain::Defs::GilRegionType viewAny(view);

    visitor.visitGilRegion(rect, viewAny);
  }
}

#endif
