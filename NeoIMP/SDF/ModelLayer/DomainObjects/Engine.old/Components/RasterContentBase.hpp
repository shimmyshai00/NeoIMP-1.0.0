#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_RASTERCONTENTBASE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_RASTERCONTENTBASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RasterContentBase.hpp
 * PURPOSE: Defines the RasterContentBase class.
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

#include "IComponent.hpp"
#include "EType.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Components {
  // Class:      RasterContent
  // Purpose:    Defines a base for raster content components.
  // Parameters: ImplSpecT - The implementation traits type.
  template<class ImplSpecT>
  class RasterContent : public IComponent<ImplSpecT> {
  public:
    static const EType c_type = COMPONENT_RASTER_CONTENT;
  public:
    virtual ~RasterContent() = default;

    EType
    getType() const {
      return c_type;
    }

    // Function:   getIntrinsicRect
    // Purpose:    Gets the intrinsic bounding rectangle of the content.
    // Parameters: None.
    // Returns:    The content's intrinsic (no transformations) bounding rectangle.
    virtual ImageRect
    getIntrinsicRect() const = 0;
  };
}

#endif
