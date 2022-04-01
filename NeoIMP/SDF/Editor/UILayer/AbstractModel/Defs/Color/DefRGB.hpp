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
#include "ColorFormat.hpp"

#include <cmath>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      DefRGB
  // Purpose:    Defines a convenience class for defining RGB color formats.
  // Parameters: CF - The color format being defined.
  //             BitsR, BitsG, BitsB - The number of bits in each channel.
  template<ColorFormat CF, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  class DefRGB : public DefGenericSDR<CF, BitsR, BitsG, BitsB> {
  public:
    DefRGB(int a_r, int a_g, int a_b) {
      this->setValue(0, a_r);
      this->setValue(1, a_g);
      this->setValue(2, a_b);
    }

    int
    r() const {
      return this->getValue(0);
    }

    int
    g() const {
      return this->getValue(1);
    }

    int
    b() const {
      return this->getValue(2);
    }

    void
    setR(int a_r) {
      this->setValue(0, a_r);
    }

    void
    setG(int a_g) {
      this->setValue(1, a_g);
    }

    void
    setB(int a_b) {
      this->setValue(2, a_b);
    }
  };
}

#endif
