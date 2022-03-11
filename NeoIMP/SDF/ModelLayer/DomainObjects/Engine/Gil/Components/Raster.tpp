#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_RASTER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COMPONENTS_RASTER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Raster.tpp
 * PURPOSE: Implements the Raster template.
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
  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::Raster(ImageMeasure widthPx,
                                                           ImageMeasure heightPx,
                                                           GilPixelT initialColor
                                                          )
  {
    if((widthPx <= 0) || (heightPx <= 0)) {
      throw InvalidSizeException();
    }

    m_data = typename GilImplT::image_t(widthPx, heightPx, initialColor, 0);
  }

  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  Engine::Components::EContentType
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::getType() const {
    return Engine::Components::CONTENT_RASTER;
  }

  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  ImageRect
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::getIntrinsicRect() const {
    return ImageRect(0, 0, m_data.width(), m_data.height());
  }

  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  GilViewT
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::getView() {
    return boost::gil::view(m_data);
  }

  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  typename GilViewT::const_t
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::getView() const {
    return boost::gil::const_view(m_data);
  }

  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  GilViewT
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::getView(ImageRect rect) {
    // Clip the rectangle if it exceeds the bounds (neatly allows for large selections, for
    // example).
    ImageRect clipRect = getIntrinsicRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::view(m_data),
      typename GilImageT::point_t(rect.x1(), rect.y1()),
      typename GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }

  template<class GilImplT, class GilImageT, class GilViewT, class GilPixelT>
  typename GilViewT::const_t
  Raster<GilImplT, GilImageT, GilViewT, GilPixelT>::getView(ImageRect rect) const {
    ImageRect clipRect = getIntrinsicRect().intersect(rect);
    return boost::gil::subimage_view(boost::gil::const_view(m_data),
      typename GilImageT::point_t(rect.x1(), rect.y1()),
      typename GilImageT::point_t(rect.getWidth(), rect.getHeight())
    );
  }
}

#endif
