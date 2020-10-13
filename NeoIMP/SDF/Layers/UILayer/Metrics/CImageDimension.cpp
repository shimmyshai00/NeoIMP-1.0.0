/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CImageDimension.hpp
 * PURPOSE: Implementation of the CImageDimension class.
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

#include <CImageDimension.hpp>
#include <ConversionFactors.hpp>

namespace SDF::Layers::UILayer::Metrics {
  // Helper functions.
  float convertLengthToPixels(float length, ELengthUnit lengthUnit, float resolutionPpi) {
    if(lengthUnit == UNIT_PIXEL) {
      // Already in pixels.
      return length;
    } else {
      // First, convert to inches. Then, use the ppi to get the length in pixels.
      return ((length * 100.0f) / g_lengthConversionFactors[lengthUnit]) * resolutionPpi;
    }
  }

  float convertPixelsToLength(float pixels, float resolutionPpi, ELengthUnit lengthUnit) {
    if(lengthUnit == UNIT_PIXEL) {
      // Already in pixels.
      return pixels;
    } else {
      // First, convert to inches using the ppi value. Then convert to the desired units.
      return ((pixels / resolutionPpi) * 100.0f) * g_lengthConversionFactors[lengthUnit];
    }
  }

  float convertResolutionUnits(float resolution, EResolutionUnit resolutionUnit, EResolutionUnit desiredUnit) {
    if(resolutionUnit == desiredUnit) {
      // No conversion necessary.
      return resolution;
    } else {
      // Do the conversion.
      return resolution * (g_resolutionConversionFactors[resolutionUnit] / g_resolutionConversionFactors[desiredUnit]);
    }
  }

  float convertResolutionToPpi(float resolution, EResolutionUnit resolutionUnit) {
    return convertResolutionUnits(resolution, resolutionUnit, UNIT_PIXELS_PER_INCH);
  }
}

namespace SDF::Layers::UILayer::Metrics {
  CImageDimension::CImageDimension(float pixels, float resolutionPpi) :
  m_lengthInPixels(pixels),
  m_resolutionPpi(resolutionPpi)
  {
  }

  CImageDimension::CImageDimension(float length, ELengthUnit lengthUnit, float resolutionPpi) :
  m_lengthInPixels(convertLengthToPixels(length, lengthUnit, resolutionPpi)),
  m_resolutionPpi(resolutionPpi)
  {
  }

  CImageDimension::CImageDimension(float length, ELengthUnit lengthUnit,
    float resolution, EResolutionUnit resolutionUnit) :
    m_lengthInPixels(convertLengthToPixels(length, lengthUnit, convertResolutionToPpi(resolution, resolutionUnit))),
    m_resolutionPpi(convertResolutionToPpi(resolution, resolutionUnit))
    {
    }

  float CImageDimension::getLengthInUnits(ELengthUnit lengthUnit) const {
    return convertPixelsToLength(m_lengthInPixels, m_resolutionPpi, lengthUnit);
  }

  float CImageDimension::getResolutionInUnits(EResolutionUnit resolutionUnit) const {
    return convertResolutionUnits(m_resolutionPpi, UNIT_PIXELS_PER_INCH, resolutionUnit);
  }

  void CImageDimension::setLength(float newLength, ELengthUnit lengthUnit) {
    m_lengthInPixels = convertLengthToPixels(newLength, lengthUnit, m_resolutionPpi);
  }

  void CImageDimension::setResolution(float newResolution, EResolutionUnit resolutionUnit) {
    m_resolutionPpi = convertResolutionUnits(newResolution, resolutionUnit, UNIT_PIXELS_PER_INCH);
  }
}
