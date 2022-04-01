#ifndef SDF_COMMON_DATA_ADAPTERS_POSIXFSADAPTER_HPP
#define SDF_COMMON_DATA_ADAPTERS_POSIXFSADAPTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PosixFSAdapter.hpp
 * PURPOSE: Defines the PosixFSAdapter class.
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
#include "FilesystemKey.hpp"

#include <fruit/fruit.h>
#include <string>
#include <vector>

namespace SDF::Common::Data::Adapters {
  // Class:      PosixFSAdapter
  // Purpose:    Adapter for file system implementation on POSIX-compatible operating systems (e.g.
  //             GNU/Linux, BSD, other *nix systems).
  // Parameters: None.
  class PosixFSAdapter : public IFilesystemAdapter {
  public:
    INJECT(PosixFSAdapter());

    bool
    exist(FilesystemKey a_key);

    void
    create(FilesystemKey a_key);

    void
    writeData(FilesystemKey a_key, const std::vector<unsigned char> &a_data);

    void
    readData(FilesystemKey a_key, std::vector<unsigned char> &a_destination);

    void
    erase(FilesystemKey a_key);
  };
}

#endif
