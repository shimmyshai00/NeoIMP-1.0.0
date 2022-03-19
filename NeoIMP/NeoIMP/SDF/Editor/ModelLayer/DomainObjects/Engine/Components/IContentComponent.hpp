#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_ICONTENTCOMPONENT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_ICONTENTCOMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IContentComponent.hpp
 * PURPOSE: Defines the IContentComponent interface.
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

#include "../Dimensions.hpp"
#include "IComponent.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Components {
  // Class:      IContentComponent
  // Purpose:    Defines the base class for image content components. This defines all
  //             implementation-independent details for those components.
  // Parameters: ImplSpecT - The implementation traits type.
  template<class ImplSpecT>
  class IContentComponent : public IComponent<ImplSpecT> {
  public:
    virtual ~IContentComponent() = default;

    // Function:   getIntrinsicRect
    // Purpose:    Obtains the intrinsic, i.e. non-transformed, bounding rectangle of this
    //             component's content. Note that transforms are supplied by other components, so
    //             we can not evaluate them here.
    // Parameters: None.
    // Returns:    The component's intrinsic rectangle.
    virtual ImageRect
    getIntrinsicRect() const = 0;
  };
}

#endif
