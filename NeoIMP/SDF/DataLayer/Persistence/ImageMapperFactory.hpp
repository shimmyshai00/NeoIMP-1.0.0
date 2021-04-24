#ifndef SDF_DATALAYER_PERSISTENCE_IMAGEMAPPERFACTORY_HPP
#define SDF_DATALAYER_PERSISTENCE_IMAGEMAPPERFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageMapperFactory.hpp
 * PURPOSE: Defines the ImageMapperFactory class.
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

#include <SDF/Interfaces/IFactory.hpp>

#include <SDF/DataLayer/Repositories/AbstractPersistence/IDataMapper.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>

#include <SDF/ModelLayer/AbstractData/ImageFileFormat.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <string>

namespace SDF::DataLayer::Persistence {
  // Class:      ImageMapperFactory
  // Purpose:    Construct image data mapper objects.
  // Parameters: None.
  class ImageMapperFactory : public Interfaces::IFactory<Repositories::AbstractPersistence::IDataMapper<
                                                          ModelLayer::Services::AbstractDomain::IImage
                                                         >,
                                                         std::string,
                                                         ModelLayer::AbstractData::ImageFileFormat
                                                        >
  {
  public:
    INJECT(ImageMapperFactory());

    std::unique_ptr<Repositories::AbstractPersistence::IDataMapper<ModelLayer::Services::AbstractDomain::IImage>>
    create(std::string fileSpec,
           ModelLayer::AbstractData::ImageFileFormat fileFormat
          );
  };
}

#endif
