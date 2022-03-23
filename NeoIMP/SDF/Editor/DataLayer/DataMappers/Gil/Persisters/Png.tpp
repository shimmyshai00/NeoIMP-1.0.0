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
  Png::operator()(ModelLayer::DomainObjects::Engine::Image<GilSpecT> &image) {
    using namespace ModelLayer::DomainObjects;
    using namespace boost::gil;

    if(m_direction == DIR_SAVE) {
      Engine::Gil::Components::Content::Background<GilSpecT> *bkgComponent(nullptr);

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
    } else if(m_direction == DIR_LOAD) {
      // That potentially problematic domain-object creation business ...

      // One thing we have to do here is check to see if the image data has the right pixel format
      // to be read into GilSpecT::bkg_image_t. Ideally, the caller of this should have matched
      // by instantiating us with the appropriate spec, but we want to double-check here.
      try {
        typedef get_reader_backend<const std::string, png_tag>::type backend_t;
        backend_t backend = read_image_info(m_fileSpec, png_tag());

        // TBA: embedded color profiles -> should adjust color space of ImageT with suitable
        // Component right now we effectively just interpret as sRGB
        // TBA 2: properly handling images with alpha when loading to non-alpha format
        if((GilSpecT::num_bkg_channels == backend._info._num_channels) &&
           (GilSpecT::bits_per_channel == backend._info._bit_depth))
        {
          // This format is congruent. Finish the loading process.
          auto c = std::make_unique<Engine::Gil::Components::Content::Background<GilSpecT>>(
            backend._info._width, backend._info._height, typename GilSpecT::bkg_pixel_t());

          read_view(m_fileSpec, c->getView(), png_tag());

          // Now check if the image already has a background layer.
          if(image.getNumLayers() > 0) {
            // TBA
            throw "NOT YET IMPLEMENTED";
          } else {
            // Create a new layer.
            auto bkgLayer = std::make_unique<Engine::Layer<GilSpecT>>();
            bkgLayer->attachComponent(Engine::Layer<GilSpecT>::c_contentComponentId, std::move(c));

            image.addLayer(std::move(bkgLayer));
          }

          // TBA: other ancillary info like resolution
        } else {
          throw UnsupportedSubFormatException(m_fileSpec.c_str());
        }
      } catch(std::ios_base::failure) {
        // that's just plain rich ... backend_t has no default constructor; so we cannot catch the
        // error when it occurs and it's possible something as general as this might have other
        // causes.
        throw MalformedFileException(m_fileSpec.c_str());
      }
    }
  }
}

#endif
