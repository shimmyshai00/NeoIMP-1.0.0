#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_IGETDOCUMENTCOLORFORMATSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_IGETDOCUMENTCOLORFORMATSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentColorFormatService.hpp
 * PURPOSE: Defines the IGetDocumentColorFormatService interface.
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
#include "../Defs/Color/ColorFormat.hpp"

namespace SDF::Editor::UILayer::AbstractModel::Color {
  // Class:      IGetDocumentColorFormatService
  // Purpose:    Defines a service interface to get the color format used by a document.
  // Parameters: None.
  class IGetDocumentColorFormatService {
  public:
    virtual ~IGetDocumentColorFormatService() = default;

    // Function:   getColorFormatOf
    // Purpose:    Gets the color format of an image document.
    // Parameters: documentHandle - The handle of the document to get the color model for.
    // Returns:    The document's color format.
    virtual Defs::Color::ColorFormat
    getColorFormatOf(Common::Handle a_documentHandle) const = 0;
  };
}

#endif
