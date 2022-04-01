#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_GENERICNRMLZR4_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_GENERICNRMLZR4_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GenericNrmlzr4.tpp
 * PURPOSE: Implements the GenericNrmlzr4 template.
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
  GenericNrmlzr4<ColorModelT, GilPixelT>::normalize(
    const GilPixelT &a_px,
    std::array<float, 4> &a_uniformRep
  ) const {
    using namespace boost::gil;

    float chMin0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::min_value();
    float chMin1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::min_value();
    float chMin2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::min_value();
    float chMin3 = channel_traits<typename kth_element_type<GilPixelT, 3>::type>::min_value();

    float chWidth0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::max_value() -
      chMin0;
    float chWidth1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::max_value() -
      chMin1;
    float chWidth2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::max_value() -
      chMin2;
    float chWidth3 = channel_traits<typename kth_element_type<GilPixelT, 3>::type>::max_value() -
      chMin3;

    a_uniformRep[0] = (boost::gil::semantic_at_c<0>(a_px) - chMin0) / chWidth0;
    a_uniformRep[1] = (boost::gil::semantic_at_c<1>(a_px) - chMin1) / chWidth1;
    a_uniformRep[2] = (boost::gil::semantic_at_c<2>(a_px) - chMin2) / chWidth2;
    a_uniformRep[3] = (boost::gil::semantic_at_c<3>(a_px) - chMin3) / chWidth3;
  }

  template<class ColorModelT, class GilPixelT>
  void
  GenericNrmlzr4<ColorModelT, GilPixelT>::unnormalize(
    const std::array<float, 4> &a_uniformRep,
    GilPixelT &a_px
  ) const {
    using namespace boost::gil;

    float chMin0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::min_value();
    float chMin1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::min_value();
    float chMin2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::min_value();
    float chMin3 = channel_traits<typename kth_element_type<GilPixelT, 3>::type>::min_value();

    float chWidth0 = channel_traits<typename kth_element_type<GilPixelT, 0>::type>::max_value() -
      chMin0;
    float chWidth1 = channel_traits<typename kth_element_type<GilPixelT, 1>::type>::max_value() -
      chMin1;
    float chWidth2 = channel_traits<typename kth_element_type<GilPixelT, 2>::type>::max_value() -
      chMin2;
    float chWidth3 = channel_traits<typename kth_element_type<GilPixelT, 3>::type>::max_value() -
      chMin3;

    a_px = GilPixelT(
      floor(a_uniformRep[0] * chWidth0 + chMin0 + 0.5f),
      floor(a_uniformRep[1] * chWidth1 + chMin1 + 0.5f),
      floor(a_uniformRep[2] * chWidth2 + chMin2 + 0.5f),
      floor(a_uniformRep[3] * chWidth3 + chMin3 + 0.5f)
    );
  }
}

#endif
