#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_DEFS_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_DEFS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Defs.hpp
 * PURPOSE: Provides type definitions for the UI-facing color spaces.
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

#include "../../DomainObjects/Engine/ColorSpaces/Fundamental/XyzD65.hpp"
#include "../../DomainObjects/Engine/ColorSpaces/Maps/IEC61966_sRGB.hpp"
#include "UiAutoSpace.hpp"

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  // Types. Note - no constants, since auto spaces are dynamic.
  typedef UiAutoSpace<
    DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65,
    DomainObjects::Engine::ColorSpaces::Maps::IEC61966_sRGB
  > UIAssumed_sRGB;
}

#endif
