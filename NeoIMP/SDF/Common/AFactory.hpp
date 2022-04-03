#ifndef SDF_COMMON_AFACTORY_HPP
#define SDF_COMMON_AFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AFactory.hpp
 * PURPOSE: Defines the AFactory base class.
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

#include <memory>

namespace SDF::Common {
  // Interfaces based on return type
  template<class ObjT, class ... Args>
  class IFactoryP {
  public:
    virtual ~IFactoryP() = default;

    virtual ObjT *
    create(Args... a_args) = 0;
  };

  template<class ObjT, class ... Args>
  class IFactoryU {
  public:
    virtual ~IFactoryU() = default;

    virtual std::unique_ptr<ObjT>
    createU(Args... a_args) = 0;
  };

  template<class ObjT, class ... Args>
  class IFactoryS {
  public:
    virtual ~IFactoryS() = default;

    virtual std::shared_ptr<ObjT>
    createS(Args... a_args) = 0;
  };

  // Class:      AFactory
  // Purpose:    Defines a base class for objects which construct other objects.
  // Parameters: ObjT - The type of object constructed.
  //             Args - The arguments required for the construction.
  template<class ObjT, class ... Args>
  class AFactory : public IFactoryP<ObjT, Args...>,
                   public IFactoryU<ObjT, Args...>,
                   public IFactoryS<ObjT, Args...>
  {
  public:
    virtual ~AFactory() = default;

    // Function:   create
    // Purpose:    Create a new instance of the object.
    // Parameters: args - The arguments to use for the construction.
    // Returns:    A pointer to the new object.
    virtual ObjT *
    create(Args... as_args) = 0;

    std::unique_ptr<ObjT>
    createU(Args... as_args) { return std::unique_ptr<ObjT>(create(as_args...)); }

    std::shared_ptr<ObjT>
    createS(Args... as_args) { return std::shared_ptr<ObjT>(create(as_args...)); }
  };
}

#endif
