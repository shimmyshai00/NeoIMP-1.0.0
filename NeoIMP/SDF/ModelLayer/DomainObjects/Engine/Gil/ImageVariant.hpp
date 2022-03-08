#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEVARIANT_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEVARIANT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariant.hpp
 * PURPOSE: Defines the ImageVariant template.
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

#include "../IImage.hpp"
#include "../Dimensions.hpp"

#include <boost/variant2/variant.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      ImageVariant
  // Purpose:    Defines a variant image type. This permits storing images of different data types
  //             in the same one. This is like boost::gil::any_image; but unfortunately we can't
  //             easily  use that directly due to our multilayer support. This, however, replicates
  //             the same idea.
  // Parameters: ImageTs - The NeoIMP (not GIL directly, but MUST be of type Gil::Image<>) image
  //                       types going into the variant.
  template<class ... ImageTs>
  class ImageVariant : public boost::variant2::variant<ImageTs...>,
                       public IImage
  {
  public:
    template<typename T>
    ImageVariant(const T& image);

    template<typename T>
    ImageVariant(T&& image);

    std::string
    getName() const;

    std::string
    getFileSpec() const;

    ImageMeasure
    getWidthPx() const;

    ImageMeasure
    getHeightPx() const;

    float
    getResolutionPpi() const;

    const IColorModel &
    getBkgColorModel() const;

    const IColorModel &
    getColorModel() const;

    std::size_t
    getNumLayers() const;

    ImageMeasure
    getLayerWidthPx(std::size_t which) const;

    ImageMeasure
    getLayerHeightPx(std::size_t which) const;

    ImageRect
    getLayerRect(std::size_t which) const;
  };
}

#include "ImageVariant.tpp"

#endif
