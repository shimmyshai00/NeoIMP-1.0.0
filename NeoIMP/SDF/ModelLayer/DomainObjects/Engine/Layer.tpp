#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_TPP

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

#include "../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  Layer<ImplSpecT>::Layer(ImageMeasure widthPx,
                          ImageMeasure heightPx
                         )
    : m_widthPx(widthPx),
      m_heightPx(heightPx)
  {
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getWidthPx() const {
    return m_widthPx;
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getHeightPx() const {
    return m_heightPx;
  }

  template<class ImplSpecT>
  template<class U>
  U *Layer<ImplSpecT>::contentAs() {
    if(auto p = dynamic_cast<U *>(getContentComponent())) {
      return p;
    } else {
      throw BadCastException();
    }
  }

  template<class ImplSpecT>
  template<class U>
  const U *Layer<ImplSpecT>::contentAs() const {
    if(auto p = dynamic_cast<const U *>(getContentComponent())) {
      return p;
    } else {
      throw BadCastException();
    }
  }
}

#endif
