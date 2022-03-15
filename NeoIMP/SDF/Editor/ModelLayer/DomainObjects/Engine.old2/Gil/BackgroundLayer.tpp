#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_BACKGROUNDLAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_BACKGROUNDLAYER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BackgroundLayer.tpp
 * PURPOSE: Implements the BackgroundLayer template.
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
  template<class GilSpecT>
  BackgroundLayer<GilSpecT>::BackgroundLayer(ImageMeasure widthPx,
                                             ImageMeasure heightPx,
                                             typename GilSpecT::bkg_pixel_t bkgColor
                                            )
    : Layer<GilSpecT>(widthPx, heightPx),
      m_content(new Components::BackgroundRaster<GilSpecT>(widthPx, heightPx, bkgColor))
  {
  }

  template<class GilSpecT>
  ELayerType
  BackgroundLayer<GilSpecT>::getType() const {
    return LAYER_BACKGROUND;
  }

  template<class GilSpecT>
  ImageRect
  BackgroundLayer<GilSpecT>::getIntrinsicRect() const {
    return ImageRect(0, 0, m_data.width(), m_data.height());
  }

  template<class GilSpecT>
  ImageRect
  BackgroundLayer<GilSpecT>::getEffectiveRect() const {
    return getIntrinsicRect();
  }
}

#endif
