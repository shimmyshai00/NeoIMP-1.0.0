/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionSelector.cpp
 * PURPOSE: Defines the ResolutionSelector class.
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

#include <ResolutionSelector.hpp>

#include <Metrics/makeResolution.hpp>
#include <Metrics/resolutionIn.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  ResolutionSelector::ResolutionSelector(float resolution, Metrics::ResolutionUnit unit)
    : m_resolution(Metrics::makeResolution(resolution, unit)),
      m_resolutionUnit(unit)
  {
  }

  float
  ResolutionSelector::getQuantity() const {
    return Metrics::resolutionIn(m_resolution, m_resolutionUnit);
  }

  Metrics::ResolutionUnit
  ResolutionSelector::getUnit() const {
    return m_resolutionUnit;
  }

  float
  ResolutionSelector::getQuantityIn(Metrics::ResolutionUnit unit) const {
    return Metrics::resolutionIn(m_resolution, unit);
  }

  void
  ResolutionSelector::setQuantity(float quantity) {
    m_resolution = Metrics::makeResolution(quantity, m_resolutionUnit);
  }

  void
  ResolutionSelector::setUnit(Metrics::ResolutionUnit unit) {
    m_resolutionUnit = unit;
  }
}
