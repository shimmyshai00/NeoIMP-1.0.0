#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_PNG_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_PNG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Png.hpp
 * PURPOSE: Defines a helper to validate a PNG for loading into a specific Boost.GIL-based image
 *          type.
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

#include "../../../../ModelLayer/DomainObjects/Engine/Image.hpp"
#include "../../../../ModelLayer/Exceptions.hpp"
#include "../../../Exceptions.hpp"

#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/io/get_reader.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>

#include <string>

namespace SDF::Editor::DataLayer::DataMappers::Gil::Validators {
  // Note that a validator only validates for a specific image spec type. Variants are to be
  // assessed by successive validation. Thus we can use a proper template structure here.
  struct Png {
    std::string m_fileSpec;

    Png(std::string fileSpec) : m_fileSpec(fileSpec) {}

    template<class GilSpecT>
    bool
    apply() {
      using namespace boost::gil;

      // Validate that the image on disk has the right color format to be loaded in as a background
      // layer
      try {
        typedef get_reader_backend<const std::string, png_tag>::type backend_t;
        backend_t backend = read_image_info(m_fileSpec, png_tag());

        return ((GilSpecT::num_bkg_channels == backend._info._num_channels) &&
                (GilSpecT::bits_per_channel == backend._info._bit_depth));
      } catch(std::ios_base::failure) {
        return false;
      }
    }
  };
}

#endif
