#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_ABSTRACTIMAGE_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_ABSTRACTIMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AbstractImage.hpp
 * PURPOSE: The abstract common base interface for the image domain object type.
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

#include <SDF/Impl/ModelLayer/Color/ColorModels.hpp>
#include <SDF/Impl/ModelLayer/Color/BitDepths.hpp>

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Math/Rect.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Image {
  class ImageDataVisitor;

  class AbstractImage {
  public:
    virtual ~AbstractImage() = default;

    virtual std::size_t getImageWidth() const = 0;
    virtual std::size_t getImageHeight() const = 0;
    virtual Math::Rect<std::size_t> getImageRect() const = 0;
    virtual float getImageResolutionPpi() const = 0;

    virtual ModelLayer::Color::ColorModel getColorModel() const = 0;
    virtual ModelLayer::Color::BitDepth getBitDepth() const = 0;

    virtual std::size_t getNumImageLayers() const = 0;

    virtual void addNewLayer(std::size_t layerNumToInsertBefore) = 0;
    virtual void deleteLayer(std::size_t layerNum) = 0;

    virtual void acceptLayerAlphaVisitor(
      std::size_t layerNum,
      Math::Rect<std::size_t> rect,
      ImageDataVisitor *visitor
    ) = 0;

    virtual void acceptLayerPixelVisitor(
      std::size_t layerNum,
      Math::Rect<std::size_t> rect,
      ImageDataVisitor *visitor
    ) = 0;
  };
}

#endif
