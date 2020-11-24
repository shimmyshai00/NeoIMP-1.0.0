/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DefaultImageAssembler.tpp
 * PURPOSE: Implementation of the DefaultImageAssembler template.
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

#include <SDF/ModelLayer/Entity/DefaultImageAssembler.hpp>
#include <SDF/ModelLayer/Entity/ImageDto.hpp>

namespace SDF::ModelLayer::Entity {
  template<class ImageType>
  DefaultImageAssembler::DefaultImageAssembler() {}

  template<class ImageType>
  DefaultImageAssembler::~DefaultImageAssembler() {}

  template<class ImageType>
  std::unique_ptr<ImageDto<ImageType>> DefaultImageAssembler::createDtoFrom(ImageType &image) {
    std::unique_ptr<ImageDto<ImageType>> rv(new ImageDto<ImageType>);
    rv->m_imagePtr = &image;

    return rv;
  }

  template<class ImageType>
  ImageType *DefaultImageAssembler::unwrapDto(ImageDto<ImageType> &imageDto) {

  }
}
