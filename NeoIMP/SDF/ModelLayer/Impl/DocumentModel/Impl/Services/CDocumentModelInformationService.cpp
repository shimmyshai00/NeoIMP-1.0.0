/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentModelInformationService.cpp
 * PURPOSE: Implementation of the document model information service class.
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

#include <CDocumentModelInformationService.hpp>
#include <Impl/DomainObjects/CDocument.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace Services {
      CDocumentModelInformationService::CDocumentModelInformationService() {

      }

      int CDocumentModelInformationService::getMinValidDocumentWidthPx() const {
        return 1;
      }

      int CDocumentModelInformationService::getMinValidDocumentHeightPx() const {
        return 1;
      }

      int CDocumentModelInformationService::getMaxValidDocumentWidthPx() const {
        using namespace Impl::DomainObjects;

        return CDocument::c_maxDocumentWidthPx;
      }

      int CDocumentModelInformationService::getMaxValidDocumentHeightPx() const {
        using namespace Impl::DomainObjects;

        return CDocument::c_maxDocumentHeightPx;
      }
    }
  }
}
