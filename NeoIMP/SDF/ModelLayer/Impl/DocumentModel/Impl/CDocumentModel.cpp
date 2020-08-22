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

#include <CDocumentModel.hpp>
#include <Services/CDocumentService.hpp>
#include <Services/CDocumentModelInformationService.hpp>
#include <Services/CDocumentMeasurementsService.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    CDocumentModel::CDocumentModel()
    : m_documentService(new Services::CDocumentService),
      m_documentModelInformationService(new Services::CDocumentModelInformationService),
      m_documentMeasurementsService(new Services::CDocumentMeasurementsService) {

    }

    void CDocumentModel::injectDocumentService(SDF::ModelLayer::Iface::IDocumentServiceDependency *dep) {
      assert(dep != nullptr);

      dep->injectWith(m_documentService.get());
    }

    void CDocumentModel::injectDocumentModelInformationService(
      SDF::ModelLayer::Iface::IDocumentModelInformationServiceDependency *dep) {
      assert(dep != nullptr);

      dep->injectWith(m_documentModelInformationService.get());
    }

    void CDocumentModel::injectDocumentMeasurementsService(
      SDF::ModelLayer::Iface::IDocumentMeasurementsServiceDependency *dep) {
      assert(dep != nullptr);

      dep->injectWith(m_documentMeasurementsService.get());
    }
  }
}
