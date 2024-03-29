#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_COLORSPACES_IEC61966_2_1_SRGB_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_COLORSPACES_IEC61966_2_1_SRGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IEC61966_2_1_sRGB.hpp
 * PURPOSE: Defines the IEC61966_2_1_sRGB class.
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

#include "../Models/Rgb.hpp"
#include "../FundamentalSpaces/XyzD65.hpp"
#include "../IColorSpace.hpp"

#include <cmath>
#include <array>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Color::ColorSpaces {
  // The color space is simply a mapping defined by a matrix operation. NOTE / CONTRIB REQ: these
  // color values were taken from third-party online reference - this author does not have the
  // riches to pay $180 to get the standards document from IEC to confirm the full conformance of
  // this implementation to the given standard. That said, it was taken from:
  //
  //      https://www.color.org/srgb04.xalter
  //
  //  which is presumably a reliable enough source to achieve this aim.
  class IEC61966_2_1_sRGB : public IColorSpace<Models::Rgb, FundamentalSpaces::XyzD65> {
  public:
    void
    nrmlToFundamental(
      const std::array<float, 3> &a_uniformRep,
      std::array<float, 3> &a_fs
    ) const {
      // This is the matrix inverse of the matrix below. The 4-digits is not an accident; it
      // appears the matrix given in the pdf was obtained by inverting an original defined to 4
      // digit precision. Note that this may be important for high depth color, so should be
      // further investigated (NB!) to see if that 4-digit matrix is really standardized at 4
      // digits or if there is missing precision at play here.

      float RL, GL, BL;

      if(a_uniformRep[0] <= 0.04045f) {
        RL = a_uniformRep[0] / 12.92f;
      } else {
        RL = pow((a_uniformRep[0] + 0.055f) / 1.055f, 2.4f); // NB: pow is slow
      }

      if(a_uniformRep[1] <= 0.04045f) {
        GL = a_uniformRep[1] / 12.92f;
      } else {
        GL = pow((a_uniformRep[1] + 0.055f) / 1.055f, 2.4f); // NB: pow is slow
      }

      if(a_uniformRep[2] <= 0.04045f) {
        BL = a_uniformRep[2] / 12.92f;
      } else {
        BL = pow((a_uniformRep[2] + 0.055f) / 1.055f, 2.4f); // NB: pow is slow
      }

      a_fs[0] = 0.4124f*RL + 0.3576f*GL + 0.1805f*BL;
      a_fs[1] = 0.2126f*RL + 0.7152f*GL + 0.0722f*BL;
      a_fs[2] = 0.0193f*RL + 0.1192f*GL + 0.9505f*BL;
    }

    void
    fundamentalToNrml(
      const std::array<float, 3> &a_fs,
      std::array<float, 3> &a_uniformRep
    ) const {
      // This function was actually coded first.
      float RL = std::clamp<float>(3.2406255f*a_fs[0] - 1.537208f*a_fs[1] - 0.4986286f*a_fs[2], 0.0f, 1.0f);
      float GL = std::clamp<float>(-0.9689307f*a_fs[0] + 1.8757561f*a_fs[1] + 0.0415175f*a_fs[2], 0.0f, 1.0f);
      float BL = std::clamp<float>(0.0557101f*a_fs[0] - 0.2040211f*a_fs[1] + 1.0569959f*a_fs[2], 0.0f, 1.0f);

      // Standardized gamma correction
      if(RL <= 0.0031308) {
        a_uniformRep[0] = 12.92f * RL;
      } else {
        a_uniformRep[0] = 1.055f * pow(RL, 1.0f/2.4f) - 0.055f; // NB: pow is slow
      }

      if(GL <= 0.0031308) {
        a_uniformRep[1] = 12.92f * GL;
      } else {
        a_uniformRep[1] = 1.055f * pow(GL, 1.0f/2.4f) - 0.055f; // NB: pow is slow
      }

      if(BL <= 0.0031308) {
        a_uniformRep[2] = 12.92f * BL;
      } else {
        a_uniformRep[2] = 1.055f * pow(BL, 1.0f/2.4f) - 0.055f; // NB: pow is slow
      }
    }
  };
}

#endif
