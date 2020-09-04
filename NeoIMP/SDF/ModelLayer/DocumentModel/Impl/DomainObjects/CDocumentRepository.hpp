#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_CDOCUMENTREPOSITORY_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_CDOCUMENTREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentRepository.hpp
 * PURPOSE: Definition of the document repository class.
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

#include <DocumentHandle.hpp>
#include <Impl/DomainObjects/CDocument.hpp>

#include <map>
#include <memory>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects {
        class CDocumentRepository {
        public:
          ~CDocumentRepository();

          void addDocument(DocumentModel::DocumentHandle handle, std::unique_ptr<CDocument> document);
          CDocument &accessDocument(DocumentModel::DocumentHandle handle);
        public:
          struct DocumentNotFoundException : public SDF::Exception {
            DocumentNotFoundException(DocumentModel::DocumentHandle handle)
            : Exception("INTERNAL ERROR: Document with handle %d not found in repository", handle)
            {
            }
          };
        private:
          std::map<DocumentModel::DocumentHandle, std::unique_ptr<CDocument>> m_documentMap;
        };
      }
    }
  }
}

#endif
