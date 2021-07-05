#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_FACTORIES_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_FACTORIES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factories.hpp
 * PURPOSE: Defines factory classes for algorithms.
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

#include <SDF/Interfaces/IFactory.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IImageDataVisitor;
    class IRenderBuffer;
  }

  namespace DomainObjects::Algorithms {
    // Class:      RendererFactory
    // Purpose:    Creates a new renderer object.
    // Parameters: None.
    class RendererFactory : public Interfaces::IFactory<Services::AbstractDomain::IImageDataVisitor,
                                                        Services::AbstractDomain::IRenderBuffer *
                                                       >
    {
    public:
      INJECT(RendererFactory());

      std::unique_ptr<Services::AbstractDomain::IImageDataVisitor>
      create(Services::AbstractDomain::IRenderBuffer *buffer);
    };
  }
}

#endif
