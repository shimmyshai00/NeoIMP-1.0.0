#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_INORMALIZER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_INORMALIZER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    INormalizer.hpp
 * PURPOSE: Defines the INormalizer interface.
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

#include "IFwdNormalizer.hpp"
#include "IRevNormalizer.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Color {
  // Class:      INormalizer
  // Purpose:    Unifies the other two normalizer interfaces into a bidirectional interface.
  // Parameters: ColorModelT - The color model (in Models) used.
  //             PixelDataT - The type of pixel data accepted.
  template<class ColorModelT, class PixelDataT>
  class INormalizer : public IFwdNormalizer<ColorModelT, PixelDataT>,
                      public IRevNormalizer<ColorModelT, PixelDataT>
  {
  };
}

#endif
