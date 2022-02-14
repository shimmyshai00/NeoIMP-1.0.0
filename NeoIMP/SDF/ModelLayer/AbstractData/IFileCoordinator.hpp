#ifndef SDF_MODELLAYER_ABSTRACTDATA_IFILECOORDINATOR_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_IFILECOORDINATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IFileCoordinator.hpp
 * PURPOSE: Defines the IFileCoordinator interface.
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

#include "../../Common/Handle.hpp"

#include <string>

namespace SDF::ModelLayer::AbstractData {
  // Class:      IFileCoordinator
  // Purpose:    Coordinates between file specs and data-mapper UIDs.
  // Parameters: None.
  class IFileCoordinator {
  public:
    virtual ~IFileCoordinator() = default;

    // Function:   getFileUid
    // Purpose:    Get a UID corresponding to a given file spec.
    // Parameters: fileSpec - The file spec to get the UID for.
    // Returns:    The UID for this file spec.
    virtual Common::Handle
    getFileUid(std::string fileSpec) = 0;
  };
}

#endif
