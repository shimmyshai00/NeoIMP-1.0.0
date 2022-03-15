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
  Layer<ImplSpecT>::Layer()
  {
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getWidthPx() const;

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getHeightPx() const;

  template<class ImplSpecT>
  ImageRect
  getContentRect() const;

  template<class ImplSpecT>
  void
  attachComponent(std::unique_ptr<Components::IComponent<ImplSpecT>> component);

  template<class ImplSpecT>
  std::unique_ptr<Components::IComponent<ImplSpecT>>
  removeComponent(Components::EType type);

  template<class ImplSpecT>
  template<class U>
  U *
  getComponent();

  template<class ImplSpecT>
  template<class U>
  const U *
  getComponent() const;
}

#endif
