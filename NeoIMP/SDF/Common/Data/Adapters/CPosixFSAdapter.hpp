#ifndef SDF_COMMON_DATA_ADAPTERS_CPOSIXFSADAPTER_HPP
#define SDF_COMMON_DATA_ADAPTERS_CPOSIXFSADAPTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CPosixFSAdapter.hpp
 * PURPOSE: Defines the CPosixFSAdapter class.
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

#include "IFilesystemAdapter.hpp"
#include "SFilesystemKey.hpp"

#include <fruit/fruit.h>
#include <string>
#include <vector>

namespace SDF::Common::Data::Adapters {
  // Class:      CPosixFSAdapter
  // Purpose:    Adapter for file system implementation on POSIX-compatible operating systems (e.g.
  //             GNU/Linux, BSD, other *nix systems).
  // Parameters: None.
  class CPosixFSAdapter : public IFilesystemAdapter {
  public:
    INJECT(CPosixFSAdapter());

    bool
    exist(SFilesystemKey a_key);

    void
    create(SFilesystemKey a_key);

    void
    writeData(SFilesystemKey a_key, const std::vector<unsigned char> &a_data);

    void
    readData(SFilesystemKey a_key, std::vector<unsigned char> &a_destination);

    void
    erase(SFilesystemKey a_key);
  };
}

#endif
