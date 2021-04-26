/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.cpp
 * PURPOSE: Implements the ImageRepository class.
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

#include <ImageRepository.hpp>

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <AbstractPersistence/IDataMapper.hpp>

#include <algorithm>

namespace SDF::DataLayer::Repositories {
  using namespace ModelLayer::Services;

  ImageRepository::ImageRepository(Interfaces::IFactory<AbstractPersistence::IDataMapper<ModelLayer::Services::AbstractDomain::IImage>, std::string, ModelLayer::AbstractData::ImageFileFormat> *mapperFactory)
    : m_mapperFactory(mapperFactory)
  {}

  void
  ImageRepository::attachObserver(
    Interfaces::IEventHandler<ModelLayer::AbstractData::RepositoryEvent<AbstractDomain::IImage>> *observer
  ) {
    m_observers.push_back(observer);
  }

  void
  ImageRepository::removeObserver(
    Interfaces::IEventHandler<ModelLayer::AbstractData::RepositoryEvent<AbstractDomain::IImage>> *observer
  ) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }

  void
  ImageRepository::create(std::unique_ptr<AbstractDomain::IImage> object) {
    using AbstractDomain::IImage;

    int objectId(object->getId());

    m_objectMap[objectId] = std::move(object);

    std::shared_ptr<ModelLayer::AbstractData::Created<IImage>>
      event(new ModelLayer::AbstractData::Created<IImage>);
    event->objectId = objectId;

    for(auto observer : m_observers) {
      observer->handleEvent(event);
    }
  }

  AbstractDomain::IImage *
  ImageRepository::retrieve(int objectId) {
    if(m_objectMap.find(objectId) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      return m_objectMap[objectId].get();
    }
  }

  void
  ImageRepository::update(AbstractDomain::IImage *object) {
    if(m_objectMap.find(object->getId()) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(object->getId());
    } else {
      // TBA
    }
  }

  std::unique_ptr<AbstractDomain::IImage>
  ImageRepository::deleteEntry(int objectId) {
    if(m_objectMap.find(objectId) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      m_objectMap.erase(objectId);
    }
  }

  void
  ImageRepository::assignFileSpec(int id,
                                  std::string fileSpec
                                 )
  {
    if(m_objectMap.find(id) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(id);
    } else {
      m_fileSpecMap[id] = fileSpec;
    }
  }

  void
  ImageRepository::setFileFormat(int id,
                                 ModelLayer::AbstractData::ImageFileFormat fileFormat
                                )
  {
    if(m_objectMap.find(id) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(id);
    } else {
      m_fileFormatMap[id] = fileFormat;
    }
  }

  void
  ImageRepository::persist(int id) {
    if((m_fileSpecMap.find(id) == m_fileSpecMap.end()) ||
       (m_fileFormatMap.find(id) == m_fileFormatMap.end()))
    {
      throw DataLayer::Exceptions::IncompletePersistenceSpecException(id);
    } else {
      std::unique_ptr<AbstractPersistence::IDataMapper<AbstractDomain::IImage>>
        mapper(m_mapperFactory->create(m_fileSpecMap[id], m_fileFormatMap[id]));

      printf("persisting %s...\n", m_fileSpecMap[id].c_str());
      mapper->persist(m_objectMap[id].get());
    }
  }

  int
  ImageRepository::load(std::string fileSpec,
                        ModelLayer::AbstractData::ImageFileFormat fileFormat
                       )
  {
    std::unique_ptr<AbstractPersistence::IDataMapper<AbstractDomain::IImage>>
      mapper(m_mapperFactory->create(fileSpec, fileFormat));

    printf("loading %s...\n", fileSpec.c_str());
    std::unique_ptr<AbstractDomain::IImage> obj(mapper->retrieve());
    std::size_t objectId(obj->getId());
    m_fileSpecMap[objectId] = fileSpec;
    m_fileFormatMap[objectId] = fileFormat;
    m_objectMap[objectId] = std::move(obj);

    std::shared_ptr<ModelLayer::AbstractData::Loaded<AbstractDomain::IImage>>
      event(new ModelLayer::AbstractData::Loaded<AbstractDomain::IImage>);
    event->objectId = objectId;

    for(auto observer : m_observers) {
      observer->handleEvent(event);
    }

    return objectId;
  }
}
