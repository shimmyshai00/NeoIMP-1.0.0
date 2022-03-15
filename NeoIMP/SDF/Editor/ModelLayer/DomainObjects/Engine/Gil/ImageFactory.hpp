#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEFACTORY_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageFactory.hpp
 * PURPOSE: Defines the ImageFactory template.
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

#include "../../../../../Common/IFactory.hpp"
#include "../Image.hpp"
#include "ImageTypes.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      ImageFactory
  // Purpose:    Provides a simple factory method for creating fresh images of a given type.
  // Parameters: GilSpecT - The image implementation spec traits.
  template<class GilSpecT>
  class ImageFactory : public Common::IFactory<
    Image<GilSpecT>,
    std::string,
    std::string,
    ImageMeasure,
    ImageMeasure,
    float,
    typename GilSpecT::bkg_pixel_t
  > {
  public:
    Image<GilSpecT> *
    create(std::string name,
           std::string fileSpec,
           ImageMeasure widthPx,
           ImageMeasure heightPx,
           float resolutionPpi,
           typename GilSpecT::bkg_pixel_t backgroundColor
          );
  };
}

#include "ImageFactory.tpp"

#endif
