#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_CREATE_IGETMEMORYREQUIREMENTSSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_CREATE_IGETMEMORYREQUIREMENTSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetMemoryRequirementsService.hpp
 * PURPOSE: Defines the IGetMemoryRequirementsService interface.
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

#include "../Defs/ImageSpec.hpp"

#include <cstddef>

namespace SDF::Editor::UILayer::AbstractModel::Create {
  // Class:      IGetMemoryRequirementsService
  // Purpose:    Defines a service interface to get memory requirements for a proposed document.
  // Parameters: None.
  class IGetMemoryRequirementsService {
  public:
    virtual ~IGetMemoryRequirementsService() = default;

    // Function:   getMemoryRequiredForOneLayer
    // Purpose:    Calculates the memory required for a single-layer document of a given spec.
    // Parameters: spec - The document spec to use.
    // Returns:    The memory requirement in bytes.
    virtual std::size_t
    getMemoryRequiredForOneLayer(const Defs::ImageSpec &spec) const = 0;
  };
}

#endif
