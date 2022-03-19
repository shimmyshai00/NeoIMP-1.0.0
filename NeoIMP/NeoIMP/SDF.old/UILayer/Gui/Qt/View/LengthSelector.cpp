/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthSelector.cpp
 * PURPOSE: Defines the LengthSelector class.
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

#include <LengthSelector.hpp>

#include <Metrics/LengthUnits.hpp>
#include <Metrics/ResolutionUnits.hpp>

#include <Metrics/makeLength.hpp>
#include <Metrics/makeResolution.hpp>

#include <Metrics/lengthIn.hpp>
#include <Metrics/resolutionIn.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  LengthSelector::LengthSelector(float length, Metrics::LengthUnit unit, float resolutionPpi)
    : m_lengthInPixels(length),
      m_lengthUnit(unit),
      m_resolution(Metrics::makeResolution(resolutionPpi, Metrics::RESOLUTION_UNIT_PPI))
  {
    if(unit != Metrics::LENGTH_UNIT_PIXEL) {
      m_lengthInPhysUnits = Metrics::makeLength(length, unit);
      m_lengthInPixels = m_lengthInPhysUnits * m_resolution;
    } else {
      m_lengthInPhysUnits = m_lengthInPixels / m_resolution;
    }
  }

  float
  LengthSelector::getQuantity() const {
    if(m_lengthUnit == Metrics::LENGTH_UNIT_PIXEL) {
      return m_lengthInPixels.value();
    } else {
      return Metrics::lengthIn(m_lengthInPhysUnits, m_lengthUnit);
    }
  }

  Metrics::LengthUnit
  LengthSelector::getUnit() const {
    return m_lengthUnit;
  }

  float
  LengthSelector::getQuantityIn(Metrics::LengthUnit unit) const {
    if(unit == Metrics::LENGTH_UNIT_PIXEL) {
      return m_lengthInPixels.value();
    } else {
      return Metrics::lengthIn(m_lengthInPhysUnits, unit);
    }
  }

  float
  LengthSelector::getResolutionPpi() const {
    return Metrics::resolutionIn(m_resolution, Metrics::RESOLUTION_UNIT_PPI);
  }

  void
  LengthSelector::setQuantity(float quantity) {
    if(m_lengthUnit == Metrics::LENGTH_UNIT_PIXEL) {
      m_lengthInPixels = Metrics::dimensionless_quantity(quantity);
    } else {
      m_lengthInPhysUnits = Metrics::makeLength(quantity, m_lengthUnit);
      m_lengthInPixels = m_lengthInPhysUnits * m_resolution;
    }
  }

  void
  LengthSelector::setUnit(Metrics::LengthUnit unit) {
    m_lengthUnit = unit;
  }

  void
  LengthSelector::setResolutionPpi(float resolutionPpi) {
    m_resolution = Metrics::makeResolution(resolutionPpi, Metrics::RESOLUTION_UNIT_PPI);
    if(m_lengthUnit != Metrics::LENGTH_UNIT_PIXEL) {
      m_lengthInPixels = m_lengthInPhysUnits * m_resolution;
    } else {
      m_lengthInPhysUnits = m_lengthInPixels / m_resolution;
    }
  }
}
