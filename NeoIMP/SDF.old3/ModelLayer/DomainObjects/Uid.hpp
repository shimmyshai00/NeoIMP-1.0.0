#ifndef SDF_MODELLAYER_DOMAINOBJECTS_UID_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_UID_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Uid.hpp
 * PURPOSE: Defines the Uid class.
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

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects {
  // Class:      Uid
  // Purpose:    Provides unique identifiers for all domain objects.
  // Parameters: None.
  class Uid {
  public:
    // Singleton method.
    static Uid next() {
      static unsigned long long nextCounter = 0L;
      return Uid(++nextCounter);
    }

    // Convert to handle.
    unsigned int handlify() const {
      return m_uid & 0xFFFFFFFFULL;
    }

    // Comparison operators.
    friend bool operator==(const Uid lhs, const Uid rhs) {
      return lhs.m_uid == rhs.m_uid;
    }

    friend bool operator!=(const Uid lhs, const Uid rhs) {
      return !(lhs == rhs);
    }

    friend bool operator<(const Uid lhs, const Uid rhs) {
      // For associative containers.
      return lhs.m_uid < rhs.m_uid;
    }
  private:
    unsigned long long m_uid;

    Uid(unsigned long long uid)
      : m_uid(uid)
    {}
  };
}

#endif
