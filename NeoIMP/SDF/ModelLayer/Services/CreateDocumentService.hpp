#ifndef SDF_MODELLAYER_SERVICES_CREATEDOCUMENTSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_CREATEDOCUMENTSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CreateDocumentService.hpp
 * PURPOSE: Defines the CreateDocumentService class.
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

#include "../../UILayer/AbstractModel/Services/ICreateDocumentService.hpp"
#include "../Repositories/IRepository.hpp"
#include "../DomainObjects/Image/IImage.hpp"

#include <fruit/fruit.h>

namespace SDF::ModelLayer::Services {
  // Class:      CreateDocumentService
  // Purpose:    Implements a service to create a new document from a document spec.
  // Parameters: None.
  class CreateDocumentService : public UILayer::AbstractModel::Services::ICreateDocumentService {
  public:
    INJECT(CreateDocumentService(Repositories::IRepository<DomainObjects::Image::IImage> *imageRepository));

    UILayer::AbstractModel::Handle
    createDocument(UILayer::AbstractModel::Data::DocumentSpec spec);
  private:
    Repositories::IRepository<DomainObjects::Image::IImage> *m_imageRepository;
  };
}

#endif
