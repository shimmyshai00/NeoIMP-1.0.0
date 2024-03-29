#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_CONVERSION_PIPELINE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_CONVERSION_PIPELINE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Pipeline.hpp
 * PURPOSE: Defines the Pipeline template.
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

#include "../IFwdNormalizer.hpp"
#include "../IFwdColorSpace.hpp"
#include "../IRevColorSpace.hpp"
#include "../IRevNormalizer.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Color::Conversion {
  // Class:      Pipeline
  // Purpose:    Defines an end-to-end color space conversion pipeline for converting one kind of
  //             pixel to another.
  // Parameters: SrcPixelT - The data type of the source pixels.
  //             SrcColorModelT - The source pixels' color model
  //             FundamentalSpaceT - The bridging fundamental space
  //             DstColorModelT - The destination pixels' color model
  //             DstPixelT - The destionation pixels' data type.
  template<
    class SrcPixelT,
    class SrcColorModelT,
    class FundamentalSpaceT,
    class DstColorModelT,
    class DstPixelT
  >
  class Pipeline {
  public:
    // Function:   Pipeline
    // Purpose:    Creates a new pixel conversion pipeline from the given components.
    // Parameters: srcNormalizer - The normalizer to normalize the source pixel values.
    //             srcColorSpace - The color space for the source pixels.
    //             dstColorSpace - The color space for the destination pixels.
    //             dstNormalizer - The normalizer for the destination pixels.
    Pipeline(
      IFwdNormalizer<SrcColorModelT, SrcPixelT> *a_srcNormalizer,
      IFwdColorSpace<SrcColorModelT, FundamentalSpaceT> *a_srcColorSpace,
      IRevColorSpace<DstColorModelT, FundamentalSpaceT> *a_dstColorSpace,
      IRevNormalizer<DstColorModelT, DstPixelT> *a_dstNormalizer
    );

    // Function:   convertPixel
    // Purpose:    Converts a pixel from the source to the destination type.
    // Parameters: srcPx - The pixel to convert.
    //             dstPx - The pixel to receive the result.
    // Returns:    The converted pixel.
    void
    convertPixel(const SrcPixelT &a_srcPx, DstPixelT &a_dstPx);
  private:
    IFwdNormalizer<SrcColorModelT, SrcPixelT> *m_srcNormalizer;
    IFwdColorSpace<SrcColorModelT, FundamentalSpaceT> *m_srcColorSpace;
    IRevColorSpace<DstColorModelT, FundamentalSpaceT> *m_dstColorSpace;
    IRevNormalizer<DstColorModelT, DstPixelT> *m_dstNormalizer;
  };
}

#include "Pipeline.tpp"

#endif
