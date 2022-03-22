#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_UIAUTOSPACE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_UIAUTOSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiAutoSpace.hpp
 * PURPOSE: Defines the UiAutoSpace template.
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

#include "../../DomainObjects/Engine/IColorSpace.hpp"
#include "../../DomainObjects/Engine/IColorModel.hpp"
#include "../ColorModels/UiAutoColor.hpp"

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  // Class:      UiAutoSpace
  // Purpose:    The color-space companion to UiAutoColor and UiAutoPixel. This provides a color
  //             space that can map out UI values to a given fundamental space and thus bridge the
  //             UI layer and domain layer with regard to color data.
  // Parameters: FundamentalTraitsT - The type of fundamental color space involved.
  //             MapT - The type of color space fundamental map to affix. Note this assumes that the
  //                    map is channel-compatible with the incoming color data. This means care is
  //                    required when considering, for example, CMYK input to an RGB image or
  //                    RGB input to a CMYK image. The ideal auto map should be able to take either
  //                    type of input and convert appropriately to the fundamental space of the
  //                    image being processed since the UI should be able to input any pixel format
  //                    it wants. Hence, the last component is an ideal UiAutoMap that handles this.
  template<class FundamentalTraitsT, class MapT>
  class UiAutoSpace : public DomainObjects::Engine::IColorSpace<
                        std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor>,
                        FundamentalTraitsT
                      >
  {
  public:
    // Function:   UiAutoSpace
    // Purpose:    Dynamically constructs a new auto space from an auto color model.
    // Parameters: autoColorModel - The auto color model to construct from.
    UiAutoSpace(const UiAutoColor &autoColorModel);

    const DomainObjects::Engine::IColorModel<
      std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor>
    > &
    getColorModel() const;

    void
    pixelToFundamental(std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor> pixel,
                       float *fs
                      ) const;

    std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor>
    fundamentalToPixel(float *fs) const;
  private:
    UiAutoColor m_autoColorModel;
  };
}

#include "UiAutoSpace.tpp"

#endif
