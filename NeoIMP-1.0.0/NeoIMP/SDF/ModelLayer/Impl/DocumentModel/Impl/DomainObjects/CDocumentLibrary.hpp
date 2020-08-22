#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_CDOCUMENTLIBRARY_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_CDOCUMENTLIBRARY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentLibrary.hpp
 * PURPOSE: Definition of a library class holding all documents currently in memory (persistent storage is handled by
 *          the DataLayer and accessed via the CDocumentDataMapper).
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

#include <SDF/ModelLayer/Iface/DocumentHandle.hpp>
#include <CDocument.hpp>
#include <SDF/Exception.hpp>
#include <memory>
#include <map>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects {
      class CDocumentLibrary {
      public:
        CDocumentLibrary();

        void addDocument(SDF::ModelLayer::Iface::DocumentHandle handle, std::unique_ptr<CDocument> document);
        void removeDocument(SDF::ModelLayer::Iface::DocumentHandle handle);
        CDocument &getDocument(SDF::ModelLayer::Iface::DocumentHandle handle);
      public:
        struct DocumentNotFoundException : public SDF::Exception {
          DocumentNotFoundException(SDF::ModelLayer::Iface::DocumentHandle handle)
          : Exception("Document with handle %d not found. This is probably a bug.", handle)
          {
          }
        };
      private:
        std::map<SDF::ModelLayer::Iface::DocumentHandle, std::unique_ptr<CDocument>> documentMap;
      };
    }
  }
}

#endif
