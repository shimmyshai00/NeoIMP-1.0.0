#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_IADDVIEWSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_IADDVIEWSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IAddViewService.hpp
 * PURPOSE: Defines the IAddViewService interface.
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

namespace SDF::Editor::UILayer::AbstractModel::Viewing {
  // Class:      IAddViewService
  // Purpose:    Defines a service interface to add view parameters to a document.
  // Parameters: None.
  class IAddViewService {
  public:
    virtual ~IAddViewService() = default;

    // Function:   addView
    // Purpose:    Creates a new set of view parameters for an image document. These parameters are
    //             defined in terms of an "anchor point" which has a position and magnification. The
    //             precise interpretation of this anchor point depends on how the UI chooses to use
    //             it.
    // Parameters: imageHandle - The handle of the image document.
    //             anchorX, anchorY - The location of the point on which to anchor the view.
    //             anchorMag - The magnification or zoom into the anchor point.
    // Returns:    A handle to the newly created view parameters.
    virtual Common::Handle
    addView(Common::Handle imageHandle, float anchorX, float anchorY, float anchorMag) = 0;
  };
}

#endif
