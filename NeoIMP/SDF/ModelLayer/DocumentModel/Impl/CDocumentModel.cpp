/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentModel.cpp
 * PURPOSE: Implementation of the document model class.
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

#include <Impl/CDocumentModel.hpp>

#include <Services/IDocumentServiceDependency.hpp>
#include <Services/IDocumentModelInformationServiceDependency.hpp>
#include <Services/IDocumentMeasurementsServiceDependency.hpp>
#include <Services/IDocumentImageDataServiceDependency.hpp>

#include <Impl/DomainObjects/CDocument.hpp>
#include <Impl/DomainObjects/CDocumentRepository.hpp>

#include <Impl/Services/CDocumentService.hpp>
#include <Impl/Services/CDocumentModelInformationService.hpp>
#include <Impl/Services/CDocumentMeasurementsService.hpp>
#include <Impl/Services/CDocumentImageDataService.hpp>

namespace SDF::ModelLayer::DocumentModel::Impl {
  CDocumentModel::CDocumentModel()
  : m_documentRepository(new DomainObjects::CDocumentRepository()),
    m_documentService(new Services::CDocumentService(m_documentRepository.get())),
    m_documentModelInformationService(new Services::CDocumentModelInformationService),
    m_documentMeasurementsService(new Services::CDocumentMeasurementsService),
    m_documentImageDataService(new Services::CDocumentImageDataService(m_documentRepository.get()))
    {
    }

  void CDocumentModel::injectDocumentService(DocumentModel::Services::IDocumentServiceDependency &dep) {
    dep.injectWith(m_documentService.get());
  }

  void CDocumentModel::injectDocumentModelInformationService(
    DocumentModel::Services::IDocumentModelInformationServiceDependency &dep) {
      dep.injectWith(m_documentModelInformationService.get());
  }

  void CDocumentModel::injectDocumentMeasurementsService(
    DocumentModel::Services::IDocumentMeasurementsServiceDependency &dep) {
      dep.injectWith(m_documentMeasurementsService.get());
  }

  void CDocumentModel::injectDocumentImageDataService(
    DocumentModel::Services::IDocumentImageDataServiceDependency &dep) {
      dep.injectWith(m_documentImageDataService.get());
  }
}
