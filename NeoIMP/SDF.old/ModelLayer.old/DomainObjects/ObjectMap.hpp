#ifndef SDF_MODELLAYER_DOMAINOBJECTS_OBJECTMAP_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_OBJECTMAP_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ObjectMap.hpp
 * PURPOSE: Defines the ObjectMap template.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IObjectMap.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <map>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    template<class T>
    class IDomainObject;
  }

  namespace AbstractData {
    template<class T>
    class IRepository;
  }

  namespace DomainObjects {
    // Class:      ObjectMap
    // Purpose:    Maps between domain objects.
    // Parameters: T - The type of objects mapped from.
    //             U - The type of objects mapped to.
    template<class T, class U>
    class ObjectMap : public Services::AbstractDomain::IObjectMap<T, U> {
    public:
      INJECT(ObjectMap(AbstractData::IRepository<U> *valueRepository));

      void
      linkTo(Services::AbstractDomain::IDomainObject<T> *key, std::unique_ptr<U> value);

      void
      breakLink(Services::AbstractDomain::IDomainObject<T> *key);

      U *
      get(Services::AbstractDomain::IDomainObject<T> *key);
    private:
      std::map<int, int> m_idMap;
      AbstractData::IRepository<U> *m_valueRepository;
    };
  }
}

#include "SDF/ModelLayer/DomainObjects/ObjectMap.tpp"

#endif
