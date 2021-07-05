#ifndef SDF_UILAYER_EXCEPTIONS_EXCEPTIONS_HPP
#define SDF_UILAYER_EXCEPTIONS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions that can be thrown from the UI layer.
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

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <string>

namespace SDF::UILayer::Exceptions {
  struct InvalidHandleException : public SDF::Exception::Exception {
    InvalidHandleException(UILayer::AbstractModel::Handle handle)
      : Exception(true, "Tried to access a resource for a document with handle '%d' that doesn't exist.", handle)
    {}
  };

  struct InvalidUnitException : public SDF::Exception::Exception {
    InvalidUnitException(const char *quantityType,
                         int unitId
                        )
      : Exception(true, "Tried to make a measurable quantity of type '%s' with unit number %d which doesn't correspond to a valid unit.", quantityType, unitId)
    {}
  };
}

#endif
