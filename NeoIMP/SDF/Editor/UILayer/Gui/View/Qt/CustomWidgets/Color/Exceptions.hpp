#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_COLOR_EXCEPTIONS_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_COLOR_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines exceptions for the color system.
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

#include "../../../../../../../Error/UiException.hpp"
#include "../../../../../../../Error/Exception.hpp"

#include <cstddef>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::Color {
  struct UnsupportedUiColorFormatException : public Error::LikelyBug<Error::UiException> {
    UnsupportedUiColorFormatException() {
      whatPrintf("Tried to use an unsupported UI color format.");
    }
  };

  struct ChannelOutOfRangeException : public Error::LikelyBug<Error::UiException> {
    ChannelOutOfRangeException(std::size_t which) {
      whatPrintf("Tried to access an out-of-range color channel (%lu).", which);
    }
  };
}

#endif
