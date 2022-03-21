#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions that can occur as the result of invalid input to the data layer.
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
#include "../../../Exception.hpp"

namespace SDF::Editor::ModelLayer::AbstractData {
  SDF_DEF_NRM_EXCEPTION_1(ObjectNotFoundInRepoException, "Object with id %u not found in repository.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(RepositoryIdInUseException, "Repository id %u already in use.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(SaveParamsNotAssociatedException, "Persistence parameters (file spec, format) not associated with object %u.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(FileNotFoundException, "File %s not found.", const char *)
  SDF_DEF_NRM_EXCEPTION_1(UnsupportedFormatException, "The file format %d is not supported.", int)
  SDF_DEF_NRM_EXCEPTION(UnsupportedSubFormatException, "Tried to load a file using a valid but currently-unsupported form of its format.")
  SDF_DEF_NRM_EXCEPTION(BadFileException, "This file is corrupt or malformed.")
  SDF_DEF_NRM_EXCEPTION(BadImageException, "Tried to save a malformed image document to a file.")
  SDF_DEF_NRM_EXCEPTION(IoException, "An I/O error occurred.")
}

#endif
