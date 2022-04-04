#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_COLOR_ADAPTEDQCOLOR_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_COLOR_ADAPTEDQCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AdaptedQColor.hpp
 * PURPOSE: Defines the AdaptedQColor class.
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

#include "../../../../../AbstractModel/Defs/Color/IColor.hpp"
#include "../../../../../AbstractModel/Defs/Color/UiColorModel.hpp"

#include <QColor>

#include <cstddef>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::Color {
  // Class:      AdaptedQColor
  // Purpose:    Adapts a Qt QColor into the model-UI interface IColor system.
  // Parameters: None.
  class AdaptedQColor : public AbstractModel::Defs::Color::IColor<
                          AbstractModel::Defs::Color::UiColorModel
                        >,
                        public QColor
  {
  public:
    AdaptedQColor();
    AdaptedQColor(const QColor &qColor);

    AbstractModel::Defs::Color::UiColorModel
    getColorFormat() const;

    std::size_t
    getNumChannels() const;

    int
    getChannelMin(std::size_t a_channelIdx) const;

    int
    getChannelMax(std::size_t a_channelIdx) const;

    // NB: there is an unfortunate name collision near-miss here
    int
    getValue(std::size_t a_channelIdx) const;

    float
    getValueF(std::size_t a_channelIdx) const;

    void
    setValue(std::size_t a_channelIdx, int a_value);

    void
    setValueF(std::size_t a_channelIdx, float a_value);
  };
}

#endif
