#ifndef SDF_ERROR_DATAEXCEPTION_HPP
#define SDF_ERROR_DATAEXCEPTION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DataException.hpp
 * PURPOSE: Defines exceptions thrown from data layers.
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

#include "Exception.hpp"
#include "SafeString.hpp"

namespace SDF::Error {
  class DataException : public Exception {
  public:
    virtual ~DataException() = 0;
  };

  template<class KeyT>
  class ObjectAlreadyExistsException : public General<DataException> {
  public:
    KeyT m_key;
    ObjectAlreadyExistsException(const KeyT &key) : m_key(key) {
      whatPrintf("Object already exists in container");
    }
  };

  template<class KeyT>
  class ObjectNotFoundException : public General<DataException> {
  public:
    KeyT m_key;
    ObjectNotFoundException(const KeyT &key) : m_key(key) {
      whatPrintf("Object not found");
    }
  };

  class FileNotFoundException : public General<DataException> {
  public:
    SafeString m_fileSpec;
    FileNotFoundException(const char *fileSpec) : m_fileSpec(fileSpec) {
      whatPrintf("File not found");
    }
  };

  class DatabaseConnectionFailedException : public General<DataException> {
  public:
    DatabaseConnectionFailedException() {
      whatPrintf("Database connection failed");
    }
  };

  class IoException : public General<DataException> {
  public:
    IoException() {
      whatPrintf("I/O error");
    }
  };

  class FilesystemException : public General<DataException> {
  public:
    FilesystemException() {
      whatPrintf("Something when wrong when trying to access the file system.");
    }
  };

  class BadFileException : public General<DataException> {
  public:
    SafeString m_fileSpec;
    BadFileException(const char *fileSpec) : m_fileSpec(fileSpec) {
      whatPrintf("This file does not appear to be valid. It may be damaged, not in the format the "
      "program is expecting, or malformed.");
    }
  };
}

#endif
