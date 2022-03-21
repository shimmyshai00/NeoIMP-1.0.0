#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_METRICS_IGETDOCUMENTDIMENSIONSSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_METRICS_IGETDOCUMENTDIMENSIONSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentDimensionsService.hpp
 * PURPOSE: Defines the IGetDocumentDimensionsService interface.
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

#include "../../../../Common/Handle.hpp"
#include "../Defs/IUnitConvertible.hpp"
#include "../Defs/ELengthUnit.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::Metrics {
  // Class:      IGetDocumentDimensionsService
  // Purpose:    Defines a service interface to get the dimensions of a document.
  // Parameters: None.
  class IGetDocumentDimensionsService {
  public:
    virtual ~IGetDocumentDimensionsService() = default;

    // Function:         getDocumentWidth
    // Purpose:          Gets the width of a document.
    // Parameters:       documentHandle - The handle of the document to get the width of.
    //                   inUnit - The unit to get the width in.
    // Returns:          The width of the document in the given unit.
    // Throws (non-bug): DocumentNotFoundException
    //                   InvalidUnitException
    virtual float
    getDocumentWidth(
      Common::Handle documentHandle,
      UILayer::AbstractModel::Defs::ELengthUnit inUnit
    ) const = 0;

    // Function:         getDocumentHeight
    // Purpose:          Gets the height of a document.
    // Parameters:       documentHandle - The handle of the document to get the height of.
    //                   inUnit - The unit to get the height in.
    // Returns:          The height of the document in the given unit.
    // Throws (non-bug): DocumentNotFoundException
    //                   InvalidUnitException
    virtual float
    getDocumentHeight(
      Common::Handle documentHandle,
      UILayer::AbstractModel::Defs::ELengthUnit inUnit
    ) const = 0;
  };
}

#endif
