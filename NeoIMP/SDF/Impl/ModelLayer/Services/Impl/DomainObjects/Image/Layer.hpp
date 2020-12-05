#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_LAYER_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_IMAGE_LAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Layer.hpp
 * PURPOSE: Definition of the image layer template.
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

#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/Raster.hpp>
#include <SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Math/Coord.hpp>

namespace SDF::Impl::ModelLayer::Servics::Impl::DomainObjects::Image {
  template<class PixelType, class AlphaType>
  class Layer {
  public:
    Layer(int width, int height);

    int getWidth() const;
    int getHeight() const;

    AlphaType getAlphaAt(Math::Coord<int> pos) const;
    PixelType getPixelAt(Math::Coord<int> pos) const;

    void setAlphaAt(Math::Coord<int> pos, AlphaType newValue);
    void setPixelAt(Math::Coord<int> pos, PixelType newValue);
  private:
    Raster<AlphaType> m_alphaChannel;
    Raster<PixelType> m_imageRaster;
  };
}

#include "SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Image/Layer.tpp"

#endif
