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

#include <ImageFactory.hpp>

#include <AbstractImage.hpp>

#include <GilImage.hpp>

#include <Framework/Handle.hpp>

#include <boost/gil/extension/dynamic_image/any_image_view.hpp>
#include <boost/gil/image_view.hpp>
#include <boost/gil.hpp>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Image::Gil {
  std::unique_ptr<AbstractImage> createImage(
    std::string imageName,
    int imageWidthPx, int imageHeightPx, float imageResolutionPpi,
    UILayer::AbstractModel::Properties::ColorModel colorModel, UILayer::AbstractModel::Properties::BitDepth bitDepth
  ) {
    using namespace UILayer::AbstractModel::Properties;

    static Framework::Handle nextImageId(0);

    if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_8)) {
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray8_image_t, boost::gil::rgb8_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_10)) {
      // NB: need to support more refined bit depth formats
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray16_image_t, boost::gil::rgb16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_12)) {
      // NB: need to support more refined bit depth formats
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray16_image_t, boost::gil::rgb16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_16)) {
      // NB: need to support more refined bit depth formats
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray16_image_t, boost::gil::rgb16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_8)) {
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray8_image_t, boost::gil::cmyk16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_10)) {
      // NB: need to support more refined bit depth formats
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray16_image_t, boost::gil::cmyk16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_12)) {
      // NB: need to support more refined bit depth formats
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray16_image_t, boost::gil::cmyk16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_16)) {
      // NB: need to support more refined bit depth formats
      return std::unique_ptr<AbstractImage>(new GilImage<boost::gil::gray16_image_t, boost::gil::cmyk16_image_t>(
        nextImageId++, imageName, imageWidthPx, imageHeightPx, imageResolutionPpi
      ));
    }
  }
}
