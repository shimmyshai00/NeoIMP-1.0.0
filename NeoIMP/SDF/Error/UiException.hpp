#ifndef SDF_ERROR_UIEXCEPTION_HPP
#define SDF_ERROR_UIEXCEPTION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiException.hpp
 * PURPOSE: Defines exceptions thrown from UI layers.
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
  class UiException : public Exception {};

  // There is only one UI exception which is meant basically to be caught to show an error message
  // to the user.
  class ErrMsgException : public General<UiException> {
  public:
    ErrMsgException(const char *msg) {
      whatPrintf(msg);
    }
  };
}

#endif
