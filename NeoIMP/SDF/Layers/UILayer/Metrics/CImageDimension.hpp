#ifndef SDF_LAYERS_UILAYER_METRICS_CIMAGEDIMENSION_HPP
#define SDF_LAYERS_UILAYER_METRICS_CIMAGEDIMENSION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CImageDimension.hpp
 * PURPOSE: A class representing an image dimension.
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

#include <ELengthUnit.hpp>
#include <EResolutionUnit.hpp>

namespace SDF::Layers::UILayer::Metrics {
  class CImageDimension {
  public:
    CImageDimension(float pixels, float resolutionPpi);
    CImageDimension(float length, ELengthUnit lengthUnit, float resolutionPpi);
    CImageDimension(float length, ELengthUnit lengthUnit, float resolution, EResolutionUnit resolutionUnit);
    ~CImageDimension() {}

    float getLengthInUnits(ELengthUnit lengthUnit) const;
    float getResolutionInUnits(EResolutionUnit resolutionUnit) const;

    void setLength(float newLength, ELengthUnit lengthUnit);
    void setResolution(float newResolution, EResolutionUnit resolutionUnit);
  private:
    float m_lengthInPixels;
    float m_resolutionPpi;
  };
}

#endif
