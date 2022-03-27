#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFRGB_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFRGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DefRGB.hpp
 * PURPOSE: Defines the DefRGB template.
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

#include "DefGenericSDR.hpp"
#include "EColorModel.hpp"

#include <cmath>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      DefRGB
  // Purpose:    Defines a convenience class for defining RGB color models.
  // Parameters: CM - The color model being defined.
  //             BitsR, BitsG, BitsB - The number of bits in each channel.
  template<EColorModle CM, class BitsR, class BitsG, class BitsB>
  class DefRGB : public DefGenericSDR<CM, BitsR, BitsG, BitsB> {
  public:
    DefRGB(int r, int g, int b) {
      setValue(0, r);
      setValue(1, g);
      setValue(2, b);
    }

    int
    r() const {
      return getValue(0);
    }

    int
    g() const {
      return getValue(1);
    }

    int
    b() const {
      return getValue(2);
    }

    void
    setR(int r) {
      setValue(0, r);
    }

    void
    setG(int g) {
      setValue(1, g);
    }

    void
    setB(int b) {
      setValue(2, b);
    }
  };
}

#endif
