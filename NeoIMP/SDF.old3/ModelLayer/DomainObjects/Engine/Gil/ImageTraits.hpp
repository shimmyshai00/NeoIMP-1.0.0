#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGETRAITS_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGETRAITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageTraits.hpp
 * PURPOSE: Defines trait objects for different image types.
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

#include "../../../../UILayer/AbstractModel/Defs/EColorModel.hpp"
#include "../../../../UILayer/AbstractModel/Defs/EBitDepth.hpp"

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<typename ImageT>
  struct ImageTraits {};

  template<>
  struct ImageTraits<typename boost::gil::rgb8_image_t> {
    static const std::size_t numChannels = 3;
    static const UILayer::AbstractModel::Defs::EColorModel colorModel = UILayer::AbstractModel::Defs::COLOR_MODEL_RGB;
    static const UILayer::AbstractModel::Defs::EBitDepth bitDepth = UILayer::AbstractModel::Defs::BIT_DEPTH_8;
  };
}

#endif
