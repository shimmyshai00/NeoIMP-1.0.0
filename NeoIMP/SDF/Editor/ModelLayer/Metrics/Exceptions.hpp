#ifndef SDF_EDITOR_MODELLAYER_METRICS_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_METRICS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines exceptions for the metrics subsystem.
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

#include "../../../Error/Exception.hpp"
#include "../../../Error/ModelException.hpp"

namespace SDF::Editor::ModelLayer::Metrics {
  struct InvalidLengthUnitException : public Error::LikelyBug<Error::ModelException> {
    int m_unitIdx;
    InvalidLengthUnitException(int unitIdx) : m_unitIdx(unitIdx) {
      whatPrintf("Tried to use a length unit with index '%d'. This does not correspond to a valid "
      "choice of measuring unit.", m_unitIdx);
    }
  };

  struct InvalidResolutionUnitException : public Error::LikelyBug<Error::ModelException> {
    int m_unitIdx;
    InvalidResolutionUnitException(int unitIdx) : m_unitIdx(unitIdx) {
      whatPrintf("Tried to use a resolution unit with index '%d'. This does not correspond to a "
      "valid choice of measuring unit.", m_unitIdx);
    }
  };
}

#endif
