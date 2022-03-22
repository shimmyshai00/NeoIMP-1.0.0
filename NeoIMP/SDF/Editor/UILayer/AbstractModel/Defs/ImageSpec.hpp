#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGESPEC_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGESPEC_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageSpec.hpp
 * PURPOSE: Defines a POD struct for specifying construction parameters for an image document.
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

#include "../../../../Common/Meta.hpp"

#include "Color/EColorModel.hpp"
#include "Color/EBitDepth.hpp"
#include "Color/IColor.hpp"
#include "Color/Types.hpp"

#include "ELengthUnit.hpp"
#include "EResolutionUnit.hpp"
#include "EBackgroundPreset.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::Defs {
  struct ImageSpec {
    float width;
    ELengthUnit widthUnit;

    float height;
    ELengthUnit heightUnit;

    float resolution;
    EResolutionUnit resolutionUnit;

    Color::EColorModel colorModel;
    Color::EBitDepth bitDepth;

    EBackgroundPreset backgroundPreset;
    std::shared_ptr<Color::IColor> backgroundColor;

    ImageSpec()
      : width(320.0f),
        widthUnit(LENGTH_UNIT_PIXEL),
        height(240.0f),
        heightUnit(LENGTH_UNIT_PIXEL),
        resolution(300.0f),
        resolutionUnit(RESOLUTION_UNIT_PPI),
        colorModel(Color::COLOR_MODEL_RGB),
        bitDepth(Color::BIT_DEPTH_8),
        backgroundPreset(PRE_BACKGROUND_BLACK),
        backgroundColor(new Color::RGB24_888(0, 0, 0))
    {
    }

    ImageSpec(
      float width_,
      ELengthUnit widthUnit_,
      float height_,
      ELengthUnit heightUnit_,
      float resolution_,
      EResolutionUnit resolutionUnit_,
      Color::EColorModel colorModel_,
      Color::EBitDepth bitDepth_,
      EBackgroundPreset backgroundPreset_,
      std::shared_ptr<Color::IColor> backgroundColor_
    )
      : width(width_),
        widthUnit(widthUnit_),
        height(height_),
        heightUnit(heightUnit_),
        resolution(resolution_),
        resolutionUnit(resolutionUnit_),
        colorModel(colorModel_),
        bitDepth(bitDepth_),
        backgroundPreset(backgroundPreset_),
        backgroundColor(backgroundColor_)
    {
    }
  };
}

#endif
