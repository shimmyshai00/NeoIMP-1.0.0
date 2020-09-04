#ifndef SDF_MODELLAYER_EXCEPTIONS_HPP
#define SDF_MODELLAYER_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Definition of exceptions which can be thrown from the model layer that are common to many model layer
 *          services.
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

#include <SDF/Exception.hpp>

namespace SDF::ModelLayer::Exceptions {
  struct DocumentNotFoundException : public SDF::Exception {
    DocumentNotFoundException(DocumentHandle handle)
    : Exception("Tried to access a document that does not exist in the ones loaded (handle: %d). This is probably a bug.", handle)
    {
    }
  };

  struct LayerNotFoundException : public SDF::Exception {
    LayerNotFoundException(int layerNum)
    : Exception("Tried to access a layer that doesn't exist (num %d). This is probably a bug.", layerNum)
    {
    }
  };

  struct OutOfBoundsException : public SDF::Exception {
    OutOfBoundsException(int x, int y)
    : Exception("Tried to access a pixel coordinate (%d, %d) that was out of image bounds. This is probably a bug.", x, y)
    {
    }
  };
}

#endif
