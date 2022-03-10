#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_RGBXYZBASE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_RGBXYZBASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RgbXyzBase.hpp
 * PURPOSE: Defines the RgbXyzBase template.
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

#include "../ColorModels/Base.hpp"
#include "../IColorSpace.hpp"

#include <tuple>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:      RgbXyzBase
  // Purpose:    Defines a color-space base for RGB spaces mapping to CIE 1931 XYZ as their
  //             fundamental.
  // Parameters: PixelDataT - The type of pixel data accepted.
  template<class PixelDataT>
  class RgbXyzBase : public IColorSpace<PixelDataT> {
  public:
    virtual ~XyzBase() = default;

    // Function:   RgbXyzBase
    // Purpose:    Builds the color space on the given color model.
    // Parameters: colorModel - The color model going in.
    // Returns:    None.
    template<std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
    RgbXyzBase(const ColorModels::Base<PixelDataT, BitsR, BitsG, BitsB> *colorModel);

    const IColorModel<PixelDataT> &
    getColorModel() const;

    void
    pixelToFundamental(PixelDataT pixel,
                       float *fs
                      ) const;

    PixelDataT
    fundamentalToPixel(float *fs) const;
  protected:
    // Function:   rgbToXyz
    // Purpose:    Defines a mapping of a normalized RGB value (reals in [0, 1]) to normalized
    //             XYZ values (also in [0, 1]).
    // Parameters: rgb - The RGB input.
    // Returns:    The XYZ output.
    virtual
    std::tuple<float, float, float> rgbToXyz(std::tuple<float, float, float> rgb) = 0;

    // Function:   xyzToRgb
    // Purpose:    Defines the inverse mapping of the above.
    // Parameters: xyz - The XYZ input.
    // Returns:    The RGB output.
    virtual
    std::tuple<float, float, float> xyzToRgb(std::tuple<float, float, float> xyz) = 0;
  private:
    const ColorModels::Base<PixelDataT, BitsR, BitsG, BitsB> *m_colorModel;
  };
}

#include "RgbXyzBase.tpp"

#endif
