/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageMapperFactory.cpp
 * PURPOSE: Implements the ImageMapperFactory class.
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

#include <ImageMapperFactory.hpp>

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <PNGImageMapper.hpp>

namespace SDF::DataLayer::Persistence {
  ImageMapperFactory::ImageMapperFactory(Interfaces::IGenerator<int> *uidGenerator)
    : m_uidGenerator(uidGenerator)
  {}

  std::unique_ptr<Repositories::AbstractPersistence::IDataMapper<ModelLayer::Services::AbstractDomain::IImage>>
  ImageMapperFactory::create(std::string fileSpec,
                             ModelLayer::AbstractData::ImageFileFormat fileFormat
                            )
  {
    if(fileFormat == ModelLayer::AbstractData::FILE_FORMAT_PNG) {
      return std::make_unique<PNGImageMapper>(fileSpec, m_uidGenerator);
    } else {
      throw DataLayer::Exceptions::BadFileFormatException(fileFormat);
    }
  }
}
