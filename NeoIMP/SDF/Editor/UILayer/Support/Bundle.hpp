#ifndef SDF_EDITOR_UILAYER_SUPPORT_BUNDLE_HPP
#define SDF_EDITOR_UILAYER_SUPPORT_BUNDLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Bundle.hpp
 * PURPOSE: Defines the Bundle class.
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

#include "../../../Common/Handle.hpp"

#include <string>
#include <map>

namespace SDF::Editor::UILayer::Support {
  // Class:      Bundle
  // Purpose:    Bundles together a variety of arguments of different types.
  // Parameters: None.
  class Bundle {
  public:
    // Function:   addInt
    // Purpose:    Add an integer value to the bundle.
    // Parameters: key - The key for the new integer value.
    //             val - The value to give it.
    // Returns:    None.
    void
    addInt(std::string key, int val);

    // Function:   addLong
    // Purpose:    Add a long value to the bundle.
    // Parameters: key - The key for the new long value.
    //             val - The value to give it.
    // Returns:    None.
    void
    addLong(std::string key, long val);

    // Function:   addString
    // Purpose:    Add a string value to the bundle.
    // Parameters: key - The key for the new string value.
    //             val - The value to give it.
    // Returns:    None.
    void
    addString(std::string key, std::string val);

    // Function:   addHandle
    // Purpose:    Adds a handle to the bundle.
    // Parameters: key - The key for the new handle value.
    //             val - The value to give it.
    // Returns:    None.
    void
    addHandle(std::string key, Common::Handle val);

    // Function:   getInt
    // Purpose;    Get an integer value from the bundle.
    // Parameters: key - The key for the integer value to get.
    //             def - The default if it is not found in the bundle.
    // Reutrns:    The acquired integer value, or the default if not found.
    int
    getInt(std::string key, int def);

    // Function:   getLong
    // Purpose;    Get a long value from the bundle.
    // Parameters: key - The key for the long value to get.
    //             def - The default if it is not found in the bundle.
    // Reutrns:    The acquired long value, or the default if not found.
    long
    getLong(std::string key, long def);

    // Function:   getString
    // Purpose;    Get a string value from the bundle.
    // Parameters: key - The key for the string value to get.
    //             def - The default if it is not found in the bundle.
    // Reutrns:    The acquired string value, or the default if not found.
    std::string
    getString(std::string key, std::string def);

    // Function:   getHandle
    // Purpose;    Get a handle value from the bundle.
    // Parameters: key - The key for the handle value to get.
    //             def - The default if it is not found in the bundle.
    // Reutrns:    The acquired handle value, or the default if not found.
    Common::Handle
    getHandle(std::string key, Common::Handle def);
  private:
    std::map<std::string, int> m_intMap;
    std::map<std::string, long> m_longMap;
    std::map<std::string, std::string> m_stringMap;
    std::map<std::string, Common::Handle> m_handleMap;
  };
}

#endif
