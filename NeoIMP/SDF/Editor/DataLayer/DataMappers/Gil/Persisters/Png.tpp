#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_PNG_TPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_PNG_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Png.tpp
 * PURPOSE: Implements the Png persister.
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

#include "../../../../ModelLayer/DomainObjects/Engine/Gil/Components/Content/Background.hpp"
#include "../../../../ModelLayer/DomainObjects/Exceptions.hpp"
#include "../../Exceptions.hpp"

#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/io/get_reader.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>

#include <memory>

namespace SDF::Editor::DataLayer::DataMappers::Gil::Persisters {
  template<class GilSpecT>
  void
  Png::operator()(const ModelLayer::DomainObjects::Engine::Image<GilSpecT> &image) {
    using namespace ModelLayer::DomainObjects;
    using namespace boost::gil;

    const Engine::Gil::Components::Content::Background<GilSpecT> *bkgComponent(nullptr);

    // Sanity check
    if(image.getNumLayers() == 0) {
      throw ImageMissingLayersException();
    } else {
      // Validate the background layer structure.
      try {
        bkgComponent = image.getLayer(0)
          .template findComponentById<Engine::Gil::Components::Content::Background<GilSpecT>>(
            Engine::Layer<GilSpecT>::c_contentComponentId
          );

        if(bkgComponent == nullptr) {
          throw ImageLayerMissingContentException();
        }
      } catch(ModelLayer::DomainObjects::BadComponentCastException) {
        throw ImageMissingBackgroundLayerException();
      }
    }

    write_view(m_fileSpec, bkgComponent->getView(), png_tag());
  }
}

#endif
