#ifndef SDF_IMPL_DATALAYER_EXCEPTIONS_EXCEPTIONS_HPP
#define SDF_IMPL_DATALAYER_EXCEPTIONS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: The exceptions that can be thrown from the data layer.
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

#include <SDF/Exception/Exception.hpp>

#include <string>

namespace SDF::Impl::DataLayer::Exceptions {
  struct MultilayerImageNotSupportedException : public SDF::Exception::Exception {
    MultilayerImageNotSupportedException(const char *formatName)
      : Exception(false, "The %s format does not support saving images with multiple layers.", formatName)
    {}
  };

  struct ColorModelNotSupportedException : public SDF::Exception::Exception {
    ColorModelNotSupportedException(const char *colorModelName)
      : Exception(false, "The %s color model is not supported by this file format.", colorModelName)
    {}
  };

  struct BadFileException : public SDF::Exception::Exception {
    BadFileException(const char *formatName, const char *curLimitations)
      : Exception(false,
                  "This file is either not a a valid '%s' format file, or is one, but of\
                   a kind the program currently does not support. Current limitations\
                   on loading this type of file are:\n\n"\
                  "%s", formatName, curLimitations)
    {}
  };
}

#endif
