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

#include <SDF/ModelLayer/AbstractData/IObservableRepository.hpp>
#include <SDF/ModelLayer/AbstractData/IRepository.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IDocumentViewParams.hpp>

namespace SDF::ModelLayer::Services {
  DocumentViewConfigService::DocumentViewConfigService(
    AbstractData::IRepository<AbstractDomain::IDocumentViewParams> *repository,
    AbstractData::IObservableRepository<AbstractDomain::IImage> *documentRepository,
    Interfaces::IFactory<AbstractDomain::IDocumentViewParams, float, float, float> *paramFactory
  )
    : m_repository(repository),
      m_documentRepository(documentRepository),
      m_paramFactory(paramFactory)
  {
    m_documentRepository->attachObserver(this);
  }

  DocumentViewConfigService::~DocumentViewConfigService() {
    m_documentRepository->removeObserver(this);
  }

  float
  DocumentViewConfigService::getDocumentCenterX(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_repository->retrieve(handle)->getCenterX();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentViewConfigService::getDocumentCenterY(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_repository->retrieve(handle)->getCenterY();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentViewConfigService::getDocumentMagnification(UILayer::AbstractModel::Handle handle) const{
    try {
      return m_repository->retrieve(handle)->getMagnification();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentCenterX(UILayer::AbstractModel::Handle handle, float centerX) {
    try {
      return m_repository->retrieve(handle)->setCenterX(centerX);
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentCenterY(UILayer::AbstractModel::Handle handle, float centerY) {
    try {
      return m_repository->retrieve(handle)->setCenterY(centerY);
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentMagnification(UILayer::AbstractModel::Handle handle, float magnification) {
    try {
      return m_repository->retrieve(handle)->setMagnification(magnification);
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  // Parameters
  void
  DocumentViewConfigService::handleEvent(std::shared_ptr<AbstractData::RepositoryEvent<AbstractDomain::IImage>> event) {
    if(auto p = dynamic_cast<AbstractData::Created<AbstractDomain::IImage> *>(event.get())) {
      handleCreatedEvent(p);
    } else if(auto p = dynamic_cast<AbstractData::Loaded<AbstractDomain::IImage> *>(event.get())) {
      handleLoadedEvent(p);
    } else if(auto p = dynamic_cast<AbstractData::Deleted<AbstractDomain::IImage> *>(event.get())) {
      handleDeletedEvent(p);
    }
  }

  void
  DocumentViewConfigService::handleCreatedEvent(AbstractData::Created<AbstractDomain::IImage> *event) {
    // TBA
  }

  void
  DocumentViewConfigService::handleLoadedEvent(AbstractData::Loaded<AbstractDomain::IImage> *event) {
    // TBA
  }

  void
  DocumentViewConfigService::handleDeletedEvent(AbstractData::Deleted<AbstractDomain::IImage> *event) {
    // TBA
  }
}
