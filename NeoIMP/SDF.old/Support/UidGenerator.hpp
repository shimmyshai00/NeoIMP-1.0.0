#ifndef SDF_SUPPORT_UIDGENERATOR_HPP
#define SDF_SUPPORT_UIDGENERATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UidGenerator.hpp
 * PURPOSE: Defines the UidGenerator template.
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

#include <SDF/Interfaces/IGenerator.hpp>

#include <fruit/fruit.h>

namespace SDF::Support {
  // Class:      UidGenerator
  // Purpose:    Defines an interface for generating unique IDs for objects.
  // Parameters: UidValT - The type of UID value to use.
  template<class UidValT>
  class UidGenerator : public Interfaces::IGenerator<UidValT> {
  public:
    INJECT(UidGenerator());

    UidValT
    get();
  private:
    UidValT m_nextUid;
  };
}

#include "SDF/Support/UidGenerator.tpp"

#endif
