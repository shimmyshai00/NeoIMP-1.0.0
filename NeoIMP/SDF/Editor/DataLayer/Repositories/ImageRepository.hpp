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

#include "../../../Common/Data/ICrudable.hpp"
#include "../../../Common/Handle.hpp"
#include "../../ModelLayer/DomainObjects/Engine/Image/Variant.hpp"
#include "../../ModelLayer/AbstractData/IImageRetainer.hpp"
#include "../../ModelLayer/AbstractData/IImageLoader.hpp"
#include "../../ModelLayer/AbstractData/IImageRetriever.hpp"
#include "../../ModelLayer/AbstractData/IImageAccessor.hpp"
#include "../../ModelLayer/AbstractData/IImagePersister.hpp"
#include "../../ModelLayer/AbstractData/IImageFileInfoRequester.hpp"
#include "Formats.hpp"

#include <string>
#include <memory>

namespace SDF::Editor::DataLayer::Repositories {
  // Class:      ImageRepository
  // Purpose:    Implements the IImageRepository interface.
  // Parameters: ImageT - The supported image type.
  template<class ImageT>
  class ImageRepository : public ModelLayer::AbstractData::IImageRetainer<ImageT>,
                          public ModelLayer::AbstractData::IImageLoader<ImageT>,
                          public ModelLayer::AbstractData::IImageRetriever<ImageT>,
                          public ModelLayer::AbstractData::IImagePersister<ImageT>,
                          public ModelLayer::AbstractData::IImageFileInfoRequester<ImageT>
  {
  public:
    INJECT(ImageRepository(
      ANNOTATED(Formats::PNG, Common::Data::ICrudable<std::string, ImageT> *) a_pngImageMapper
    ));

    Common::Handle
    retainImageAtAutoID(std::unique_ptr<ImageT> a_image);

    ImageT *
    retrieve(Common::Handle a_id);

    Common::Handle
    loadImageFromFile(std::string a_fileSpec, ModelLayer::AbstractData::EFormat a_fileFormat);

    void
    registerFileSpec(
      Common::Handle a_id,
      std::string a_fileSpec,
      ModelLayer::AbstractData::EFormat a_fileFormat
    );

    void
    persistImage(Common::Handle a_id);

    bool
    hasAssociatedFile(Common::Handle a_id) const;

    std::string
    getFileSpecById(Common::Handle a_id) const;

    ModelLayer::AbstractData::EFormat
    getFileFormatById(Common::Handle a_id) const;
  private:
    Common::Data::ICrudable<std::string, ImageT> *m_pngImageMapper;

    std::map<Common::Handle, std::unique_ptr<ImageT>> m_imageMap;
    std::map<Common::Handle, std::string> m_fileSpecMap;
    std::map<Common::Handle, ModelLayer::AbstractData::EFormat> m_fileFormatMap;

    Common::Handle
    getFirstFreeId() const;
  };
}

#include "ImageRepository.tpp"

#endif
