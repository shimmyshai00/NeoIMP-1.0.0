#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_ILAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_ILAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ILayer.hpp
 * PURPOSE: Defines the ILayer interface.
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

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      ILayer
  // Purpose:    Defines an interface for the different kinds of image layer.
  // Parameters: ImplSpecT - The image implementation traits.
  template<class ImplSpecT>
  class ILayer {
  public:
    virtual ~ILayer() = default;

    // Function:   getType
    // Purpose:    Gets the type of this layer.
    // Parameters: None.
    // Returns:    The layer type.
    virtual ELayerType
    getType() const = 0;
    
    // Function:   getIntrinsicRect
    // Purpose:    Gets the intrinsic (untransformed) bounding rectangle of this layer.
    // Parameters: None.
    // Returns:    The untransformed rectangle.
    virtual ImageRect
    getIntrinsicRect() const = 0;

    // Function:   getEffectiveRect
    // Purpose:    Gets the transformed bounding rectangle of the layer.
    // Parameters: None.
    // Returns:    The actual bounding rectangle on the image.
    virtual ImageRect
    getEffectiveRect() const = 0;
  };
}

#endif
