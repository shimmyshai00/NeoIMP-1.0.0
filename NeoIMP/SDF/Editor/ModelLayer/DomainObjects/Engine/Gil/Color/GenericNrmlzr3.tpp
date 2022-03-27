#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_GENERICNRMLZR3_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_GENERICNRMLZR3_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GenericNrmlzr3.tpp
 * PURPOSE: Implements the GenericNrmlzr3 template.
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

#include <boost/gil/color_base.hpp>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Color {
  template<class ColorModelT, class GilPixelT>
  void
  GenericNrmlzr3<ColorModelT, GilPixelT>::normalize(
    const GilPixelT &px,
    std::array<float, 3> &uniformRep
  ) const {
    using namespace boost::gil;

    float chMin0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::min_value();
    float chMin1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::min_value();
    float chMin2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::min_value();

    float chWidth0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::max_value() -
      chMin0;
    float chWidth1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::max_value() -
      chMin1;
    float chWidth2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::max_value() -
      chMin2;

    uniformRep[0] = (boost::gil::semantic_at_c<0>(px) - chMin0) / chWidth0;
    uniformRep[1] = (boost::gil::semantic_at_c<1>(px) - chMin1) / chWidth1;
    uniformRep[2] = (boost::gil::semantic_at_c<2>(px) - chMin2) / chWidth2;
  }

  template<class ColorModelT, class GilPixelT>
  void
  GenericNrmlzr3<ColorModelT, GilPixelT>::unnormalize(
    const std::array<float, 3> &uniformRep,
    GilPixelT &px
  ) const {
    using namespace boost::gil;

    float chMin0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::min_value();
    float chMin1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::min_value();
    float chMin2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::min_value();

    float chWidth0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::max_value() -
      chMin0;
    float chWidth1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::max_value() -
      chMin1;
    float chWidth2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::max_value() -
      chMin2;

    px = GilPixelT(
      floor(uniformRep[0] * chWidth0 + chMin0 + 0.5f),
      floor(uniformRep[1] * chWidth1 + chMin1 + 0.5f),
      floor(uniformRep[2] * chWidth2 + chMin2 + 0.5f)
    );
  }
}

#endif
