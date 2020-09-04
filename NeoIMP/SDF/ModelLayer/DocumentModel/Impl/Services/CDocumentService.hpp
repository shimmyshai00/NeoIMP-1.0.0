#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_IMPL_SERVICES_CDOCUMENTSERVICE_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_IMPL_SERVICES_CDOCUMENTSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentService.hpp
 * PURPOSE: Definition of the document service class.
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

#include <Services/IDocumentService.hpp>
#include <DocumentHandle.hpp>
#include <Spec/EFileFormat.hpp>

#include <string>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Spec {
        struct SDocumentSpec;
      }

      namespace Impl::DomainObjects {
        class CDocumentRepository;
      }

      namespace Impl::Services {
        class CDocumentService : public DocumentModel::Services::IDocumentService {
        public:
          CDocumentService(DomainObjects::CDocumentRepository *documentRepository);

          DocumentHandle createDocument(Spec::SDocumentSpec documentSpec);
          DocumentHandle loadDocument(std::string fileName, Spec::EFileFormat fileFormat);
          void saveDocument(std::string fileName, Spec::EFileFormat fileFormat, DocumentHandle handle);
        public:
          struct NullRepositoryException : public SDF::Exception {
            NullRepositoryException()
            : Exception("Tried to pass a null document repository pointer to document service")
            {
            }
          };
        private:
          DocumentHandle m_nextHandle;
          DomainObjects::CDocumentRepository *m_documentRepository;
        };
      }
    }
  }
}

#endif
