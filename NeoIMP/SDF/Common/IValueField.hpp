#ifndef SDF_COMMON_IVALUEFIELD_HPP
#define SDF_COMMON_IVALUEFIELD_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IValueField.hpp
 * PURPOSE: Defines the IValueField interface.
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

#include "IGettable.hpp"
#include "ISettable.hpp"
#include "IListenable.hpp"

namespace SDF::Common {
  // Class:      IValueField
  // Purpose:    Provides a value-holding object with segregated interfaces for accessing, mutating,
  //             and listening.
  // Parameters: ValueT - The value that the user can get.
  template<class ValueT>
  class IValueField : public IGettable<ValueT>,
                      public ISettable<ValueT>,
                      public IListenable<ValueT>
  {
  public:
    virtual ~IValueField() = default;
  };
}

#endif
