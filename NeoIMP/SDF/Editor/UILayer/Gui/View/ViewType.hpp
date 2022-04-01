#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_VIEWTYPE_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_VIEWTYPE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewType.hpp
 * PURPOSE: Enumerates the available view types.
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

namespace SDF::Editor::UILayer::Gui::View {
  enum ViewType {
    VIEW_MAIN_WINDOW,
    VIEW_NEW_DOCUMENT_DIALOG,
    VIEW_SAVE_DOCUMENT_DIALOG,
    VIEW_OPEN_DOCUMENT_DIALOG,
    VIEW_DOCUMENT_VIEW
  };
}

#endif
