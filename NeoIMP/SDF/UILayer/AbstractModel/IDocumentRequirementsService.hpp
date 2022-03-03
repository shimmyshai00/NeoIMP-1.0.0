#ifndef SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTREQUIREMENTSSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTREQUIREMENTSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentRequirementsService.hpp
 * PURPOSE: Defines the IDocumentRequirementsService interface.
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

#include "Defs/ImageSpec.hpp"

#include <cstddef>

namespace SDF::UILayer::AbstractModel {
  // Class:      IDocumentRequirementsService
  // Purpose:    Defines the interface for an MVC service to obtain things like memory and disk
  //             storage or other requirements for a document before creating it.
  // Parameters: None.
  class IDocumentRequirementsService {
  public:
    virtual ~IDocumentRequirementsService() = default;

    // Function:   getMemoryRequiredForOneLayer
    // Purpose:    Get the memory required (in bytes) for a single layer of a document.
    // Parameters: spec - The document spec to use.
    // Returns:    The memory required for this spec, in bytes.
    virtual std::size_t
    getMemoryRequiredForOneLayer(Defs::ImageSpec spec) = 0;
  };
}

#endif
