#ifndef SDF_MODELLAYER_DOCUMENTMODEL_SERVICES_IDOCUMENTIMAGEDATASERVICE_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_SERVICES_IDOCUMENTIMAGEDATASERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentImageDataService.hpp
 * PURPOSE: The public interface for the document image data service.
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

#include <Spec/EColorModel.hpp>
#include <Spec/EBitDepth.hpp>

#include <DocumentHandle.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Services {
        class IDocumentImageDataService {
        public:
          virtual ~IDocumentImageDataService() {}

          virtual int getImageWidthInPixels(DocumentHandle handle) const = 0;
          virtual int getImageHeightInPixels(DocumentHandle handle) const = 0;

          virtual Spec::EColorModel getDocumentColorModel(DocumentHandle handle) const = 0;
          virtual Spec::EBitDepth getDocumentBitDepth(DocumentHandle handle) const = 0;
        public:
          struct InvalidDocumentHandleException : public SDF::Exception {
            InvalidDocumentHandleException(DocumentHandle handle)
            : Exception("Tried to access a document handle that doesn't seem to reference a presently-loaded document. This is likely a bug.")
            {
            }
          };
        };
      }
    }
  }
}

#endif
