/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentService.cpp
 * PURPOSE: Implementation of the document service class.
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

#include <Impl/Services/CDocumentService.hpp>

#include <Impl/DomainObjects/CDocumentRepository.hpp>
#include <Impl/DomainObjects/Metrics/Length/Quantity.hpp>
#include <Impl/DomainObjects/Metrics/Length/FromSpec.hpp>
#include <Impl/DomainObjects/Metrics/Resolution/Quantity.hpp>
#include <Impl/DomainObjects/Metrics/Resolution/FromSpec.hpp>
#include <Spec/EDimensionUnit.hpp>
#include <Spec/EResolutionUnit.hpp>
#include <Spec/SDocumentSpec.hpp>
#include <Impl/DomainObjects/CLayer.hpp>
#include <Impl/DomainObjects/CDocument.hpp>

#include <cassert>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::Services {
        CDocumentService::CDocumentService(DomainObjects::CDocumentRepository *documentRepository)
          : m_nextHandle(0),
            m_documentRepository(documentRepository)
            {
              if(m_documentRepository == nullptr) {
                throw NullRepositoryException();
              }

              assert(m_documentRepository != nullptr);
            }

        DocumentHandle CDocumentService::createDocument(Spec::SDocumentSpec documentSpec) {
          using namespace Impl::DomainObjects;
          using namespace Spec;

          std::unique_ptr<CDocument> doc;
          Metrics::Resolution::Quantity resolution(Metrics::Resolution::fromSpec(documentSpec.documentResolution,
            documentSpec.resolutionUnit));

          if((documentSpec.widthUnit == UNIT_PIXEL) && (documentSpec.heightUnit == UNIT_PIXEL)) {
            doc = std::make_unique<CDocument>(documentSpec.documentWidthPx, documentSpec.documentHeightPx, resolution,
              documentSpec.colorModel, documentSpec.bitDepth);
          } else if((documentSpec.widthUnit == UNIT_PIXEL) && (documentSpec.heightUnit != UNIT_PIXEL)) {
            Metrics::Length::Quantity height(Metrics::Length::fromSpec(
              documentSpec.documentHeight, documentSpec.heightUnit));

            doc = std::make_unique<CDocument>(documentSpec.documentWidthPx, height, resolution,
              documentSpec.colorModel, documentSpec.bitDepth);
          } else if((documentSpec.widthUnit != UNIT_PIXEL) && (documentSpec.heightUnit == UNIT_PIXEL)) {
            Metrics::Length::Quantity width(Metrics::Length::fromSpec(
              documentSpec.documentWidth, documentSpec.widthUnit));

            doc = std::make_unique<CDocument>(width, documentSpec.documentHeightPx, resolution,
              documentSpec.colorModel, documentSpec.bitDepth);
          } else if((documentSpec.widthUnit != UNIT_PIXEL) && (documentSpec.heightUnit != UNIT_PIXEL)) {
            Metrics::Length::Quantity width(Metrics::Length::fromSpec(
              documentSpec.documentWidth, documentSpec.widthUnit));
            Metrics::Length::Quantity height(Metrics::Length::fromSpec(
              documentSpec.documentHeight, documentSpec.heightUnit));

            doc = std::make_unique<CDocument>(width, height, resolution,
              documentSpec.colorModel, documentSpec.bitDepth);
          }

          m_documentRepository->addDocument(m_nextHandle, std::move(doc));
          return m_nextHandle++;
        }

        DocumentHandle CDocumentService::loadDocument(std::string fileName, Spec::EFileFormat fileFormat) {
          using namespace SDF::ModelLayer::DocumentModel::Impl::DomainObjects;

          // TBA
          return -1;
        }

        void CDocumentService::saveDocument(std::string fileName, Spec::EFileFormat fileFormat, DocumentHandle handle) {
          // TBA
        }
      }
    }
  }
}
