#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYLAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYLAYER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AnyLayer.tpp
 * PURPOSE: Implements the AnyLayer template.
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
  template<class T>
  AnyLayer<GilImageTs...>::AnyLayer(const Layer<T> &layer)
    : m_image(layer.m_image)
  {
  }

  template<class ... GilImageTs>
  template<class T>
  AnyLayer<GilImageTs...>::AnyLayer(Layer<T> &&layer)
    : m_image(std::move(layer.m_image))
  {
  }

  /*
  template<class T, class ... GilImageTs>
  Layer<T> *
  AnyLayer<GilImageTs...>::specifize(bool doSwap) {
    Layer<T> rv = new Layer<T>(1, 1);

    if(!doSwap) {
      rv.m_image =
    }
  }
  */

  template<class ... GilImageTs>
  std::size_t
  AnyLayer<GilImageTs...>::getWidthPx() const {
    return m_image.dimensions().x;
  }

  template<class ... GilImageTs>
  std::size_t
  AnyLayer<GilImageTs...>::getHeightPx() const {
    return m_image.dimensions().y;
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyLayer<GilImageTs...>::getView() {
    return boost::gil::any_image<GilImageTs...>::view_t(m_image);
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyLayer<GilImageTs...>::getView() const {
    return boost::gil::any_image<GilImageTs...>::const_view_t(m_image);
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyLayer<GilImageTs...>::getView(Math::Rect<std::size_t> rect) {
    typename boost::gil::any_image<GilImageTs...>::view_t masterView(getView());
    return boost::gil::any_image<GilImageTs...>::view_t(rect.getWidth(), rect.getHeight(),
      masterView.xy_at(rect.getX1(), rect.getY1()));
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyLayer<GilImageTs...>::getView(Math::Rect<std::size_t> rect) const {
    typename boost::gil::any_image<GilImageTs...>::const_view_t masterView(getView());
    return boost::gil::any_image<GilImageTs...>::const_view_t(rect.getWidth(), rect.getHeight(),
      masterView.xy_at(rect.getX1(), rect.getY1()));
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::view_t
  AnyLayer<GilImageTs...>::getView(std::size_t x1,
                                   std::size_t y1,
                                   std::size_t x2,
                                   std::size_t y2
                                  )
  {
    return getView(Math::Rect<std::size_t>(x1, y1, x2, y2));
  }

  template<class ... GilImageTs>
  typename boost::gil::any_image<GilImageTs...>::const_view_t
  AnyLayer<GilImageTs...>::getView(std::size_t x1,
                                   std::size_t y1,
                                   std::size_t x2,
                                   std::size_t y2
                                  ) const
  {
    return getView(Math::Rect<std::size_t>(x1, y1, x2, y2));
  }
}

#endif
