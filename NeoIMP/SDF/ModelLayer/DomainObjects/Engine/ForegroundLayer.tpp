#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_FOREGROUNDLAYER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_FOREGROUNDLAYER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ForegroundLayer.tpp
 * PURPOSE: Implements the ForegroundLayer template.
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

namespace SDF::ModelLayer::DomainObjects::Engine {
  template<class ImplSpecT>
  ForegroundLayer<ImplSpecT>::ForegroundLayer(ImageMeasure widthPx,
                                              ImageMeasure heightPx
                                             )
    : Layer<ImplSpecT>(widthPx, heightPx)
  {
  }

  template<class ImplSpecT>
  void
  ForegroundLayer<ImplSpecT>::setContentComponent(
    std::unique_ptr<Components::IContent<ImplSpecT>> content
  ) {
    m_content = std::move(content);
  }

  template<class ImplSpecT>
  Components::IContent<ImplSpecT> *
  ForegroundLayer<ImplSpecT>::getContentComponent() {
    return m_content.get();
  }

  template<class ImplSpecT>
  const Components::IContent<ImplSpecT> *
  ForegroundLayer<ImplSpecT>::getContentComponent() const {
    return m_content.get();
  }
}

#endif
