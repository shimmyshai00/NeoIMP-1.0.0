#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_UICOLORCONVERTER_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_UICOLORCONVERTER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiColorConverter.tpp
 * PURPOSE: Implements the UiColorConverter template.
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

#include "../../../../Common/Overload.hpp"
#include "../../DomainObjects/Engine/ColorSpaces/Adapter.hpp"
#include "Defs.hpp"

#include <variant>

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  template<class DstPixelT, class FundamentalSpaceT>
  UiColorConverter<DstPixelT, FundamentalSpaceT>::UiColorConverter(
    const DomainObjects::Engine::IColorSpace<DstPixelT, FundamentalSpaceT> *dstColorSpace
  )
    : m_dstColorSpace(dstColorSpace)
  {
  }

  template<class DstPixelT, class FundamentalSpaceT>
  DstPixelT
  UiColorConverter<DstPixelT, FundamentalSpaceT>::convert(
    UILayer::AbstractModel::Defs::AnyColor anyColor
  ) {
    using namespace DomainObjects;
    using namespace UILayer::AbstractModel;

    // NB: assumes display is sRGB - reconfig TBA
    auto vis = Common::Overload {
      [=](Defs::RGB24_888_Color &c) {
        return Engine::ColorSpaces::adapt(*m_dstColorSpace, g_iec61966_sRGB_rgb24_888, c);
      },

      [=](Defs::ARGB32_8888_Color &c) {
        printf("alpha color: %d %d %d %d\n", (int)c.m_r, (int)c.m_g, (int)c.m_b, (int)c.m_a);
        // TBA to appease the compiler rn - this bit will require some more thought
        return Engine::ColorSpaces::adapt(*m_dstColorSpace, g_iec61966_sRGB_rgba32_8888, c);
      }
    };

    return std::visit(vis, anyColor);
  }
}

#endif
