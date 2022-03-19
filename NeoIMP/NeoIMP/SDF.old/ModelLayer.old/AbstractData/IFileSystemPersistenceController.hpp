#ifndef SDF_MODELLAYER_ABSTRACTDATA_IFILESYSTEMPERSISTENCECONTROLLER_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_IFILESYSTEMPERSISTENCECONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IFileSystemPersistenceController.hpp
 * PURPOSE: Defines the IFileSystemPersistenceController interface.
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

namespace SDF::ModelLayer::AbstractData {
  // Class:      IFileSystemPersistenceController
  // Purpose:    Provides an interface to set and retrieve how a document should be persisted to the file system.
  // Parameters: T - The domain object type.
  //             FormatEnumT - Enumeration of the allowable file formats to use for persisting.
  template<class T, class FormatEnumT>
  class IFileSystemPersistenceController {
  public:
    virtual ~IFileSystemPersistenceController() = default;

    // Function:  assignFileSpec
    // Purpose:   Assign a file spec to save an object as.
    // Arguments: id - The ID of the domain object to set the file name for.
    //            fileSpec - The file name to give the object.
    virtual void
    assignFileSpec(int id,
                   std::string fileSpec
                  ) = 0;

    // Function:  setFileFormat
    // Purpose:   Set the file format used to save an object.
    // Arguments: id - The ID of the domain object to set the file format for.
    //            fileFormat - The format to use to persist the object.
    virtual void
    setFileFormat(int id,
                  FormatEnumT fileFormat
                 ) = 0;

    // Function:  persist
    // Purpose:   Persists the object with the given ID.
    // Arguments: id - The ID of the domain object to persist.
    virtual void
    persist(int id) = 0;

    // Function:  load
    // Purpose:   Loads an object from persistent storage.
    // Arguments: fileSpec - The file spec to the file to load.
    //            fileFormat - The format to attempt to load this file as.
    // Returns:   The domain object ID of the newly-loaded object.
    virtual int
    load(std::string fileSpec,
         FormatEnumT fileFormat
        ) = 0;
  };
}

#endif
