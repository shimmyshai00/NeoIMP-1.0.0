#ifndef SDF_COMMON_DATA_ADAPTERS_FILESYSTEMKEY_HPP
#define SDF_COMMON_DATA_ADAPTERS_FILESYSTEMKEY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FilesystemKey.hpp
 * PURPOSE: Defines the FilesystemKey structure.
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

#include <cstddef>
#include <string>

namespace SDF::Common::Data::Adapters {
  // A low-level key into a filesystem. This "key" relates the idea of a filesystem to that of a
  // database by considering it as a collection of byte strings stored by the file containing them,
  // the offset into that file where the string begins, and the length of the byte string requested.
  struct FilesystemKey {
    std::string m_fileSpec;
    std::size_t m_offset; // bytes since the file beginning at which the desired data starts
    std::size_t m_length; // note: if 0, denotes the whole file, not an empty buffer!

    FilesystemKey(std::string fileSpec,
                  std::size_t offset,
                  std::size_t length
                 )
    {
      m_fileSpec = fileSpec;
      m_offset = offset;
      m_length = length;
    }
  };
}

#endif
