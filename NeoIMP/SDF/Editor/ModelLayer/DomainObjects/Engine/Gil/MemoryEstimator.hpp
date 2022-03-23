#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_MEMORYESTIMATOR_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_MEMORYESTIMATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MemoryEstimator.hpp
 * PURPOSE: Defines traits-like objects to get the memory required
 *          for a single layer of a prospectively-created Boost.GIL image.
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

#include "../../Exceptions.hpp"
#include "../Dimensions.hpp"
#include "ImageTypes.hpp"
#include "ImplTraits.hpp"

#include <cstddef>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil {
  template<class GilImplT>
  struct MemoryEstimator {
    static std::size_t
    singleLayerEstimate(ImageMeasure widthPx, ImageMeasure heightPx) {
      if((widthPx <= 0) || (heightPx <= 0)) {
        throw InvalidDimensionsException(widthPx, heightPx);
      } else {
        // NB: presumes boost::gil::image is contiguous in memory - needs to be checked, and may
        //     need further tweaking
        return static_cast<std::size_t>(widthPx) * heightPx *
          sizeof(typename GilImplT::bkg_pixel_t);
      }
    }
  };
}

#endif
