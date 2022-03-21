#ifndef SDF_EDITOR_DATALAYER_EXCEPTIONS_HPP
#define SDF_EDITOR_DATALAYER_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions that can occur as the result of internal data layer errors.
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

#include "../../Common/Handle.hpp"
#include "../../Exception.hpp"

namespace SDF::Editor::DataLayer {
  SDF_DEF_BUG_EXCEPTION(FileNotFoundException, "File not found.")
  SDF_DEF_BUG_EXCEPTION(BadImageException, "Tried to persist a malformed image document.")
  SDF_DEF_BUG_EXCEPTION(BadFileException, "Tried to load a corrupt or invalid image file.")
  SDF_DEF_BUG_EXCEPTION(UnimplementedFormatException, "Tried to save to an unimplemented file format.")
  SDF_DEF_BUG_EXCEPTION(UnsupportedSubFormatException, "Tried to load a file with a valid but unsupported form of its format.")
  SDF_DEF_BUG_EXCEPTION(DoubleMapException, "Tried to double-map an existing file spec using 'insert'.")
  SDF_DEF_BUG_EXCEPTION(FileSpecNotMappedException, "File to be updated was not previously mapped.")
}

#endif
