#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_LAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_LAYER_TPP

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

#include "../../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  Layer<GilImageT>::Layer(ImageMeasure widthPx,
                          ImageMeasure heightPx,
                          typename GilImageT::value_type initialColor
                         )
    : m_image(widthPx, heightPx, initialColor, 0)
  {
  }

  template<class GilImageT>
  ImageMeasure
  Layer<GilImageT>::getWidthPx() const {
    return m_image.dimensions().x;
  }

  template<class GilImageT>
  ImageMeasure
  Layer<GilImageT>::getHeightPx() const {
    return m_image.dimensions().y;
  }

  template<class GilImageT>
  typename GilImageT::view_t::value_type
  Layer<GilImageT>::getPixelAt(ImagePoint pos) const {
    return *GilImageT::const_view(m_image).xy_at(pos.getX(), pos.getY());
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView() {
    return boost::gil::view(m_image);
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView() const {
    return boost::gil::const_view(m_image);
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView(ImageRect rect) {
    typename GilImageT::view_t masterView(getView());
    return GilImageT::view_t(rect.getWidth(), rect.getHeight(), masterView.xy_at(rect.getX1(), rect.getY1()));
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView(ImageRect rect) const {
    typename GilImageT::const_view_t masterView(getView());
    return GilImageT::const_view_t(rect.getWidth(), rect.getHeight(), masterView.xy_at(rect.getX1(), rect.getY1()));
  }
}

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  std::size_t
  Layer<GilImageT>::getMemorySize(std::size_t width,
                                  std::size_t height
                                 )
  {
    // NB: not sure how accurate this is
    return sizeof(typename GilImageT::value_type)*width*height;
  }
}

#endif
