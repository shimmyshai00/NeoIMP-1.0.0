#ifndef SDF_EDITOR_DATALAYE_REPOSITORIES_IMAGEACCESSOR_HPP
#define SDF_EDITOR_DATALAYE_REPOSITORIES_IMAGEACCESSOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageAccessor.hpp
 * PURPOSE: Defines the ImageAccessor template.
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
#include "../../ModelLayer/AbstractData/IImageAccessor.hpp"
#include "ImageRepository.hpp"

#include <string>
#include <memory>

namespace SDF::Editor::DataLayer::Repositories {
  // Class:      ImageAccessor
  // Purpose:    Implements the IImageAccessor interface.
  // Parameters: ImageT - The supported image type.
  //             IfaceT - The interface type to access it as.
  template<class ImageT, class IfaceT>
  class ImageAccessor : public ModelLayer::AbstractData::IImageAccessor<IfaceT> {
  public:
    INJECT(ImageAccessor(ImageRepository<ImageT> *imageRepository));

    IfaceT *
    accessImage(Common::Handle imageHandle);
  private:
    ImageRepository<ImageT> *m_imageRepository;
  };
}

#include "ImageAccessor.tpp"

#endif
