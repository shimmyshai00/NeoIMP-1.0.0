#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEFACTORY_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEFACTORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageFactory.tpp
 * PURPOSE: Implements the ImageFactory template.
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

#include "Components/Content/Background.hpp"
#include "../Image/Layer.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilSpecT>
  Image::Image<GilSpecT> *
  ImageFactory<GilSpecT>::create(
    std::string a_name,
    std::string a_fileSpec,
    ImageMeasure a_widthPx,
    ImageMeasure a_heightPx,
    float a_resolutionPpi,
    typename GilSpecT::bkg_pixel_t a_backgroundColor
  ) {
    auto bkgLayer = std::make_unique<Image::Layer<GilSpecT>>();
    auto bkgContent = std::make_unique<Components::Content::Background<GilSpecT>>(a_widthPx,
      a_heightPx, a_backgroundColor);

    bkgLayer->setContentComponent(std::move(bkgContent));

    auto img = new Image::Image<GilSpecT>(a_name, a_resolutionPpi);
    img->addLayer(std::move(bkgLayer));

    return img;
  }
}

#endif
