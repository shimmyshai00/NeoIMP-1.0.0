#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIAUTOCOLOR_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIAUTOCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiAutoColor.hpp
 * PURPOSE: Defines the UiAutoColor class.
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
#include "../../../UILayer/AbstractModel/Defs/Color/EColorModel.hpp"
#include "../../DomainObjects/Engine/IColorModel.hpp"

#include <cstddef>
#include <vector>

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  // The pixel format used by the below model. Narrower numbers of channels mean we just ignore
  // channels. The pixels here use [0, 1]-range values, so there is no need to worry about bit
  // depths. HDR is represented by values greater than 1, if applicable.
  class UiAutoPixel : public UILayer::AbstractModel::Defs::Color::IColor {
  public:
    // Function:   UiAutoPixel
    // Purpose:    Construct this auto pixel to a specified size.
    // Parameters: colorModel - The UI color model specifier this corresponds to.
    //             numChannels - The number of channels to make.
    UiAutoPixel(
      UILayer::AbstractModel::Defs::Color::EColorModel enumColorModel,
      std::size_t numChannels
    );

    EColorModel
    getColorModel() const;

    std::size_t
    getNumChannels() const;

    float
    getChannelMin(std::size_t idx) const;

    float
    getChannelMax(std::size_t idx) const;

    float
    get(std::size_t idx) const;

    void
    set(std::size_t idx, float val);
  private:
    UILayer::AbstractModel::Defs::Color::EColorModel m_enumColorModel;

    std::vector<float> m_values;
  };
}

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  // Class:      UiAutoColor
  // Purpose:    This is an interesting beast. It bridges between the domain model layer's data
  //             format-dependent color models (which are made that way for memory efficiency
  //             purposes, so we can work on image data of the right size, i.e. a low-color 16 bits-
  //             per-pixel image should not use 96 bits per pixel due to using generic types!) and
  //             the UI layer's generic parameter-passing models (which, since they do not involve
  //             lots of data, do not require this constraint). Because the latter are passed via an
  //             interface IColor, allowing the UI to use any color format it likes on the other
  //             side, to provide inter-conversion we must "straddle" the two worlds by implementing
  //             *both* the domain layer *and* UI layer interfaces. Fortunately, the two apply to
  //             different concepts; so we just need to implement IColor in UiAutoPixel and
  //             IColorModel here.
  // Parameters: None.
  class UiAutoColor : public DomainObjects::Engine::IColorModel<UiAutoPixel> {
  public:
    // Function:   UIAutoColor
    // Purpose:    Initializes the auto color to the specs of a test pixel. This is another
    //             interesting aspect - normally, color models are global constants. Here, though,
    //             we instantiate one dynamically.
    // Parameters: protoPixel - The test prototype pixel used to set the parameters.
    UiAutoColor(const IColor &protoPixel);

    // fortuitous - or not? - that these three coincide on the two interfaces including in return
    // type, FOR NOW
    std::size_t
    getNumChannels() const;

    float
    getChannelMax(std::size_t channelNum) const;

    float
    getChannelMin(std::size_t channelNum) const;

    UiAutoPixel
    convertToPixel(float *values) const;

    void
    convertPixelTo(UiAutoPixel px,
                   float *values
                  ) const;
  private:
    std::vector<float> m_channelMinLimits;
    std::vector<float> m_channelMaxLimits;
  };
}

#endif
