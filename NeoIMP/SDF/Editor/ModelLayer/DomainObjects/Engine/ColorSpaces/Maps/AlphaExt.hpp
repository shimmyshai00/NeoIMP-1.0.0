#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_MAPS_ALPHAEXT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_MAPS_ALPHAEXT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AlphaExt.hpp
 * PURPOSE: Defines the AlphaExt template.
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

#include "../IMap.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::ColorSpaces::Maps {
  // Class:      AlphaExt
  // Purpose:    Extends a map to be able to "carry through" an alpha channel value. This will
  //             follow the usual color values in the arrays.
  // Parameters: MapT - The base map to extend. Must derive from IMap.
  template<template<class FundamentalTraitsT> class MapT>
  class AlphaExt : private MapT,
                   public IMap<Fundamental::AlphaExt<FundamentalTraitsT>>
  {
  public:
    inline std::size_t
    getNumInpVals() const {
      return MapT::getNumInpVals()+1;
    }

    inline void
    valsToFundamental(const float *vals, float *fs) const {
      MapT::valsToFundamental(vals, fs);
      fs[FundamentalTraitsT::num_channels+1] = vals[MapT::getNumInpVals()+1];
    }

    inline void
    fundamentalToVals(const float *fs, float *vals) const {
      MapT::fundamentalToVals(fs, vals);
      vals[MapT::getNumInpVals()+1] = fs[FundamentalTraitsT::num_channels+1];
    }
  };

  // Class:      AlphaSrcExt
  // Purpose:    Extends a map to accept an alpha channel on the source, but ignores (does not pass
  //             it through) it.
  // Parameters: MapT - The base map to extend. Must derive from IMap.
  template<template<class FundamentalTraitsT> class MapT>
  class AlphaSrcExt : private MapT {
  public:
    inline std::size_t
    getNumInpVals() const {
      return MapT::getNumInpVals()+1;
    }

    inline void
    valsToFundamental(const float *vals, float *fs) const {
      MapT::valsToFundamental(vals, fs);
    }

    inline void
    fundamentalToVals(const float *fs, float *vals) const {
      MapT::fundamentalToVals(fs, vals);
      vals[MapT::getNumInpVals()+1] = 1.0f;
    }
  };
}

#endif
