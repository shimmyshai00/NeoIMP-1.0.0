/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewConfigService.cpp
 * PURPOSE: Implements the DocumentViewConfigService class.
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

#include <DocumentViewConfigService.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>

#include <Math/Coord.hpp>

namespace SDF::ModelLayer::Services {
  DocumentViewConfigService::DocumentViewConfigService(
    AbstractData::IRepository<AbstractDomain::IImage> *documentRepository
  )
    : m_documentRepository(documentRepository)
  {
  }

  float
  DocumentViewConfigService::getDocumentCenterX(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_documentRepository->retrieve(handle)->getViewCenter().getX();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentViewConfigService::getDocumentCenterY(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_documentRepository->retrieve(handle)->getViewCenter().getY();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentViewConfigService::getDocumentMagnification(UILayer::AbstractModel::Handle handle) const{
    try {
      return m_documentRepository->retrieve(handle)->getViewMagnification();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentCenterX(UILayer::AbstractModel::Handle handle, float centerX) {
    try {
      Math::Coord<float> curCenter(m_documentRepository->retrieve(handle)->getViewCenter());
      return m_documentRepository->retrieve(handle)->setViewCenter(Math::Coord<float>(centerX, curCenter.getY()));
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentCenterY(UILayer::AbstractModel::Handle handle, float centerY) {
    try {
      Math::Coord<float> curCenter(m_documentRepository->retrieve(handle)->getViewCenter());
      return m_documentRepository->retrieve(handle)->setViewCenter(Math::Coord<float>(curCenter.getX(), centerY));
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentMagnification(UILayer::AbstractModel::Handle handle, float magnification) {
    try {
      m_documentRepository->retrieve(handle)->setViewMagnification(magnification);
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }
}
