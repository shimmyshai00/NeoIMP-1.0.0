/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRevColorSpace.cpp
 * PURPOSE: Implements the UiRevColorSpace class.
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

#include "UiRevColorSpace.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::ColorSpaces {
  UiRevColorSpace::UiRevColorSpace(
    std::shared_ptr<
      DomainObjects::Engine::ColorSpaces::IRevMapping<
        DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
      >
    > mapping
  )
    : m_mapping(mapping)
  {
  }

  UiRevColorSpace::SDRIllumColorSpace(
    std::shared_ptr<IBidirectionalColorModel<PixelDataT>> colorModel,
    std::shared_ptr<IBidirectionalMapping<FundamentalSpaceT>> mapping
  )
    : m_colorModel(colorModel),
      m_mapping(mapping)
  {
  }

  IRevColorModel<PixelDataT> &
  UiRevColorSpace::getColorModel() const {
    return *m_colorModel;
  }

  float
  UiRevColorSpace::getOutputMin(std::size_t fundamentalIdx) {
    return 0.0f;
  }

  float
  UiRevColorSpace::getOutputMax(std::size_t fundamentalIdx) {
    return 1.0f;
  }

  void
  UiRevColorSpace::fundamentalToPixel(
    const std::array<float, FundamentalTraitsT::num_channels> &fs,
    UILayer::AbstractModel::Defs::Color::IColor &pixel
  ) {
    std::array<float, 5> values; // n.b. 5 may not be enough

    // NB: assumes output in [0..1] from color model
    m_mapping->fundamentalToValues(&fs[0], &values[0]);
    m_colorModel.valuesToPixel(&values[0], pixel);
  }
}
