#ifndef SDF_DATALAYER_REPOSITORIES_IMAGEREPOSITORY_HPP
#define SDF_DATALAYER_REPOSITORIES_IMAGEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.hpp
 * PURPOSE: Defines the ImageRepository class.
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

#include <SDF/ModelLayer/AbstractData/IObservableRepository.hpp>
#include <SDF/ModelLayer/AbstractData/IRepository.hpp>
#include <SDF/ModelLayer/AbstractData/IFileSystemPersistenceController.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>
#include <SDF/ModelLayer/AbstractData/ImageFileFormat.hpp>

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/Interfaces/IFactory.hpp>

#include <SDF/ModelLayer/AbstractData/RepositoryEvent.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <map>
#include <vector>
#include <string>

namespace SDF::DataLayer::Repositories {
  namespace AbstractPersistence {
    template<class T>
    class IDataMapper;
  }

  // Class:      ImageRepository
  // Purpose:    Defines the in-memory repository for image objects.
  // Parameters: None.
  class ImageRepository : public ModelLayer::AbstractData::IObservableRepository<ModelLayer::Services::AbstractDomain::IImage>,
                          public ModelLayer::AbstractData::IFileSystemPersistenceController<ModelLayer::Services::AbstractDomain::IImage,
                                                                                            ModelLayer::AbstractData::ImageFileFormat
                                                                                           > {
  public:
    static constexpr const char *c_createWhat = "create";
    static constexpr const char *c_updateWhat = "update";
    static constexpr const char *c_deleteWhat = "delete";
  public:
    INJECT(ImageRepository(Interfaces::IFactory<AbstractPersistence::IDataMapper<ModelLayer::Services::AbstractDomain::IImage>, std::string, ModelLayer::AbstractData::ImageFileFormat> *mapperFactory));

    void
    attachObserver(Interfaces::IEventHandler<ModelLayer::AbstractData::RepositoryEvent<ModelLayer::Services::AbstractDomain::IImage>> *observer);

    void
    removeObserver(Interfaces::IEventHandler<ModelLayer::AbstractData::RepositoryEvent<ModelLayer::Services::AbstractDomain::IImage>> *observer);

    void
    create(std::unique_ptr<ModelLayer::Services::AbstractDomain::IImage> object);

    ModelLayer::Services::AbstractDomain::IImage *
    retrieve(int objectId);

    void
    update(ModelLayer::Services::AbstractDomain::IImage *object);

    std::unique_ptr<ModelLayer::Services::AbstractDomain::IImage>
    deleteEntry(int objectId);

    void
    assignFileSpec(int id,
                   std::string fileSpec
                  );

    void
    setFileFormat(int id,
                  ModelLayer::AbstractData::ImageFileFormat fileFormat
                 );

    void
    persist(int id);

    int
    load(std::string fileSpec,
         ModelLayer::AbstractData::ImageFileFormat fileFormat
        );
  private:
    Interfaces::IFactory<AbstractPersistence::IDataMapper<ModelLayer::Services::AbstractDomain::IImage>, std::string, ModelLayer::AbstractData::ImageFileFormat> *m_mapperFactory;

    std::map<int, std::unique_ptr<ModelLayer::Services::AbstractDomain::IImage>> m_objectMap;

    std::map<int, std::string> m_fileSpecMap;
    std::map<int, ModelLayer::AbstractData::ImageFileFormat> m_fileFormatMap;

    std::vector<Interfaces::IEventHandler<ModelLayer::AbstractData::RepositoryEvent<ModelLayer::Services::AbstractDomain::IImage>> *> m_observers;
  };
}

#endif
