#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariantMapper.hpp
 * PURPOSE: Defines the ImageVariantMapper template.
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
  // Class:      ImageVariantMapper
  // Purpose:    Defines a data mapper for mapping NeoIMP image variants.
  // Parameters: PersisterT - The type of persister to use (allows changing file format).
  //             ImageVariantT - The image variant type itself.
  template<class PersisterT, class ImageVariantT>
  class ImageVariantMapper : public Common::Data::IDataMapper<std::string, ImageVariantT> {
  public:
    // Function:   ImageMapper
    // Purpose:    Construct the new data mapper.
    // Parameters: filesystemAdapter - The filesystem adapter to use.
    INJECT(ImageVariantMapper(Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter));

    bool
    has(std::string fileSpec);

    void
    insert(std::string fileSpec, ImageVariantT &obj);

    void
    retrieve(std::string fileSpec, ImageVariantT &obj);

    void
    update(std::string fileSpec, ImageVariantT &obj);

    void
    erase(std::string fileSpec);
  private:
    Common::Data::Adapters::IFilesystemAdapter *m_filesystemAdapter;
  };
}

#include "ImageVariantMapper.tpp"

#endif
