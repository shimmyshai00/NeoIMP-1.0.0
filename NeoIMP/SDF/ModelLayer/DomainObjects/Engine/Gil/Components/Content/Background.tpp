#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_CONTENT_BACKGROUND_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_CONTENT_BACKGROUND_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Background.tpp
 * PURPOSE: Implements the Background template.
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
#include <boost/gil/image_view.hpp>
#include <boost/gil/image_view_factory.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Components::Content {
  template<class GilSpecT>
  Background<GilSpecT>::Background(std::size_t widthPx,
                                   std::size_t heightPx,
                                   typename GilImplT::bkg_pixel_t bkgColor
                                  )
    : m_data(widthPx, heightPx, bkgColor, 0)
  {
  }

  template<class GilSpecT>
  ImageRect
  Background<GilSpecT>::getIntrinsicRect() const {
    return ImageRect(0, 0, m_data.width(), m_data.height());
  }

  template<class GilSpecT>
  typename GilSpecT::bkg_image_t &
  Background<GilSpecT>::getData() {
    return m_data;
  }

  template<class GilSpecT>
  const typename GilSpecT::bkg_image_t &
  Background<GilSpecT>::getData() const {
    return m_data;
  }

  template<class GilSpecT>
  typename GilSpecT::bkg_view_t
  Background<GilSpecT>::getView() {
    return boost::gil::view(m_data);
  }

  template<class GilSpecT>
  typename GilSpecT::bkg_view_t::const_t
  Background<GilSpecT>::getView() const {
    return boost::gil::const_view(m_data);
  }

  template<class GilSpecT>
  typename GilSpecT::bkg_view_t
  Background<GilSpecT>::getView(ImageRect rect) {
    // Clip the rectangle if it exceeds the bounds (neatly allows for large selections, for
    // example).
    ImageRect clipRect = getIntrinsicRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::view(m_data),
      typename GilImageT::point_t(rect.x1(), rect.y1()),
      typename GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }

  template<class GilSpecT>
  typename GilSpecT::bkg_view_t::const_t
  Background<GilSpecT>::getView(ImageRect rect) const {
    ImageRect clipRect = getIntrinsicRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::const_view(m_data),
      typename GilImageT::point_t(rect.x1(), rect.y1()),
      typename GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }
}

#endif
