#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_GIL_IMAGEFACTORY_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_GIL_IMAGEFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageFactory.hpp
 * PURPOSE: The factory for Boost GIL-based images.
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

#include <SDF/Impl/ModelLayer/Properties/ColorModel.hpp>
#include <SDF/Impl/ModelLayer/Properties/BitDepth.hpp>

#include <string>
#include <memory>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Image {
  class AbstractImage;

  namespace Gil {
    std::unique_ptr<AbstractImage> createImage(
      std::string imageName,
      int imageWidthPx, int imageHeightPx, float imageResolutionPpi,
      ModelLayer::Properties::ColorModel colorModel, ModelLayer::Properties::BitDepth bitDepth
    );
  }
}

#endif
