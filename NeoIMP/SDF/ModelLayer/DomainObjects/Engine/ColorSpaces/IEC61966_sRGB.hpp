#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_IEC61966_SRGB_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_IEC61966_SRGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IEC61966_sRGB.hpp
 * PURPOSE: Defines the IEC61966_sRGB template.
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

#include "../ColorModels/Categories.hpp"
#include "../IColorModel.hpp"
#include "Fundamental/XyzD65.hpp"
#include "RgbBase.hpp"

#include <algorithm>
#include <cmath>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:      IEC61966_sRGB
  // Purpose:    Defines a family of color spaces based on the IEC 61966-2-1:1999 sRGB "standard
  //             Red Green Blue" standard, which is the common color space used by typical monitors
  //             and typical reference designant of RGB raw data in image files (e.g. CSS hex values
  //             on the Web). In effect, the "plate carrée" of color spaces. The fundamental space
  //             is CIE 1931 XYZ with the D65 standard illuminant. This last bit SHOULD BE NOTED.
  //             E.g. Photoshop has a CIELAB space implementation which uses *D50*. This affects the
  //             normalization below.
  // Parameters: PixelDataT - The pixel data format to use.
  //             BitsR, BitsG, BitsB - The bit widths of the pixel data channels.
  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  class IEC61966_sRGB : public RgbBase<PixelDataT, Fundamental::XyzD65, BitsR, BitsG, BitsB> {
  public:
    IEC61966_sRGB(const ColorModels::RgbBase<PixelDataT, BitsR, BitsG, BitsB> *rgbColorModel)
      : RgbBase<PixelDataT, Fundamental::XyzD65, BitsR, BitsG, BitsB>(rgbColorModel)
    {}
  protected:
    // The color space is simply a mapping defined by a matrix operation. NOTE / CONTRIB REQ: these
    // color values were taken from third-party online reference - this author does not have the
    // riches to pay $180 to get the standards document from IEC to confirm the full conformance of
    // this implementation to the given standard. That said, it was taken from:
    //
    //      https://www.color.org/srgb04.xalter
    //
    //  which is presumably a reliable enough source to achieve this aim.
    void
    nrmlToFundamental(float *nrml,
                      float *fs
                     ) const
    {
      // This is the matrix inverse of the matrix below. The 4-digits is not an accident; it
      // appears the matrix given in the pdf was obtained by inverting an original defined to 4
      // digit precision. Note that this may be important for high depth color, so should be
      // further investigated (NB!) to see if that 4-digit matrix is really standardized at 4
      // digits or if there is missing precision at play here.

      float RL, GL, BL;

      if(nrml[0] <= 0.04045f) {
        RL = nrml[0] / 12.92f;
      } else {
        RL = pow((nrml[0] + 0.055f) / 1.055f, 2.4f); // NB: pow is slow
      }

      if(nrml[1] <= 0.04045f) {
        GL = nrml[1] / 12.92f;
      } else {
        GL = pow((nrml[1] + 0.055f) / 1.055f, 2.4f); // NB: pow is slow
      }

      if(nrml[2] <= 0.04045f) {
        BL = nrml[2] / 12.92f;
      } else {
        BL = pow((nrml[2] + 0.055f) / 1.055f, 2.4f); // NB: pow is slow
      }

      fs[0] = 0.4124f*RL + 0.3576f*GL + 0.1805f*BL;
      fs[1] = 0.2126f*RL + 0.7152f*GL + 0.0722f*BL;
      fs[2] = 0.0193f*RL + 0.1192f*GL + 0.9505f*BL;
    }

    void
    fundamentalToNrml(float *fs,
                      float *nrml
                     ) const
    {
      // This function was actually coded first.
      float RL = std::clamp<float>(3.2406255f*fs[0] - 1.537208f*fs[0] - 0.4986286f*fs[0], 0.0f, 1.0f);
      float GL = std::clamp<float>(-0.9689307f*fs[1] + 1.8757561f*fs[1] + 0.0415175f*fs[1], 0.0f, 1.0f);
      float BL = std::clamp<float>(0.0557101f*fs[2] - 0.2040211f*fs[2] + 1.0569959f*fs[2], 0.0f, 1.0f);

      // Standardized gamma correction
      if(RL <= 0.0031308) {
        nrml[0] = 12.92f * RL;
      } else {
        nrml[0] = 1.055f * pow(RL, 1.0f/2.4f) - 0.055f; // NB: pow is slow
      }

      if(GL <= 0.0031308) {
        nrml[1] = 12.92f * GL;
      } else {
        nrml[1] = 1.055f * pow(GL, 1.0f/2.4f) - 0.055f; // NB: pow is slow
      }

      if(BL <= 0.0031308) {
        nrml[2] = 12.92f * BL;
      } else {
        nrml[2] = 1.055f * pow(BL, 1.0f/2.4f) - 0.055f; // NB: pow is slow
      }
    }
  };
}

#endif
