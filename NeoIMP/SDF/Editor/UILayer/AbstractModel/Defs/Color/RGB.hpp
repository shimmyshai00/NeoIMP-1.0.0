#ifndef SDF_UILAYER_ABSTRACTMODEL_DEFS_RGB_HPP
#define SDF_UILAYER_ABSTRACTMODEL_DEFS_RGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB.hpp
 * PURPOSE: Defines the RGB template.
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

#include "EColorModel.hpp"
#include "GenericSDR.hpp"

#include <cstddef>
#include <algorithm>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      RGB
  // Purpose:    Defines a set of color values based on RGB (red/green/blue) color models.
  // Parameters: BitsR, BitsG, BitsB - The bits per channel in each RGB channel.
  template<std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  class RGB : public GenericSDR<COLOR_MODEL_RGB, BitsR, BitsG, BitsB> {
  public:
    RGB() {}

    RGB(int r, int g, int b) {
      this->set(0, r);
      this->set(1, g);
      this->set(2, b);
    }

    int
    getR() const {
      return this->getInt(0);
    }

    int
    getG() const {
      return this->getInt(1);
    }

    int
    getB() const {
      return this->getInt(2);
    }

    void
    setR(int r) {
      this->set(0, r);
    }

    void
    setG(int g) {
      this->set(1, g);
    }

    void
    setB(int b) {
      this->set(2, b);
    }
  };
}

#endif
