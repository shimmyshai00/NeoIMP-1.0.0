#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_EXCEPTIONS_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines exceptions specific to the data mapper functionality.
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

namespace SDF::Editor::DataLayer::DataMappers {
  class InvalidImageObjectException : public Error::LikelyBug<Error::DataException> {};

  struct ImageLayerMissingContentException : public InvalidImageObjectException {
    ImageLayerMissingContentException() {
      whatPrintf("Tried to persist an image object with a layer with no content.");
    }
  };

  struct ImageMissingBackgroundLayerException : public InvalidImageObjectException {
    ImageMissingBackgroundLayerException() {
      whatPrintf("Tried to persist an image object that is missing a background layer.");
    }
  };

  struct ImageMissingLayersException : public InvalidImageObjectException {
    ImageMissingLayersException() {
      whatPrintf("Tried to persist an image object that is missing layers.");
    }
  };

  struct UnsupportedFormatException : public Error::LikelyBug<Error::DataException> {
    int m_formatIdx;
    UnsupportedFormatException(int formatIdx) : m_formatIdx(formatIdx) {
      whatPrintf("Tried to load a file using an unrecognized or unsupported file format '%d'.",
        m_formatIdx);
    }
  };
}

namespace SDF::Editor::DataLayer::DataMappers {
  struct UnsupportedSubFormatException : public Error::BadFileException {
    UnsupportedSubFormatException(const char *fileSpec) : BadFileException(fileSpec) {
      whatPrintf("The format of this file was valid, but the specific type is not supported by "
      "this program.");
    }
  };

  struct MalformedFileException : public Error::BadFileException {
    MalformedFileException(const char *fileSpec) : BadFileException(fileSpec) {
      whatPrintf("This file is not valid - it is either malformed or corrupt.");
    }
  };
}

#endif
