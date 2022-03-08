#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYLAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYLAYER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AnyLayer.tpp
 * PURPOSE: Defines the AnyLayer template.
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
  template<class ... GilImageTs>
  template<class GilImageT>
  AnyLayer<GilImageTs...>::AnyLayer(const Layer<GilImageT> &layer)
    : m_widthPx(layer.m_widthPx),
      m_heightPx(layer.m_heightPx),
      m_data(layer.m_data)
  {
  }

  template<class ... GilImageTs>
  template<class GilImageT>
  AnyLayer<GilImageTs...>::AnyLayer(Layer<GilImageT> &&layer)
    : m_widthPx(std::move(layer.m_widthPx)),
      m_heightPx(std::move(layer.m_heightPx)),
      m_data(std::move(layer.m_data))
  {
  }

  template<class ... GilImageTs>
  ImageMeasure
  AnyLayer<GilImageTs...>::getWidthPx() const {
    return m_widthPx;
  }

  template<class ... GilImageTs>
  ImageMeasure
  AnyLayer<GilImageTs...>::getHeightPx() const {
    return m_heightPx;
  }

  template<class ... GilImageTs>
  ImageRect
  AnyLayer<GilImageTs...>::getRect() const {
    return ImageRect(0, 0, m_widthPx, m_heightPx);
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyLayer<GilImageTs...>::getView() {
    return boost::gil::view(m_data);
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyLayer<GilImageTs...>::getView() const {
    return boost::gil::const_view(m_data);
  }
}

#endif
