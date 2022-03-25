#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_GIL_BUILTINRGBCOLORSPACEREPOSITORY_TPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_GIL_BUILTINRGBCOLORSPACEREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BuiltinRgbColorSpaceRepository.tpp
 * PURPOSE: Implements the BuiltinRgbColorSpaceRepository template.
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

namespace SDF::Editor::DataLayer::Repositories::Gil {
  template<class GilPixelT>
  BuiltinRgbColorSpaceRepository<GilPixelT>::BuiltinRgbColorSpaceRepository() {
    using namespace ModelLayer::DomainObjects::Engine;

    m_colorSpaces.push_back(
      ColorSpaces::SDRColorSpace<GilPixelT, ColorSpaces::Fundamental::XyzD65>(&m_iec61966_2_1_sRGB)
    );
  }

  template<class GilPixelT>
  ModelLayer::DomainObjects::Engine::IColorSpace<
    GilPixelT,
    ModelLayer::DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
  > *
  BuiltinRgbColorSpaceRepository<GilPixelT>::retrieve(
    ModelLayer::AbstractData::EBuiltinRgbColorSpace id
  ) {
    return &m_colorSpaces[id];
  }
}

#endif
