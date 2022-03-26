#ifndef SDF_EDITOR_MODELLAYER_SERVICES_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the remaining exceptions for the model layer services.
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
#include "../../../Error/ModelException.hpp"

namespace SDF::Editor::ModelLayer::Services {
  class ServiceException : public Error::LikelyBug<Error::ModelException> {};

  struct BadFileFormatException : public ServiceException {
    int m_formatIdx;
    BadFileFormatException(int formatIdx) : m_formatIdx(formatIdx) {
      whatPrintf("Bad file format specifier '%d' passed.", m_formatIdx);
    }
  };

  struct BadColorModelException : public ServiceException {
    int m_colorModelIdx;
    BadColorModelException(int colorModelIdx) : m_colorModelIdx(colorModelIdx) {
      whatPrintf("Bad color model specifier '%d' passed.", m_colorModelIdx);
    }
  };
}

#endif
