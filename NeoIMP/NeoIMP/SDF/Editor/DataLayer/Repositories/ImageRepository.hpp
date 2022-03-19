#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEREPOSITORY_HPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.hpp
 * PURPOSE: Defines the ImageRepository template.
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

#include "../../../Common/Data/IDataMapper.hpp"
#include "../../../Common/Handle.hpp"
#include "../../ModelLayer/DomainObjects/Engine/ImageVariant.hpp"
#include "../../ModelLayer/AbstractData/IImageRepository.hpp"
#include "Formats.hpp"

#include <string>
#include <memory>

namespace SDF::Editor::DataLayer::Repositories {
  // Class:      ImageRepository
  // Purpose:    Implements the IImageRepository interface.
  // Parameters: ImageT - The supported image type.
  template<class ImageT>
  class ImageRepository : public ModelLayer::AbstractData::IImageRepository<ImageT> {
  public:
    INJECT(ImageRepository(
      ANNOTATED(Formats::PNG, Common::Data::IDataMapper<std::string, ImageT> *) pngImageMapper
    ));

    ImageT *
    getImage(Common::Handle id);

    void
    insertImage(Common::Handle id, std::unique_ptr<ImageT> image);

    void
    persistImage(Common::Handle id);

    Common::Handle
    loadImageFromFile(std::string fileSpec, ModelLayer::AbstractData::EFormat fileFormat);

    void
    registerFileSpec(
      Common::Handle id,
      std::string fileSpec,
      ModelLayer::AbstractData::EFormat fileFormat
    );
  private:
    Common::Data::IDataMapper<std::string, ImageT> *m_pngImageMapper;

    std::map<Common::Handle, std::unique_ptr<ImageT>> m_imageMap;
    std::map<Common::Handle, std::string> m_fileSpecMap;
    std::map<Common::Handle, ModelLayer::AbstractData::EFormat> m_fileFormatMap;
  };
}

#include "ImageRepository.tpp"

#endif