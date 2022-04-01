#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEACCESSOR_TPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEACCESSOR_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageAccessor.tpp
 * PURPOSE: Implements the ImageAccessor template.
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

namespace SDF::Editor::DataLayer::Repositories {
  template<class ImageT, class IfaceT>
  ImageAccessor<ImageT, IfaceT>::ImageAccessor(ImageRepository<ImageT> *a_imageRepository)
    : m_imageRepository(a_imageRepository)
  {
  }

  template<class ImageT, class IfaceT>
  IfaceT *
  ImageAccessor<ImageT, IfaceT>::accessImage(Common::Handle a_imageHandle) {
    return m_imageRepository->retrieve(a_imageHandle);
  }
}

#endif
