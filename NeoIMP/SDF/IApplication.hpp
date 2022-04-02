#ifndef SDF_IAPPLICATION_HPP
#define SDF_IAPPLICATION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IApplication.hpp
 * PURPOSE: Defines the IApplication interface.
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

namespace SDF {
  // Class:      IApplication
  // Purpose:    Defines the interface for the top-level application object. Different UI packages
  //             (Qt, wxWidgets, etc.) may require their own special initialization, thus we may
  //             need a different application object for each.
  // Parameters: None.
  class IApplication {
  public:
    virtual ~IApplication() = default;

    // Function:   exec
    // Purpose:    Execute the application.
    // Parameters: argc - Same as the parameter passed to main().
    //             argv - Same as the parameter passed to main().
    // Returns:    The program exit code.
    virtual int
    exec(int argc, char **argv) = 0;
  };
}

#endif
