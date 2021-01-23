#ifndef SDF_IMPL_MEMORYLAYER_EXCEPTIONS_EXCEPTIONS_HPP
#define SDF_IMPL_MEMORYLAYER_EXCEPTIONS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: The exceptions that can be thrown from the memory layer.
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

#include <SDF/Impl/ModelLayer/AbstractMemory/Handle.hpp>

namespace SDF::Impl::MemoryLayer::Exceptions {
  struct ObjectNotFoundException : public SDF::Exception::Exception {
    ObjectNotFoundException(ModelLayer::AbstractMemory::Handle handle)
      : Exception("Object with handle '%d' not found in the repository", handle)
    {}
  };

  struct DuplicateObjectException : public SDF::Exception::Exception {
    DuplicateObjectException(ModelLayer::AbstractMemory::Handle handle)
      : Exception("Tried to add object to repository with already-taken handle '%d'", handle)
    {}
  };

  struct FileSpecNotAssignedException : public SDF::Exception::Exception {
    FileSpecNotAssignedException(ModelLayer::AbstractMemory::Handle handle)
      : Exception("Tried to save/load object with handle '%d' without assigned file spec", handle)
    {}
  };

  struct FileFormatNotAssignedException : public SDF::Exception::Exception {
    FileFormatNotAssignedException(ModelLayer::AbstractMemory::Handle handle)
      : Exception("Tried to load object into handle '%d' without assigned file format", handle)
    {}
  };
}

#endif
