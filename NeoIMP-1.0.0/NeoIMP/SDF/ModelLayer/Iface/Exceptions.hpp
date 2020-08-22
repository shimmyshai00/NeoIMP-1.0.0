#ifndef SDF_MODELLAYER_IFACE_DOCUMENTMODEL_EXCEPTIONS_HPP
#define SDF_MODELLAYER_IFACE_DOCUMENTMODEL_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Definition of exceptions which can be thrown from the model layer.
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

namespace SDF::ModelLayer {
  namespace Iface {
    namespace Exceptions {
      struct DocumentSizeTooBigException : public SDF::Exception {
        DocumentSizeTooBigException(int width, int height, int maxWidth, int maxHeight)
        : Exception("Document size %d px x %d px is too big. Maximum is %d px x %d px.",
            width, height, maxWidth, maxHeight)
        {
        }
      };

      struct BadDocumentSizeException : public SDF::Exception {
        BadDocumentSizeException(int width, int height)
        : Exception("Document size %d px x %d px is bad (either negative or zero).", width, height)
        {
        }
      };
    }
  }
}

#endif
