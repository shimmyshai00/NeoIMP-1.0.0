#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IIMAGEDATAVISITOR_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IIMAGEDATAVISITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageDataVisitor.hpp
 * PURPOSE: Defines the IImageDataVisitor interface.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IDomainObject.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageImpl.hpp>

#include <SDF/ModelLayer/Math/Rect.hpp>

namespace SDF::ModelLayer::Services::AbstractDomain {
  // Class:      IImageDataVisitor
  // Purpose:    Defines a visitor interface for visiting the underlying image implementation data. Used to make use of
  //             3rd-party algorithms and/or for maximally efficient access to image data with no pre-processing. The
  //             recommended way to implement new core algorithms; NOT recommended for use outside of such!
  // Parameters: None.
  class IImageDataVisitor : public IDomainObject<IImageDataVisitor> {
  public:
    virtual ~IImageDataVisitor() = default;

    // Visitation methods for each implementation type.
    virtual void
    visitGilRegion(Math::Rect<std::size_t> rect, Defs::GilRegionType &gilRegion) = 0;
  };
}

#endif
