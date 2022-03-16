#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_ADAPTER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_ADAPTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Adapter.hpp
 * PURPOSE: The core of the color space system - the end-to-end adapter for putting two color spaces
 *          together.
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

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Note: in order to be adapted successfully, two color spaces must map to the same fundamental
  //       space. We can typecheck the number of fundamental channels, but not (yet) the semantics.
  //       NB!
  template<class PixelDataDstT, class PixelDataSrcT, class FundamentalTraitsT>
  PixelDataDstT adapt(
    const IColorSpace<PixelDataDstT, FundamentalTraitsT> &dstSpace,
    const IColorSpace<PixelDataSrcT, FundamentalTraitsT> &srcSpace,
    PixelDataSrcT srcVal
  ) {
    // Allow +1 for alpha channel-including spaces
    float fundamentals[FundamentalTraitsT::num_channels+1];

    srcSpace.pixelToFundamental(srcVal, fundamentals);
    return dstSpace.fundamentalToPixel(fundamentals);
  }
}

#endif
