#ifndef SDF_DATALAYER_DATAMAPPERS_GIL_IMAGEMAPPER_HPP
#define SDF_DATALAYER_DATAMAPPERS_GIL_IMAGEMAPPER_HPP

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

#include "../../../ModelLayer/AbstractData/Entity/Gil/Image.hpp"
#include "../../../ModelLayer/AbstractData/Entity/Gil/ImageVariant.hpp"
#include "../../../ModelLayer/AbstractData/IDataMapper.hpp"
#include "../../Context/FileRegistry.hpp"

#include <fruit/fruit.h>

namespace SDF::DataLayer::DataMappers::Gil {
  // Class:      ImageMapper
  // Purpose:    Defines a data mapper for mapping Boost.GIL-based NeoIMP images.
  // Parameters: ImageEntityT - The image entity type (either Image or ImageVariant from
  //                            ModelLayer::AbstractData::Entity::Gil).
  //             PersisterT - The type of persister to use (allows changing file format).
  template<class ImageEntityT, class PersisterT>
  class ImageMapper : public ModelLayer::AbstractData::IDataMapper<ImageEntityT> {
  public:
    // Function:   ImageMapper
    // Purpose:    Construct the new data mapper.
    INJECT(ImageMapper(Context::FileRegistry *fileRegistry));

    void
    insert(Common::Handle uid, ImageEntityT *entity);

    std::unique_ptr<ImageEntityT>
    retrieve(Common::Handle uid);

    void
    update(Common::Handle uid, ImageEntityT *entity);

    void
    erase(Common::Handle uid);
  private:
    Context::FileRegistry *m_fileRegistry;
  };
}

namespace SDF::DataLayer::DataMappers::Gil {
  // Conveniene typedefs.
  template<class GilBkgImageT, class GilImageT, class PersisterT>
  using SingleImageMapper =
    ImageMapper<ModelLayer::AbstractData::Entity::Gil::Image<GilBkgImageT, GilImageT>, PersisterT>;

  template<class ... ImageEntityTs, class PersisterT>
  using MultiImageMapper =
    ImageMapper<ModelLayer::AbstractData::Entity::Gil::ImageVariant<ImageEntityTs...>, PersisterT>;
}

#include "ImageMapper.tpp"

#endif
