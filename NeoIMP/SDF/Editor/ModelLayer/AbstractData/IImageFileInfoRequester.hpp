#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEFILEINFOREQUESTER_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEFILEINFOREQUESTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageFileInfoRequester.hpp
 * PURPOSE: Defines the IImageFileInfoRequester interface.
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
#include "EFormat.hpp"

#include <string>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IImageFileInfoRequester
  // Purpose:    Defines an interface mapping between image document handles and file specs and
  //             formats.
  // Parameters: ImageT - The image type.
  template<class ImageT>
  class IImageFileInfoRequester {
  public:
    virtual ~IImageFileInfoRequester() = default;

    // Function:         hasAssociatedFile
    // Purpose:          Check if the given id has an associated file.
    // Parameters:       id - The image document ID to check.
    // Returns:          Whether a file is associated to this ID.
    // Throws (non-bug): ObjectNotFoundInRepoException
    virtual bool
    hasAssociatedFile(Common::Handle id) const = 0;

    // Function:         getFileSpecById
    // Purpose:          Obtains the file spec associated to the given id.
    // Parameters:       id - The image document ID to check.
    // Returns:          The desired file spec.
    // Throws (non-bug): SaveParamsNotAssociatedException
    virtual std::string
    getFileSpecById(Common::Handle id) const = 0;

    // Function:         getFileFormatById
    // Purpose:          Obtains the file format associated to the given id.
    // Parameters:       id - The image document ID to check.
    // Returns:          The desired file format.
    // Throws (non-bug): SaveParamsNotAssociatedException
    virtual EFormat
    getFileFormatById(Common::Handle id) const = 0;
  };
}

#endif
