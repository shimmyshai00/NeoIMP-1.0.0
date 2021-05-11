/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentCreationService.cpp
 * PURPOSE: Implements the DocumentCreationService class.
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

#include <DocumentCreationService.hpp>

#include <AbstractData/IRepository.hpp>
#include <AbstractDomain/IObjectMap.hpp>

#include <AbstractDomain/IImage.hpp>
#include <AbstractDomain/IDeltaEditor.hpp>

#include <BrokerId.hpp>

namespace SDF::ModelLayer::Services {
  DocumentCreationService::DocumentCreationService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                                   AbstractDomain::IObjectMap<AbstractDomain::IImage,
                                                                              AbstractDomain::IDeltaEditor
                                                                             > *deltaEditorMap,
                                                   Interfaces::IFactory<AbstractDomain::IImage,
                                                                        AbstractDomain::DocumentSpec
                                                                       > *imageFactory,
                                                   Interfaces::IFactory<AbstractDomain::IDeltaEditor,
                                                                        AbstractDomain::IImage *
                                                                       > *deltaEditorFactory,
                                                   Interfaces::IMessageBroker<
                                                    Events::RepositoryUpdate<AbstractDomain::IImage>
                                                   > *messageBroker
                                                  )
    : m_imageRepository(imageRepository),
      m_deltaEditorMap(deltaEditorMap),
      m_imageFactory(imageFactory),
      m_deltaEditorFactory(deltaEditorFactory),
      m_messageBroker(nullptr)
  {
    messageBroker->addPublisher(this);
  }

  DocumentCreationService::~DocumentCreationService() {
    m_messageBroker->removePublisher(this);
  }

  void
  DocumentCreationService::createDocument(int documentWidthPx,
                                          int documentHeightPx,
                                          float documentResolutionPpi,
                                          UILayer::AbstractModel::Properties::ColorModel colorModel,
                                          UILayer::AbstractModel::Properties::BitDepth bitDepth
                                         )
  {
    using namespace UILayer::AbstractModel;

    AbstractDomain::DocumentSpec spec {
      "Untitled",
      documentWidthPx,
      documentHeightPx,
      documentResolutionPpi,
      colorModel,
      bitDepth
    };

    std::unique_ptr<AbstractDomain::IImage> newImage(m_imageFactory->create(spec));
    std::unique_ptr<AbstractDomain::IDeltaEditor> newImageEditor(m_deltaEditorFactory->create(newImage.get()));

    AbstractDomain::IImage *newImagePtr(newImage.get());

    m_imageRepository->create(std::move(newImage));
    m_deltaEditorMap->linkTo(newImagePtr, std::move(newImageEditor));

    std::shared_ptr<Events::Created<AbstractDomain::IImage>> event(new Events::Created<AbstractDomain::IImage>);
    event->objectId = newImagePtr->getId();
    m_messageBroker->receiveMessage(this, event);
  }

  // Private members.
  int
  DocumentCreationService::getUid() const {
    return SERVICE_DOCUMENT_CREATION;
  }

  void
  DocumentCreationService::setBroker(
    Interfaces::IMessageBroker<Events::RepositoryUpdate<AbstractDomain::IImage>> *broker
  ) {
    m_messageBroker = broker;
  }
}
