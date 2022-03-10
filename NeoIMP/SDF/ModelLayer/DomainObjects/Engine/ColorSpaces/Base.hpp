#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_BASE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_BASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LDRBase.hpp
 * PURPOSE: Defines the LDRBase template.
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

#include "../IColorModel.hpp"
#include "../IColorSpace.hpp"

#include <tuple>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:      LDRBase
  // Purpose:    Defines a base for low dynamic range color spaces.
  // Parameters: PixelDataT - The type of pixel data to build this space on.
  //             FundamentalChannelCount - The number of fundamental space channels.
  //             BitCounts - The bit counts of the underlying channels.
  template<class PixelDataT, std::size_t FundamentalChannelCount, std::size_t ... BitCounts>
  class LDRBase : public IColorSpace<PixelDataT, FundamentalChannelCount> {
  public:
    // Class:      LDRBase
    // Purpose:    Constructs a color space base on top of a given color model.
    // Parameters: colorModel - The color model to use.
    LDRBase(const IColorModel<PixelDataT> *colorModel);

    const IColorModel<PixelDataT> &
    getColorModel() const;

    void
    pixelToFundamental(PixelDataT pixel,
                       float *fs
                      ) const;

    PixelDataT
    fundamentalToPixel(float *fs) const;
  protected:
    // Function:   nrmlToFundamental
    // Purpose:    Converts normalized floating-point values coming out of the color model, i.e. in
    //             the range [0, 1], to normalized values in the fundamental space.
    // Parameters: fs - The array of fundamental space values (must have FundamentalChannelCount
    //                  values).
    //             nrml - The normalized color model output (must have the same number of channels.)
    // Returns:    None.
    virtual void
    nrmlToFundamental(float *fs,
                      float *nrml
                     ) const = 0;

    // Function:   fundamentalToNrml
    // Purpose:    Does the inverse mapping of the above.
    // Parameters: nrml - ditto.
    //             fs - ditto.
    // Returns:    None.
    virtual void
    fundamentalToNrml(float *nrml,
                      float *fs
                     ) const = 0;
  private:
    const IColorModel<PixelDataT> *m_colorModel;
  };
}

#endif
