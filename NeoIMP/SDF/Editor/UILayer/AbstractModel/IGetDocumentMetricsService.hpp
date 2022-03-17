#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_IGETDOCUMENTMETRICSSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_IGETDOCUMENTMETRICSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentMetricsService.hpp
 * PURPOSE: Defines the IGetDocumentMetricsService interface.
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

#include "../../../Common/Handle.hpp"
#include "Defs/ELengthUnit.hpp"

namespace SDF::Editor::UILayer::AbstractModel {
  // Class:      IGetDocumentMetricsService
  // Purpose:    Defines the interface for an MVC service to obtain the size of an image.
  // Parameters: None.
  class IGetDocumentMetricsService {
  public:
    virtual ~IGetDocumentMetricsService() = default;

    // Function:   getDocumentWidth
    // Purpose:    Get the width of an image document.
    // Parameters: documentHandle - The handle to the document.
    //             inUnit - The unit to get the width in.
    // Returns:    The width in this unit.
    virtual float
    getDocumentWidth(Common::Handle documentHandle, Defs::ELengthUnit inUnit) = 0;

    // Function:   getDocumentHeight
    // Purpose:    Get the height of an image document.
    // Parameters: documentHandle - The handle to the document.
    //             inUnit - The unit to get the width in.
    // Returns:    The width in this unit.
    virtual float
    getDocumentHeight(Common::Handle documentHandle, Defs::ELengthUnit inUnit) = 0;
  };
}

#endif
