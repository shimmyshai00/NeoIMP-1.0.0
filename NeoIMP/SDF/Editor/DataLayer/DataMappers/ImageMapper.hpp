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
#include "../../../Common/Data/ICrudable.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::DataLayer::DataMappers {
  // Class:      ImageMapper
  // Purpose:    Defines a data mapper for mapping NeoIMP images.
  // Parameters: FormatT - The traits/tag object for the format to deal in.
  template<class FormatT, class ImageT>
  class ImageMapper : public Common::Data::ICrudable<std::string, ImageT> {
  public:
    // Function:   ImageMapper
    // Purpose:    Construct the new data mapper.
    // Parameters: filesystemAdapter - The filesystem adapter to use.
    INJECT(ImageMapper(Common::Data::Adapters::IFilesystemAdapter *a_filesystemAdapter));

    bool
    has(std::string a_fileSpec);

    void
    create(std::string a_fileSpec, const ImageT &a_obj);

    void
    retrieve(std::string a_fileSpec, ImageT &a_obj);

    void
    update(std::string a_fileSpec, const ImageT &a_obj);

    void
    deleteO(std::string a_fileSpec);
  private:
    Common::Data::Adapters::IFilesystemAdapter *m_filesystemAdapter;
  };
}

#include "ImageMapper.tpp"

#endif
