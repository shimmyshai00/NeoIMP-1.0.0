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

#include "../../../ModelLayer/DomainObjects/Engine/ColorSpaces/Maps/IEC61966_sRGB.hpp"
#include "../../../ModelLayer/DomainObjects/Engine/ColorSpaces/SDRIllumColorSpace.hpp"
#include "../../../ModelLayer/DomainObjects/Engine/ColorSpaces/IBidirectionalMapping.hpp"
#include "../../../UILayer/AbstractModel/Defs/Color/colorSpaceIds.hpp" // nb: reaching too far back?

namespace SDF::Editor::DataLayer::Repositories::Gil {
  template<class GilPixelT>
  BuiltinRgbColorSpaceRepository<GilPixelT>::BuiltinRgbColorSpaceRepository() {
    using namespace ModelLayer::AbstractData::Gil;
    using namespace ModelLayer::DomainObjects::Engine;
    using namespace UILayer::AbstractModel::Defs::Color;

    // Construct the color model.
    std::shared_ptr<IColorModel<GilPixelT>> cm(new Gil::ColorModel<GilPixelT>());

    // Construct the Mappings.
    typedef ColorSpaces::IBidirectionalMapping<ColorSpaces::Fundamental::XyzD65> map_t;
    typedef RgbColorSpace<GilPixelT> cs_t;

    // Define your mappings here.
    std::shared_ptr<map_t> map_iec61966_2_1_sRGB(new ColorSpaces::Maps::IEC61966_sRGB);

    // Define your color spaces here.
    m_colorSpaces[g_iec61966_2_1_sRGB] = cs_t(cm, map_iec61966_2_1_sRGB);
  }

  template<class GilPixelT>
  const RgbColorSpace<PixelDataT> &
  BuiltinRgbColorSpaceRepository<GilPixelT>::retrieve(std::string key) const {
    if(m_colorSpaces.find(key) == m_colorSpaces.end()) {
      throw Error::ObjectNotFoundException<Error::SafeString>(key.c_str());
    } else {
      return m_colorSpaces[key];
    }
  }
}

#endif
