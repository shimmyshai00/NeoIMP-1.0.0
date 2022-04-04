#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_PRODUCER_IDS_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_PRODUCER_IDS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    producer_ids.hpp
 * PURPOSE: Defines unique ID codes for the view producers in the producer hierarchy.
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

#include "../../../../../../Common/Handle.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  static const Common::Handle MAIN_WINDOW_PRODUCER = 0;
  static const Common::Handle MAIN_WINDOW_NEW_DOCUMENT_DIALOG_PRODUCER = 1;
  static const Common::Handle MAIN_WINDOW_OPEN_DIALOG_PRODUCER = 2;
  static const Common::Handle MAIN_WINDOW_SAVE_AS_DIALOG_PRODUCER = 3;
  static const Common::Handle MAIN_WINDOW_DOCUMENT_VIEW_PRODUCERS_BEGIN = 10000;
}

#endif
