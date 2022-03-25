#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODEL_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODEL_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorModel.tpp
 * PURPOSE: Implements the ColorModel template.
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

#include <boost/gil/channel.hpp>
#include <boost/gil/typedefs.hpp>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil {
  namespace Impl {
    struct float_zero { static float apply() { return 0.0f; } };
    struct float_one { static float apply() { return 1.0f; } };
    using float01custom_t = boost::gil::scoped_channel_value<float, float_zero, float_one>;
  }

  template<class GilPixelT>
  GilPixelT
  ColorModel<GilPixelT>::convertToPixel(
    const std::array<float, pixel_traits<GilPixelT>::num_channels> &values
  ) const {
    using namespace boost::gil;

    pixel<Impl::float01custom_t, devicen_t<pixel_traits<GilPixelT>::num_channels>>> floatPixel;
    GilPixelT rv;

    for(std::size_t i(0); i < pixel_traits<GilPixelT>::num_channels; ++i) {
      dynamic_at_c(floatPixel, i) = values[i];
    }

    color_convert(floatPixel, rv);

    return rv;
  }

  template<class GilPixelT>
  void
  ColorModel<GilPixelT>::convertPixelTo(
    PixelDataT px,
    std::array<float, pixel_traits<GilPixelT>::num_channels> &values
  ) const {
    using namespace boost::gil;

    pixel<Impl::float01custom_t, devicen_t<pixel_traits<GilPixelT>::num_channels>>> floatPixel;
    color_convert(px, floatPixel);

    for(std::size_t i(0); i < pixel_traits<GilPixelT>::num_channels; ++i) {
      values[i] = dynamic_at_c(floatPixel, i);
    }
  }
}

#endif
