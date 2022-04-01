#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_CONVERSION_PIPELINE_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_CONVERSION_PIPELINE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Pipeline.tpp
 * PURPOSE: Implements the Pipeline template.
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

#include <array>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Color::Conversion {
  template<
    class SrcPixelT,
    class SrcColorModelT,
    class FundamentalSpaceT,
    class DstColorModelT,
    class DstPixelT
  >
  Pipeline<SrcPixelT, SrcColorModelT, FundamentalSpaceT, DstColorModelT, DstPixelT>::Pipeline(
    IFwdNormalizer<SrcColorModelT, SrcPixelT> *a_srcNormalizer,
    IFwdColorSpace<SrcColorModelT, FundamentalSpaceT> *a_srcColorSpace,
    IRevColorSpace<DstColorModelT, FundamentalSpaceT> *a_dstColorSpace,
    IRevNormalizer<DstColorModelT, DstPixelT> *a_dstNormalizer
  )
    : m_srcNormalizer(a_srcNormalizer),
      m_srcColorSpace(a_srcColorSpace),
      m_dstColorSpace(a_dstColorSpace),
      m_dstNormalizer(a_dstNormalizer)
  {
  }

  template<
    class SrcPixelT,
    class SrcColorModelT,
    class FundamentalSpaceT,
    class DstColorModelT,
    class DstPixelT
  >
  void
  Pipeline<SrcPixelT, SrcColorModelT, FundamentalSpaceT, DstColorModelT, DstPixelT>::convertPixel(
    const SrcPixelT &a_srcPx,
    DstPixelT &a_dstPx
  ) {
    std::array<float, SrcColorModelT::num_channels> srcNrmlRep;
    std::array<float, FundamentalSpaceT::num_channels> fundamentalRep;
    std::array<float, DstColorModelT::num_channels> dstNrmlRep;

    m_srcNormalizer->normalize(a_srcPx, srcNrmlRep);
    m_srcColorSpace->nrmlToFundamental(srcNrmlRep, fundamentalRep);
    m_dstColorSpace->fundamentalToNrml(fundamentalRep, dstNrmlRep);
    m_dstNormalizer->unnormalize(dstNrmlRep, a_dstPx);
  }
}

#endif
