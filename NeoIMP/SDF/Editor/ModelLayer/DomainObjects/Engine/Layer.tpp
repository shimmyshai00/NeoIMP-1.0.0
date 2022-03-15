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
#include "Components/ContentComponent.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  Layer<ImplSpecT>::Layer()
  {
  }

  template<class ImplSpecT>
  void
  Layer<ImplSpecT>::addToImageEntity(
    AbstractData::Entity::Image<typename ImplSpecT::entity_spec_t> &entity
  ) const {
    auto layerEntity = AbstractData::Entity::Layer<typename ImplSpecT::entity_spec_t>();
    for(const auto &c : m_components) {
      c.second->addToLayerEntity(layerEntity);
    }

    entity.m_layers.push_back(layerEntity);
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getContentWidth() const {
    return getContentRect().width();
  }

  template<class ImplSpecT>
  ImageMeasure
  Layer<ImplSpecT>::getContentHeight() const {
    return getContentRect().height();
  }

  template<class ImplSpecT>
  ImageRect
  Layer<ImplSpecT>::getContentRect() const {
    using namespace Components;

    return findFirstComponentByFamily<ContentComponent<ImplSpecT>>(COMPONENT_CONTENT)->
      getIntrinsicRect();
  }

  template<class ImplSpecT>
  template<class U>
  bool
  Layer<ImplSpecT>::hasComponent() {
    return (m_components.find(typeid(U)) != m_components.end());
  }

  template<class ImplSpecT>
  template<class U>
  U *
  Layer<ImplSpecT>::attachComponent(std::unique_ptr<U> component) {
    if(!hasComponent<U>()) {
      U *rv = component.get();
      m_components[typeid(U)] = std::move(component);
      return rv;
    } else {
      throw ComponentAlreadyAddedException();
    }
  }

  template<class ImplSpecT>
  template<class U>
  U *
  Layer<ImplSpecT>::getComponent() {
    if(m_components.find(typeid(U)) != m_components.end()) {
      return dynamic_cast<U *>(m_components[typeid(U)].get());
    } else {
      return nullptr;
    }
  }

  template<class ImplSpecT>
  template<class U>
  const U *
  Layer<ImplSpecT>::getComponent() const {
    if(m_components.find(typeid(U)) != m_components.end()) {
      return dynamic_cast<const U *>(m_components[typeid(U)].get());
    } else {
      return nullptr;
    }
  }
}

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  template<class U>
  U *
  Layer<ImplSpecT>::findFirstComponentByFamily(Components::EFamily family) {
    for(const auto &kvp : m_components) {
      if(kvp.second->getFamily() == family) {
        if(auto p = dynamic_cast<U>(kvp.second.get())) {
          return p;
        } else {
          throw BadCastException();
        }
      }
    }

    // not found
    return nullptr;
  }
}

#endif
