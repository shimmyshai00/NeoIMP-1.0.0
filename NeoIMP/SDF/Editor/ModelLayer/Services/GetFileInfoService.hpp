#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GETFILEINFOSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GETFILEINFOSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetFileInfoService.hpp
 * PURPOSE: Defines the GetFileInfoService class.
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

#include "../../../Common/Handle.hpp"
#include "../../UILayer/AbstractModel/Defs/FileFormat.hpp"
#include "../../UILayer/AbstractModel/Storage/IGetDocumentFileInfoService.hpp"
#include "../AbstractData/IImageFileInfoRequester.hpp"

namespace SDF::Editor::ModelLayer::Services {
  // Class:      GetFileInfoService
  // Purpose:    Provides a service for getting the file information about saved images.
  // Parameters: ImageT - The image type in the repository.
  template<class ImageT>
  class GetFileInfoService : public UILayer::AbstractModel::Storage::IGetDocumentFileInfoService {
  public:
    INJECT(GetFileInfoService(AbstractData::IImageFileInfoRequester<ImageT> *a_fileInfoRequester));

    bool
    wasDocumentPreviouslySaved(Common::Handle a_imageHandle);

    std::string
    getFileSpec(Common::Handle a_imageHandle);

    UILayer::AbstractModel::Defs::FileFormat
    getFileFormat(Common::Handle a_imageHandle);
  private:
    AbstractData::IImageFileInfoRequester<ImageT> *m_fileInfoRequester;
  };
}

#include "GetFileInfoService.tpp"

#endif
