#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_LAYER_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_LAYER_TPP

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

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Image {
  template<class ImplSpecT>
  Layer<ImplSpecT>::Layer()
  {
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getWidthPx() const {
    if(!m_contentComponent) {
      return 0;
    } else {
      return m_contentComponent->getWidthPx();
    }
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getHeightPx() const {
    if(!m_contentComponent) {
      return 0;
    } else {
      return m_contentComponent->getHeightPx();
    }
  }

  template<class ImplSpecT>
  ImageRect
  Layer<ImplSpecT>::getDimensionsRect() const {
    if(!m_contentComponent) {
      return ImageRect(0, 0, 0, 0);
    } else {
      return m_contentComponent->getDimensionsRect();
    }
  }

  template<class ImplSpecT>
  ImageRect
  Layer<ImplSpecT>::getBoundingRect() const {
    // no transforms for now
    return getDimensionsRect();
  }

  template<class ImplSpecT>
  void
  Layer<ImplSpecT>::setContentComponent(
    std::unique_ptr<Components::AContent<ImplSpecT>> a_component
  ) {
    m_contentComponent = std::move(a_component);
  }

  template<class ImplSpecT>
  Components::AContent<ImplSpecT> *
  Layer<ImplSpecT>::getContentComponent() {
    return m_contentComponent.get();
  }

  template<class ImplSpecT>
  const Components::AContent<ImplSpecT> *
  Layer<ImplSpecT>::getContentComponent() const {
    return m_contentComponent.get();
  }

  template<class ImplSpecT>
  template<class AsT>
  AsT *
  Layer<ImplSpecT>::getContentComponentAs() {
    if(auto p = dynamic_cast<AsT *>(m_contentComponent.get())) {
      return p;
    } else {
      throw BadComponentCastException();
    }
  }

  template<class ImplSpecT>
  template<class AsT>
  const AsT *
  Layer<ImplSpecT>::getContentComponentAs() const {
    if(auto p = dynamic_cast<AsT *>(m_contentComponent.get())) {
      return p;
    } else {
      throw BadComponentCastException();
    }
  }
}

#endif
