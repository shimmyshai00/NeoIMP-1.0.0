#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_ISETVIEWCOORDINATESSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_ISETVIEWCOORDINATESSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISetViewCoordinatesService.hpp
 * PURPOSE: Defines the ISetViewCoordinatesService interface.
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
  // Class:      ISetViewCoordinatesService
  // Purpose:    Defines a service interface to set the viewing coordinates on image documents.
  // Parameters: None.
  class ISetViewCoordinatesService {
  public:
    virtual ~ISetViewCoordinatesService() = default;
    
    virtual void
    setViewingPointMagnification(Common::Handle imageHandle, float mag) = 0;

    virtual void
    setViewingPointPos(Common::Handle imageHandle, float x, float y) = 0;

    virtual void
    setViewingPoint(Common::Handle imageHandle, float x, float y, float mag) = 0;
  };
}

#endif
