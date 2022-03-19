#ifndef SDF_DATALAYER_PERSISTENCE_PNGIMAGEMAPPER_HPP
#define SDF_DATALAYER_PERSISTENCE_PNGIMAGEMAPPER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PNGImageMapper.hpp
 * PURPOSE: Defines the PNGImageMapper class.
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

#include <SDF/Interfaces/IGenerator.hpp>
#include <SDF/DataLayer/Repositories/AbstractPersistence/IDataMapper.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>

#include <string>
#include <memory>

namespace SDF::DataLayer::Persistence {
  // Class:      PNGImageMapper
  // Purpose:    Maps image data to PNG format files.
  // Parameters: None.
  class PNGImageMapper : public Repositories::AbstractPersistence::IDataMapper<
                                  ModelLayer::Services::AbstractDomain::IImage
                                >
  {
  public:
    // Function:   PNGImageMapper
    // Purpose:    Construct a new data mapper for mapping to a given file.
    // Parameters: fileSpec - The file spec to the file to map to.
    //             uidGenerator - Pointer to the UID generator to use to generate the image domain object IDs.
    PNGImageMapper(std::string fileSpec,
                   Interfaces::IGenerator<int> *uidGenerator
                  );

    void
    persist(ModelLayer::Services::AbstractDomain::IImage *obj);

    std::unique_ptr<ModelLayer::Services::AbstractDomain::IImage>
    retrieve();
  private:
    std::string m_fileSpec;
    Interfaces::IGenerator<int> *m_uidGenerator;
  };
}

#endif
