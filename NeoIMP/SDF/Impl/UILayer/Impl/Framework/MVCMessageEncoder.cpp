/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCMessageEncoder.cpp
 * PURPOSE: A simple method to encode a bit of extra information into inter-controller pub/sub messages. These messages
 *          are not meant to convey a lot of information (otherwise we would use the Observer system in some way), but
 *          rather just to notify views and controllers they need to pull data from the model layer. However, sometimes
 *          a handle or other such simple datum will be required along with the specification of what to fetch.
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

#include <MVCMessageEncoder.hpp>

#include <vector>
#include <cstring>
#include <exception>

namespace SDF::Impl::UILayer::Impl::Framework {
  std::string encodeExtra(std::string prefix, int val) {
    return prefix + ":" + std::to_string(val);
  }

  std::pair<std::string, int> decodeExtra(std::string message) {
    std::string tokenStr(message);
    std::vector<std::string> tokens;

    for(auto token = strtok(&tokenStr[0], ":"); token != NULL; token = strtok(NULL, ":")) {
      tokens.push_back(token);
    }

    if(tokens.size() == 2) {
      try {
        return std::pair<std::string, int>(tokens[0], std::stoi(tokens[1]));
      } catch(std::exception &e) {
        return std::pair<std::string, int>(tokens[0], -1);
      }
    } else if(tokens.size() == 1) {
      return std::pair<std::string, int>(tokens[0], -1);
    } else {
      return std::pair<std::string, int>(":ERROR:", -1);
    }
  }
}
