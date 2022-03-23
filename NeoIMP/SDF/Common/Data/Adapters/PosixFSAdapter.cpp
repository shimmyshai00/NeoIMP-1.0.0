/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PosixFSAdapter.cpp
 * PURPOSE: Implements the PosixFSAdapter class.
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

#include "PosixFSAdapter.hpp"

#include "../../../Error/DataException.hpp"

#include <sys/types.h>
#include <sys/stat.h>

namespace SDF::Common::Data::Adapters {
  PosixFSAdapter::PosixFSAdapter() {
  }

  bool
  PosixFSAdapter::exist(FilesystemKey key) {
    struct ::stat fs;
    if(::stat(key.m_fileSpec.c_str(), &fs) == -1) {
      if(errno == ENOENT) {
        return false;
      } else {
        throw Error::FilesystemException();
      }
    } else {
      // The *file* exists - check now if it has enough data to accommodate this offset and buffer
      // length.
      if(fs.st_size == 0) {
        // user only cares if the file exists
        return true;
      } else if(fs.st_size >= key.m_offset + key.m_length) {
        return true;
      } else {
        return false;
      }
    }
  }

  void
  PosixFSAdapter::create(FilesystemKey key) {
    throw "NOT YET IMPLEMENTED";
  }

  void
  PosixFSAdapter::writeData(FilesystemKey key, const std::vector<unsigned char> &data) {
    throw "NOT YET IMPLEMENTED";
  }

  void
  PosixFSAdapter::readData(FilesystemKey key, std::vector<unsigned char> &destination) {
    throw "NOT YET IMPLEMENTED";
  }

  void
  PosixFSAdapter::erase(FilesystemKey key) {
    throw "NOT YET IMPLEMENTED";
  }
}
