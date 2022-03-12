#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_BACKGROUNDLAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_BACKGROUNDLAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BackgroundLayer.hpp
 * PURPOSE: Defines the BackgroundLayer template.
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

#include "../Components/IContent.hpp"
#include "../Dimensions.hpp"
#include "../Layer.hpp"
#include "Components/Raster.hpp"

#include <memory>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      BackgroundLayer
  // Purpose:    Defines a Boost.GIL-based background layer.
  // Parameters: GilSpecT - The GIL implementation traits spec.
  template<class GilSpecT>
  class BackgroundLayer : public Layer<GilSpecT> {
  public:
    // Function:   BackgroundLayer
    // Purpose:    Constructs a new layer to the specified parameters.
    // Parameters: widthPx - The width of the layer in pixels.
    //             heightPx - The height of the layer in pixels.
    //             bkgColor - The color of the new layer.
    BackgroundLayer(ImageMeasure widthPx,
                    ImageMeasure heightPx,
                    typename GilSpecT::bkg_pixel_t bkgColor
                   );

    Engine::Components::IContent<GilSpecT> *
    getContentComponent();

    const Engine::Components::IContent<GilSpecT> *
    getContentComponent() const;
  private:
    std::unique_ptr<Components::BackgroundRaster<GilSpecT>> m_content;
  };
}

#include "BackgroundLayer.tpp"

#endif
