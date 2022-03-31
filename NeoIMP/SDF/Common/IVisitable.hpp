#ifndef SDF_COMMON_IVISITABLE_HPP
#define SDF_COMMON_IVISITABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IVisitable.hpp
 * PURPOSE: Defines the IVisitable interface.
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

namespace SDF::Common {
  // Class:      IVisitable
  // Purpose:    Defines an interface for visitable objects.
  // Parameters: VisitorT - The type of visitor to accept.
  template<class VisitorT>
  class IVisitable {
  public:
    virtual ~IVisitable() = default;

    // Function:   accept
    // Purpose:    Accepts a visitor into the object.
    // Parameters: visitor - The visitor to accept.
    // Returns:    None.
    virtual void
    accept(VisitorT &visitor) = 0;

    virtual void
    accept(VisitorT &visitor) const = 0;
  };
}

#endif
