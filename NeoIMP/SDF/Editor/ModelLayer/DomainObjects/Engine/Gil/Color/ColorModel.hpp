#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_COLORMODEL_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_COLORMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorModel.hpp
 * PURPOSE: Defines the ColorModel template.
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

#include "../../IBidirectionalColorModel.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Color {
  // Class:      ColorModel
  // Purpose:    Defines a generic color model for the Boost.GIL-based engine subsystem. This
  //             basically adapts a Boost.GIL pixel type into the broader NeoIMP color models and
  //             spaces framework.
  // Parameters: GilPixelT - The Boost.GIL pixel type.
  template<class GilPixelT>
  class ColorModel : public IBidirectionalColorModel<GilPixelT> {
  public:
    inline std::size_t
    getNumChannels() const;

    inline float
    getValueMin(std::size_t channel) const;

    inline float
    getValueMax(std::size_t channel) const;

    inline float
    getQuantizationStep(std::size_t channel) const;

    inline void
    pixelToValues(const GilPixelT &px, float *values) const;

    inline void
    valuesToPixel(const float *values, GilPixelT &px) const;
  };
}

#include "ColorModel.tpp"

#endif
