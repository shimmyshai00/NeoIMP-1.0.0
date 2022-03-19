#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEMAPPER_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEMAPPER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageMapper.hpp
 * PURPOSE: Defines the ImageMapper template.
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

#include "../../../Common/Data/Adapters/IFilesystemAdapter.hpp"
#include "../../../Common/Data/IDataMapper.hpp"
#include "../../ModelLayer/DomainObjects/Engine/Image.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::DataLayer::DataMappers {
  // Class:      ImageMapper
  // Purpose:    Defines a data mapper for mapping NeoIMP images.
  // Parameters: PersisterT - The type of persister to use (allows changing file format).
  //             ImageT - The image type.
  template<class PersisterT, class ImageT>
  class ImageMapper : public Common::Data::IDataMapper<std::string, ImageT> {
  public:
    // Function:   ImageMapper
    // Purpose:    Construct the new data mapper.
    // Parameters: filesystemAdapter - The filesystem adapter to use.
    INJECT(ImageMapper(Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter));

    bool
    has(std::string fileSpec);

    void
    insert(std::string fileSpec, ImageT &obj);

    void
    retrieve(std::string fileSpec, ImageT &obj);

    void
    update(std::string fileSpec, ImageT &obj);

    void
    erase(std::string fileSpec);
  private:
    Common::Data::Adapters::IFilesystemAdapter *m_filesystemAdapter;
  };
}

#include "ImageMapper.tpp"

#endif
