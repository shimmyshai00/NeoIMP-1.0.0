#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_IMPL_CDOCUMENTMODEL_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_IMPL_CDOCUMENTMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentModel.hpp
 * PURPOSE: Definition of the document model class.
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

#include <Iface/IDocumentModel.hpp>
#include <SDF/ModelLayer/Iface/IDocumentServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentModelInformationServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentMeasurementsServiceDependency.hpp>
#include <Impl/Services/CDocumentService.hpp>
#include <Impl/Services/CDocumentModelInformationService.hpp>
#include <Impl/Services/CDocumentMeasurementsService.hpp>
#include <memory>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    class CDocumentModel : public Iface::IDocumentModel {
    public:
      CDocumentModel();

      void injectDocumentService(SDF::ModelLayer::Iface::IDocumentServiceDependency *dep);
      void injectDocumentModelInformationService(
        SDF::ModelLayer::Iface::IDocumentModelInformationServiceDependency *dep);
      void injectDocumentMeasurementsService(SDF::ModelLayer::Iface::IDocumentMeasurementsServiceDependency *dep);
    private:
      std::unique_ptr<Services::CDocumentService> m_documentService;
      std::unique_ptr<Services::CDocumentModelInformationService> m_documentModelInformationService;
      std::unique_ptr<Services::CDocumentMeasurementsService> m_documentMeasurementsService;
    };
  }
}

#endif
