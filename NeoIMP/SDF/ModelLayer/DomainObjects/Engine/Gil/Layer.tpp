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

#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>
#include <boost/gil/image_view_factory.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImageT>
  Layer<GilImageT>::Layer(ImageMeasure widthPx,
                          ImageMeasure heightPx,
                          typename GilImageT::value_type fillColor
                         )
    : m_widthPx(widthPx),
      m_heightPx(heightPx),
      m_data(widthPx, heightPx, fillColor, 0)
  {
  }

  template<class GilImageT>
  ImageMeasure
  Layer<GilImageT>::getWidthPx() const {
    return m_widthPx;
  }

  template<class GilImageT>
  ImageMeasure
  Layer<GilImageT>::getHeightPx() const {
    return m_heightPx;
  }

  template<class GilImageT>
  ImageRect
  Layer<GilImageT>::getRect() const {
    return ImageRect(0, 0, m_widthPx, m_heightPx);
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView() {
    return boost::gil::view(m_data);
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView() const {
    return boost::gil::const_view(m_data);
  }

  template<class GilImageT>
  typename GilImageT::view_t
  Layer<GilImageT>::getView(ImageRect rect) {
    // Clip the rectangle if it exceeds the bounds (neatly allows for large selections, for
    // example).
    ImageRect clipRect = getRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::view(m_data),
      GilImageT::point_t(rect.x1(), rect.y1()),
      GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }

  template<class GilImageT>
  typename GilImageT::const_view_t
  Layer<GilImageT>::getView(ImageRect rect) const {
    ImageRect clipRect = getRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::const_view(m_data),
      GilImageT::point_t(rect.x1(), rect.y1()),
      GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }
}

#endif
