#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IDOCUMENTVIEWPARAMS_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IDOCUMENTVIEWPARAMS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentViewParams.hpp
 * PURPOSE: Defines the IDocumentViewParams interface.
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

namespace SDF::ModelLayer::Services::AbstractDomain {
  // Class:      IDocumentViewParams
  // Purpose:    Provides an interface to a domain object storing the viewport parameters for a document.
  // Parameters: None.
  class IDocumentViewParams : public IDomainObject<IDocumentViewParams> {
  public:
    virtual ~IDocumentViewParams() = default;

    // Function:   getCenterX
    // Purpose:    Get the center-X coordinate of the document viewport.
    // Parameters: None.
    // Returns:    The coordinate value.
    virtual float
    getCenterX() const = 0;

    // Function:   getCenterY
    // Purpose:    Get the center-Y coordinate of the document viewport.
    // Parameters: None.
    // Returns:    The coordinate value.
    virtual float
    getCenterY() const = 0;

    // Function:   getMagnification
    // Purpose:    Get the magnification factor of the document viewport.
    // Parameters: None.
    // Returns:    The magnification factor (dimensionless).
    virtual float
    getMagnification() const = 0;

    // Function:   setCenterX
    // Purpose:    Set the center-X coordinate of the document viewport.
    // Parameters: centerX - The new coordinate value.
    // Returns:    None.
    virtual void
    setCenterX(float centerX) = 0;

    // Function:   setCenterX
    // Purpose:    Set the center-Y coordinate of the document viewport.
    // Parameters: centerY - The new coordinate value.
    // Returns:    None.
    virtual void
    setCenterY(float centerY) = 0;

    // Function:   setMagnification
    // Purpose:    Set the magnification factor of the document viewport.
    // Parameters: magnif - The new magnification factor.
    // Returns:    None.
    virtual void
    setMagnification(float magnif) = 0;
  };
}

#endif
