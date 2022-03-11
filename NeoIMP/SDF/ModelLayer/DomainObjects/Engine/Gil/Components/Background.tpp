#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_BACKGROUND_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_BACKGROUND_TPP

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

#include "../../../../Exceptions.hpp"

#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>
#include <boost/gil/image_view_factory.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Components {
  template<class GilImplT>
  Background<GilImplT>::Background(ImageMeasure widthPx,
                                   ImageMeasure heightPx,
                                   typename GilImplT::pixel_t initialColor
                                  )
  {
    if((widthPx <= 0) || (heightPx <= 0)) {
      throw InvalidSizeException();
    }

    m_data = typename GilImplT::image_t(widthPx, heightPx, initialColor, 0);
  }

  template<class GilImplT>
  Engine::Components::EContentType
  Background<GilImplT>::getType() const {
    return Engine::Components::CONTENT_BACKGROUND_RASTER;
  }

  template<class GilImplT>
  ImageRect
  Background<GilImplT>::getIntrinsicRect() const {
    return ImageRect(0, 0, m_data.width(), m_data.height());
  }

  template<class GilImplT>
  typename GilImplT::view_t
  Background<GilImplT>::getView() {
    return boost::gil::view(m_data);
  }

  template<class GilImplT>
  typename GilImplT::view_t::const_t
  Background<GilImplT>::getView() const {
    return boost::gil::const_view(m_data);
  }

  template<class GilImplT>
  typename GilImplT::view_t
  Background<GilImplT>::getView(ImageRect rect) {
    // Clip the rectangle if it exceeds the bounds (neatly allows for large selections, for
    // example).
    ImageRect clipRect = getRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::view(m_data),
      typename GilImageT::point_t(rect.x1(), rect.y1()),
      typename GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }

  template<class GilImplT>
  typename GilImplT::view_t::const_t
  Background<GilImplT>::getView(ImageRect rect) const {
    ImageRect clipRect = getRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::const_view(m_data),
      typename GilImageT::point_t(rect.x1(), rect.y1()),
      typename GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }
}

#endif
