#ifndef SDF_MODELLAYER_DOMAINOBJECTS_RENDERPARAM_FACTORY_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_RENDERPARAM_FACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.hpp
 * PURPOSE: Defines the Factory class.
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
#include <SDF/Interfaces/IGenerator.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IDocumentViewParams;
  }

  namespace DomainObjects::RenderParam {
    // Class:      CenterMagViewportFactory
    // Purpose:    Creates a new viewport object from center-mag coordinates.
    // Parameters: None.
    class ViewportFactory : public Interfaces::IFactory<Services::AbstractDomain::IDocumentViewParams,
                                                        float,
                                                        float,
                                                        float
                                                       >
    {
    public:
      INJECT(ViewportFactory(Interfaces::IGenerator<int> *uidGenerator));

      std::unique_ptr<Services::AbstractDomain::IDocumentViewParams>
      create(float centerX,
             float centerY,
             float magnification
            );
    private:
      Interfaces::IGenerator<int> *m_uidGenerator;
    };
  }
}

#endif
