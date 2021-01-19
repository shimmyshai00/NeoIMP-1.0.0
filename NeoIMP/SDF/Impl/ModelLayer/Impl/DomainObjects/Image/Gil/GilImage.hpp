#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_GIL_IMPL_GILIMAGE_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_GIL_IMPL_GILIMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilImage.hpp
 * PURPOSE: The image glue template for the Boost GIL.
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Image/AbstractImage.hpp>
#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Image/Gil/GilLayer.hpp>
#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Math/Rect.hpp>

#include <string>
#include <cstdlib>
#include <vector>
#include <memory>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Image {
  class ImageDataVisitor;

  namespace Gil {
    template<class GilAlphaType, class GilImageType>
    class GilImage : public AbstractImage {
    public:
      GilImage(std::string imageName, std::size_t imageWidthPx, std::size_t imageHeightPx, float imageResolutionPpi);
      ~GilImage();

      std::string getImageName() const;

      std::size_t getImageWidth() const;
      std::size_t getImageHeight() const;
      Math::Rect<std::size_t> getImageRect() const;
      float getImageResolutionPpi() const;

      ModelLayer::Properties::ColorModel getColorModel() const;
      ModelLayer::Properties::BitDepth getBitDepth() const;

      std::size_t getNumImageLayers() const;

      void setImageName(std::string newImageName);

      void addNewLayer(std::size_t layerNumToInsertBefore);
      void deleteLayer(std::size_t layerNum);

      void acceptLayerAlphaVisitor(std::size_t layerNum, Math::Rect<std::size_t> rect, ImageDataVisitor *visitor);
      void acceptLayerPixelVisitor(std::size_t layerNum, Math::Rect<std::size_t> rect, ImageDataVisitor *visitor);
    private:
      std::string m_imageName;

      std::size_t m_imageWidthPx;
      std::size_t m_imageHeightPx;
      float m_imageResolutionPpi;

      std::vector<std::unique_ptr<GilLayer<GilAlphaType, GilImageType>>> m_layers;
    };
  }
}

#include "SDF/Impl/ModelLayer/Impl/DomainObjects/Image/Gil/GilImage.tpp"

#endif
