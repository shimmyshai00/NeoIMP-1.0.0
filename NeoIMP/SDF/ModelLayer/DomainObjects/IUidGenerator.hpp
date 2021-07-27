#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IUIDGENERATOR_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IUIDGENERATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IUidGenerator.hpp
 * PURPOSE: Defines the IUidGenerator interface.
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

namespace SDF::ModelLayer::DomainObjects {
  // Class:      IUidGenerator
  // Purpose:    Defines an interface for getting unique ID values (UIDs) for domain objects.
  // Parameters: UidValT - The type of UID value to generate.
  template<class UidValT>
  class IUidGenerator {
  public:
    virtual ~IUidGenerator() = default;

    // Function:   get
    // Purpose:    Get a new UID from the generator.
    // Parameters: None.
    // Returns:    The new UID value.
    virtual UidValT
    get() = 0;
  };
}

#endif
