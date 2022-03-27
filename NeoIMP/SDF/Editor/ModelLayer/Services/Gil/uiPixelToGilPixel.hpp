#ifndef SDF_EDITOR_MODELLAYER_SERIVCES_GIL_UIPIXELTOGILPIXEL_HPP
#define SDF_EDITOR_MODELLAYER_SERIVCES_GIL_UIPIXELTOGILPIXEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    uiPixelToGilPixel.hpp
 * PURPOSE: Defines a helper method for converting UI pixels to Boost.GIL pixels.
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

#include "../../../UILayer/AbstractModel/Defs/Color/IColor.hpp"
#include "../../../UILayer/AbstractModel/Defs/Color/EColorModel.hpp"
#include "../Exceptions.hpp"

#include <boost/gil/pixel.hpp>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Note: for this method to work right, the UI input color should have the same ranges as the
  //       GIL pixel type. That's the point: it's for importing document-bound data from the UI -
  //       it is **NOT** a color model/color space conversion!
  template<class GilPixelT>
  GilPixelT
  uiPixelToGilPixel(
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EColorModel
    > &color
  ) {
#ifndef NDEBUG
    if(boost::gil::num_channels<GilPixelT>::value != color.getNumChannels()) {
      throw IncompatiblePixelFormatsException();
    }
#endif NDEBUG

    GilPixelT rv;

    for(std::size_t i(0); i < color.getNumChannels(); ++i) {
      boost::gil::dynamic_at_c(rv, i) = color.getValue(i);
    }

    return(rv);
  }
}

#endif
