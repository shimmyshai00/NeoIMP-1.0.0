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

#include <SDF/ModelLayer/Iface/IDocumentService.hpp>
#include <SDF/ModelLayer/Iface/DocumentHandle.hpp>
#include <SDF/ModelLayer/Iface/Param/SDocumentSpec.hpp>
#include <SDF/ModelLayer/Iface/Param/EFileFormat.hpp>
#include <Impl/DomainObjects/CDocumentLibrary.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace Services {
      class CDocumentService : public SDF::ModelLayer::Iface::IDocumentService {
      public:
        CDocumentService();

        SDF::ModelLayer::Iface::DocumentHandle createDocument(
          SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec);
        SDF::ModelLayer::Iface::DocumentHandle loadDocumentFromFile(std::string fileName,
          SDF::ModelLayer::Iface::Param::EFileFormat fileFormat);
        void saveDocumentToFile(std::string fileName, SDF::ModelLayer::Iface::Param::EFileFormat fileFormat,
          SDF::ModelLayer::Iface::DocumentHandle handle);
      private:
        SDF::ModelLayer::Iface::DocumentHandle nextHandle;
        Impl::DomainObjects::CDocumentLibrary documentLibrary;
      };
    }
  }
}

#endif
