#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_TPP

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
#include "Components/IContentComponent.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  Layer<ImplSpecT>::Layer()
  {
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getContentWidth() const {
    return getContentRect().getWidth();
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getContentHeight() const {
    return getContentRect().getHeight();
  }

  template<class ImplSpecT>
  ImageRect
  Layer<ImplSpecT>::getContentRect() const {
    using namespace Components;

    if(auto *p = findComponentById<IContentComponent<ImplSpecT>>(c_contentComponentId)) {
      return p->getIntrinsicRect();
    } else {
      return ImageRect(0, 0, 0, 0); // no recognizable content!
    }
  }

  template<class ImplSpecT>
  void
  Layer<ImplSpecT>::attachComponent(
    std::string id,
    std::unique_ptr<Components::IComponent<ImplSpecT>> component
  ) {
    if(m_components.find(id) != m_components.end()) {
      throw ComponentAlreadyAddedException(id.c_str());
    } else {
      m_components[id] = std::move(component);
    }
  }

  template<class ImplSpecT>
  template<class U>
  U *
  Layer<ImplSpecT>::findComponentById(std::string id) {
    if(m_components.find(id) == m_components.end()) {
      return nullptr;
    } else {
      if(U *p = dynamic_cast<U *>(m_components[id].get())) {
        return p;
      } else {
        throw BadCastException();
      }
    }
  }

  template<class ImplSpecT>
  template<class U>
  const U *
  Layer<ImplSpecT>::findComponentById(std::string id) const {
    if(m_components.find(id) == m_components.end()) {
      return nullptr;
    } else {
      if(const U *p = dynamic_cast<const U *>(m_components.at(id).get())) {
        return p;
      } else {
        throw BadCastException();
      }
    }
  }

  template<class ImplSpecT>
  void
  Layer<ImplSpecT>::visitComponents(typename ImplSpecT::component_visitor_t &visitor) {
    for(auto &component : m_visitationList) {
      component->accept(visitor);
    }
  }

  template<class ImplSpecT>
  void
  Layer<ImplSpecT>::visitComponents(typename ImplSpecT::const_component_visitor_t &visitor) const {
    for(auto &component : m_visitationList) {
      component->accept(visitor);
    }
  }
}

#endif
