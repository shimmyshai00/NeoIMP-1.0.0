#ifndef SDF_MODELLAYER_EXCEPTIONS_EXCEPTIONS_HPP
#define SDF_MODELLAYER_EXCEPTIONS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions that can be thrown from the model layer.
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

#include <cstddef>

namespace SDF::ModelLayer::Exceptions {
  struct DocumentNotFoundException : public SDF::Exception::Exception {
    DocumentNotFoundException(UILayer::AbstractModel::Handle handle)
      : Exception(true, "Tried to access a document with handle '%d' that does not appear to exist.", handle)
      {}
  };

  struct RenderingNotFoundException : public SDF::Exception::Exception {
    RenderingNotFoundException(UILayer::AbstractModel::Handle handle)
      : Exception(true, "Tried to access a rendering with handle '%d' that does not appear to exist.", handle)
      {}
  };

  struct InvalidLayerException : public SDF::Exception::Exception {
    InvalidLayerException(std::size_t layerNum)
      : Exception(true, "Tried to access a layer at invalid layer number '%d'.", layerNum)
    {}
  };

  struct BadDocumentSpecException : public SDF::Exception::Exception {
    BadDocumentSpecException()
      : Exception(true, "Tried to create a document from a bad spec.")
    {}
  };
}

#endif
