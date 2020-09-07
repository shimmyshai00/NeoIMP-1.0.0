/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentImageDataService.cpp
 * PURPOSE: Implementation of the document image data service class.
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

#include <Impl/Services/CDocumentImageDataService.hpp>

#include <Impl/DomainObjects/CDocumentRepository.hpp>
#include <Impl/DomainObjects/CDocument.hpp>

#include <cassert>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::Services {
        CDocumentImageDataService::CDocumentImageDataService(DomainObjects::CDocumentRepository *documentRepository)
        : m_documentRepository(documentRepository)
        {
          if(m_documentRepository == nullptr) {
            throw NullRepositoryException();
          }

          // class invariants
          assert(m_documentRepository != nullptr);
        }

        int CDocumentImageDataService::getImageWidthInPixels(DocumentHandle handle) const {
          using namespace DomainObjects;

          assert(m_documentRepository != nullptr);

          try {
            return m_documentRepository->accessDocument(handle).getDocumentWidthPx();
          } catch(CDocumentRepository::DocumentNotFoundException &e) {
            throw InvalidDocumentHandleException(handle);
          }
        }

        int CDocumentImageDataService::getImageHeightInPixels(DocumentHandle handle) const {
          using namespace DomainObjects;

          assert(m_documentRepository != nullptr);

          try {
            return m_documentRepository->accessDocument(handle).getDocumentHeightPx();
          } catch(CDocumentRepository::DocumentNotFoundException &e) {
            throw InvalidDocumentHandleException(handle);
          }
        }

        Spec::EColorModel CDocumentImageDataService::getDocumentColorModel(DocumentHandle handle) const {
          using namespace DomainObjects;

          assert(m_documentRepository != nullptr);

          try {
            return m_documentRepository->accessDocument(handle).getDocumentColorModel();
          } catch(CDocumentRepository::DocumentNotFoundException &e) {
            throw InvalidDocumentHandleException(handle);
          }
        }

        Spec::EBitDepth CDocumentImageDataService::getDocumentBitDepth(DocumentHandle handle) const {
          using namespace DomainObjects;

          assert(m_documentRepository != nullptr);

          try {
            return m_documentRepository->accessDocument(handle).getDocumentBitDepth();
          } catch(CDocumentRepository::DocumentNotFoundException &e) {
            throw InvalidDocumentHandleException(handle);
          }
        }
      }
    }
  }
}
