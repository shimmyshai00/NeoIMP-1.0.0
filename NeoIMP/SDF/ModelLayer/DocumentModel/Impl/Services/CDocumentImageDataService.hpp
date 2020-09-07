#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_SERVICES_CDOCUMENTIMAGEDATASERVICE_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_SERVICES_CDOCUMENTIMAGEDATASERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentImageDataService.hpp
 * PURPOSE: Definition of the document image data service class.
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

#include <Services/IDocumentImageDataService.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects {
        class CDocumentRepository;
      }

      namespace Impl::Services {
        class CDocumentImageDataService : public DocumentModel::Services::IDocumentImageDataService {
        public:
          CDocumentImageDataService(DomainObjects::CDocumentRepository *documentRepository);

          int getImageWidthInPixels(DocumentHandle handle) const;
          int getImageHeightInPixels(DocumentHandle handle) const;

          Spec::EColorModel getDocumentColorModel(DocumentHandle handle) const;
          Spec::EBitDepth getDocumentBitDepth(DocumentHandle handle) const;
        public:
          struct NullRepositoryException : public SDF::Exception {
            NullRepositoryException()
            : Exception("Tried to pass a null document repository pointer to document image data service")
            {
            }
          };
        private:
          DomainObjects::CDocumentRepository *m_documentRepository;
        };
      }
    }
  }
}

#endif
