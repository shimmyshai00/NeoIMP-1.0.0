#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_IGETDOCUMENTCOLORFORMATSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_IGETDOCUMENTCOLORFORMATSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentColorFormatService.hpp
 * PURPOSE: Defines the IGetDocumentColorFormatService interface
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
#include "../Defs/Color/EColorModel.hpp"
#include "../Defs/Color/EBitDepth.hpp"

#include <string>

namespace SDF::Editor::UILayer::AbstractModel::Color {
  // Class:      IGetDocumentColorFormatService
  // Purpose:    Defines a service interface to get the color format used by a document.
  // Parameters: None.
  class IGetDocumentColorFormatService {
  public:
    virtual ~IGetDocumentColorFormatService() = default;

    // Function:   getColorModelOf
    // Purpose:    Returns the color model used by a document.
    // Parameters: documentHandle - A handle to the document in question.
    // Returns:    The color model enum value for that document.
    virtual Defs::Color::EColorModel
    getColorModelOf(Common::Handle documentHandle) const = 0;

    // Function:   getBitDepthOf
    // Purpose:    Returns the bit depth used by a document.
    // Parameters: documentHandle - A handle to the document in question.
    // Returns:    The bit depth enum value for that document.
    virtual Defs::Color::EBitDepth
    getBitDepthOf(Common::Handle documentHandle) const = 0;
  };
}

#endif
