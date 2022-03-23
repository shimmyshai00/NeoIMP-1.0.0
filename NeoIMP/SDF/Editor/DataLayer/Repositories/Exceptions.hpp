#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_EXCEPTIONS_HPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines exceptions specific to the repository functionality.
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

#include "../../../Error/Exception.hpp"
#include "../../../Error/DataException.hpp"
#include "../../../Error/SafeString.hpp"

namespace SDF::Editor::DataLayer::Repositories {
  struct SaveParamsNotAssociatedException : public Error::LikelyBug<Error::DataException> {
    Common::Handle m_id;
    SaveParamsNotAssociatedException(Common::Handle id) : m_id(id) {}

    virtual const char *what() const noexcept {
      return "Save parameters (file format/spec) were not associated with this image.";
    }
  };

  struct UnsupportedFormatException : public Error::LikelyBug<Error::DataException> {
    int m_formatIdx;
    UnsupportedFormatException(int formatIdx) : m_formatIdx(formatIdx) {}

    const char *what() const noexcept {
      Error::SafeString ret;
      ret.sPrintf("Tried to load a file using an unrecognized or unsupported file format '%d'.");

      return ret.get();
    }
  };
}

#endif
