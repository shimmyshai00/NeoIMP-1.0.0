#ifndef SDF_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_HPP
#define SDF_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_HPP

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

#include "../../ModelLayer/AbstractData/IDataMapper.hpp"
#include "../Context/FileRegistry.hpp"

#include <fruit/fruit.h>

namespace SDF::DataLayer::DataMappers {
  // Class:      ImageVariantMapper
  // Purpose:    Defines a data mapper for mapping NeoIMP image variants.
  // Parameters: PersisterT - The type of persister to use (allows changing file format).
  //             ImageVariantT - The type of variant to persist.
  template<class PersisterT, class ImageVariantT>
  class ImageVariantMapper : public ModelLayer::AbstractData::IDataMapper<ImageVariantT> {
  public:
    // Function:   ImageVariantMapper
    // Purpose:    Construct the new data mapper.
    INJECT(ImageVariantMapper(Context::FileRegistry *fileRegistry));

    void
    insert(Common::Handle uid,
           ImageVariantT *entity
          );

    std::unique_ptr<ImageVariantT>
    retrieve(Common::Handle uid);

    void
    update(Common::Handle uid,
           ImageVariantT *entity
          );

    void
    erase(Common::Handle uid);
  private:
    Context::FileRegistry *m_fileRegistry;
  };
}

#include "ImageVariantMapper.tpp"

#endif
