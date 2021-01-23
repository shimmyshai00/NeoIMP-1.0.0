#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_GIL_GILLAYER_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_GIL_GILLAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilLayer.hpp
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Math/Rect.hpp>

#include <cstdlib>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Image {
  class ImageDataVisitor;

  namespace Gil {
    template<class GilAlphaType, class GilImageType>
    class GilLayer {
    public:
      GilLayer(std::size_t layerWidthPx, std::size_t layerHeightPx);
      GilLayer(const GilImageType &gilImageBuffer);
      ~GilLayer() {}

      std::size_t getLayerWidth() const;
      std::size_t getLayerHeight() const;

      void acceptAlphaVisitor(Math::Rect<std::size_t> rect, ImageDataVisitor *visitor);
      void acceptPixelVisitor(Math::Rect<std::size_t> rect, ImageDataVisitor *visitor);
    private:
      GilAlphaType m_alpha;
      GilImageType m_image;
    };
  }
}

#include "SDF/Impl/ModelLayer/Impl/DomainObjects/Image/Gil/GilLayer.tpp"

#endif
