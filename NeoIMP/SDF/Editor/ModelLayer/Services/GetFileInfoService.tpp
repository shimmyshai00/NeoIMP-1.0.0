#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GETFILEINFOSERVICE_TPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GETFILEINFOSERVICE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetFileInfoService.tpp
 * PURPOSE: Implements the GetFileInfoService class.
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

#include "GetFileInfoService.hpp"

#include "file_format_map.hpp"

namespace SDF::Editor::ModelLayer::Services {
  template<class ImageT>
  GetFileInfoService<ImageT>::GetFileInfoService(
    AbstractData::IImageFileInfoRequester<ImageT> *a_fileInfoRequester
  )
    : m_fileInfoRequester(a_fileInfoRequester)
  {
  }

  template<class ImageT>
  bool
  GetFileInfoService<ImageT>::wasDocumentPreviouslySaved(Common::Handle a_imageHandle) {
    return m_fileInfoRequester->hasAssociatedFile(a_imageHandle);
  }

  template<class ImageT>
  std::string
  GetFileInfoService<ImageT>::getFileSpec(Common::Handle a_imageHandle) {
    return m_fileInfoRequester->getFileSpecById(a_imageHandle);
  }

  template<class ImageT>
  UILayer::AbstractModel::Defs::FileFormat
  GetFileInfoService<ImageT>::getFileFormat(Common::Handle a_imageHandle) {
    return g_fileFormatMapDLtoUL[m_fileInfoRequester->getFileFormatById(a_imageHandle)];
  }
}

#endif
