/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Bundle.hpp
 * PURPOSE: Implements the Bundle class.
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

#include "Bundle.hpp"

namespace SDF::UILayer::Support {
  void
  Bundle::addInt(std::string key, int val) {
    m_intMap[key] = val;
  }

  void
  Bundle::addLong(std::string key, long val) {
    m_longMap[key] = val;
  }

  void
  Bundle::addString(std::string key, std::string val) {
    m_stringMap[key] = val;
  }

  void
  Bundle::addHandle(std::string key, Common::Handle val) {
    m_handleMap[key] = val;
  }

  int
  Bundle::getInt(std::string key, int def) {
    if(m_intMap.find(key) == m_intMap.end()) {
      return def;
    } else {
      return m_intMap[key];
    }
  }

  long
  Bundle::getLong(std::string key, long def) {
    if(m_longMap.find(key) == m_longMap.end()) {
      return def;
    } else {
      return m_longMap[key];
    }
  }

  std::string
  Bundle::getString(std::string key, std::string def) {
    if(m_stringMap.find(key) == m_stringMap.end()) {
      return def;
    } else {
      return m_stringMap[key];
    }
  }

  Common::Handle
  Bundle::getHandle(std::string key, Common::Handle def) {
    if(m_handleMap.find(key) == m_handleMap.end()) {
      return def;
    } else {
      return m_handleMap[key];
    }
  }
}
