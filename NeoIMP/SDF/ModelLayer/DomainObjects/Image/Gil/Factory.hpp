#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_FACTORY_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_FACTORY_HPP

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

#include <SDF/ModelLayer/Services/AbstractDomain/DocumentSpec.hpp>

#include <fruit/fruit.h>

#include <memory>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IImage;
  }

  namespace DomainObjects::Image::Gil {
    // Class:      Factory
    // Purpose:    Create new Boost.GIL-implemented documents.
    // Parameters: None.
    class Factory : public Interfaces::IFactory<Services::AbstractDomain::IImage,
                                                Services::AbstractDomain::DocumentSpec
                                               >
    {
    public:
      INJECT(Factory());

      std::unique_ptr<Services::AbstractDomain::IImage>
      create(Services::AbstractDomain::DocumentSpec spec);
    private:
      int m_nextUid;
    };
  }
}

#endif
