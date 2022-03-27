#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_UIREVCOLORSPACE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_UIREVCOLORSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRevColorSpace.hpp
 * PURPOSE: Defines the UiRevColorSpace template.
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
#include "../DomainObjects/Engine/ColorSpaces/Fundamental/XyzD65.hpp"
#include "../DomainObjects/Engine/ColorSpaces/IRevMapping.hpp"
#include "../DomainObjects/Engine/IRevColorModel.hpp"
#include "../DomainObjects/Engine/IRevColorSpace.hpp"

#include <cstddef>
#include <memory>

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  // Class:      UiRevColorSpace
  // Purpose:    Defines a reverse-mapped color space to send small amounts of color data to the UI.
  class UiRevColorSpace : public DomainObjects::Engine::IRevColorSpace<
                            UILayer::AbstractModel::Defs::Color::IColor,
                            DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
                          >
  {
  public:
    UiRevColorSpace(
      std::shared_ptr<
        DomainObjects::Engine::ColorSpaces::IRevMapping<
          DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
        >
      > mapping
    );

    IRevColorModel<PixelDataT> &
    getColorModel() const;

    float
    getOutputMin(std::size_t fundamentalIdx);

    float
    getOutputMax(std::size_t fundamentalIdx);

    void
    fundamentalToPixel(
      const std::array<float, FundamentalTraitsT::num_channels> &fs,
      UILayer::AbstractModel::Defs::Color::IColor &pixel
    );
  private:
    ColorModels::UiRevColorModel<UILayer::AbstractModel::Defs::Color::EUiColorModel> m_colorModel;

    std::shared_ptr<
      DomainObjects::Engine::ColorSpaces::IRevMapping<
        DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
      >
    > m_mapping;
  };
}

#include "UiRevColorSpace.tpp"

#endif
