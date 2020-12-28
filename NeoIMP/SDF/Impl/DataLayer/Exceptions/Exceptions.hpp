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

#include <SDF/Impl/Framework/Handle.hpp>

namespace SDF::Impl::DataLayer::Exceptions {
  struct IdAlreadyInUseException : public SDF::Exception::Exception {
    IdAlreadyInUseException(Framework::Handle handle)
      : Exception("An object with handle '%d' already exists in the repository.", handle)
    {}
  };

  struct ObjectNotFoundException : public SDF::Exception::Exception {
    ObjectNotFoundException(Framework::Handle handle)
      : Exception("Object with handle '%d' was not found in the repository.", handle)
    {}
  };

  struct MultilayerImageNotSupportedException : public SDF::Exception::Exception {
    MultilayerImageNotSupportedException(std::string formatName)
      : Exception("The %s format does not support saving images with multiple layers.", formatName)
    {}
  };

  struct ColorModelNotSupportedException : public SDF::Exception::Exception {
    ColorModelNotSupportedException(std::string colorModelName)
      : Exception("The %s color model is not supported by this file format.", colorModelName)
    {}
  };
}

#endif
