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

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  Layer<GilImageT>::Layer(std::size_t widthPx,
                          std::size_t heightPx
                         )
    : m_image(widthPx, heightPx)
  {
  }

  template<class GilImageT>
  std::size_t
  Layer<GilImageT>::getWidthPx() const {
    return m_image.dimensions().x;
  }

  template<class GilImageT>
  std::size_t
  Layer<GilImageT>::getHeightPx() const {
    return m_image.dimensions().y;
  }

  template<class GilImageT>
  typename GilImageT::view_t::value_type
  Layer<GilImageT>::getPixelAt(Math::Coord<std::size_t> pos) const {
    return *GilImageT::const_view(m_image).xy_at(pos.getX(), pos.getY());
  }

  template<class GilImageT>
  typename GilImageT::view_t::value_type
  Layer<GilImageT>::getPixelAt(std::size_t x,
                               std::size_t y
                              ) const
  {
    return getPixelAt(Math::Coord<std::size_t>(x, y));
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView() {
    return GilImageT::view(m_image);
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView() const {
    return GilImageT::const_view(m_image);
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView(Math::Rect<std::size_t> rect) {
    typename GilImageT::view_t masterView(getView());
    return GilImageT::view_t(rect.getWidth(), rect.getHeight(), masterView.xy_at(rect.getX1(), rect.getY1()));
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView(Math::Rect<std::size_t> rect) const {
    typename GilImageT::const_view_t masterView(getView());
    return GilImageT::const_view_t(rect.getWidth(), rect.getHeight(), masterView.xy_at(rect.getX1(), rect.getY1()));
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView(std::size_t x1,
                            std::size_t y1,
                            std::size_t x2,
                            std::size_t y2
                           )
  {
    return getView(Math::Rect<std::size_t>(x1, y1, x2, y2));
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView(std::size_t x1,
                            std::size_t y1,
                            std::size_t x2,
                            std::size_t y2
                           ) const
  {
    return getView(Math::Rect<std::size_t>(x1, y1, x2, y2));
  }
}

#endif
