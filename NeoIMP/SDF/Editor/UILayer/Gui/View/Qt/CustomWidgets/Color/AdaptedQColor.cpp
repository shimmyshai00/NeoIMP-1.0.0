/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AdaptedQColor.cpp
 * PURPOSE: Implements the AdaptedQColor class.
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

#include "AdaptedQColor.hpp"

#include "Exceptions.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::Color {
  AdaptedQColor::AdaptedQColor() {
  }

  AdaptedQColor::AdaptedQColor(const QColor &qColor)
    : QColor(qColor)
  {
  }

  AbstractModel::Defs::Color::UiColorModel
  AdaptedQColor::getColorFormat() const {
    if(spec() == Rgb) {
      return AbstractModel::Defs::Color::UI_COLOR_MODEL_RGB;
    } else {
      // These other types need to still be implemented! WOW, QT sure has diverse formats.
      throw UnsupportedUiColorFormatException();
    }
  }

  std::size_t
  AdaptedQColor::getNumChannels() const {
    if(spec() == Rgb) {
      return 3;
    } else {
      return 0;
    }
  }

  int
  AdaptedQColor::getChannelMin(std::size_t a_channelIdx) const {
    return 0;
  }

  int
  AdaptedQColor::getChannelMax(std::size_t a_channelIdx) const {
    return 255;
  }

  int
  AdaptedQColor::getValue(std::size_t a_channelIdx) const {
    if(spec() == Rgb) {
      if(a_channelIdx == 0) {
        return red();
      } else if(a_channelIdx == 1) {
        return green();
      } else if(a_channelIdx == 2) {
        return blue();
      } else {
        throw ChannelOutOfRangeException(a_channelIdx);
      }
    } else {
      throw UnsupportedUiColorFormatException();
    }
  }

  float
  AdaptedQColor::getValueF(std::size_t a_channelIdx) const {
    if(spec() == Rgb) {
      if(a_channelIdx == 0) {
        return redF();
      } else if(a_channelIdx == 1) {
        return greenF();
      } else if(a_channelIdx == 2) {
        return blueF();
      } else {
        throw ChannelOutOfRangeException(a_channelIdx);
      }
    } else {
      throw UnsupportedUiColorFormatException();
    }
  }

  void
  AdaptedQColor::setValue(std::size_t a_channelIdx, int a_value) {
    if(spec() == Rgb) {
      if(a_channelIdx == 0) {
        setRed(a_value);
      } else if(a_channelIdx == 1) {
        setGreen(a_value);
      } else if(a_channelIdx == 2) {
        setBlue(a_value);
      } else {
        throw ChannelOutOfRangeException(a_channelIdx);
      }
    } else {
      throw UnsupportedUiColorFormatException();
    }
  }

  void
  AdaptedQColor::setValueF(std::size_t a_channelIdx, float a_value) {
    if(spec() == Rgb) {
      if(a_channelIdx == 0) {
        setRedF(a_value);
      } else if(a_channelIdx == 1) {
        setGreenF(a_value);
      } else if(a_channelIdx == 2) {
        setBlueF(a_value);
      } else {
        throw ChannelOutOfRangeException(a_channelIdx);
      }
    } else {
      throw UnsupportedUiColorFormatException();
    }
  }
}
