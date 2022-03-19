#ifndef SDF_UILAYER_GUI_QT_EVENTS_DIALOGEVENT_HPP
#define SDF_UILAYER_GUI_QT_EVENTS_DIALOGEVENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DialogEvent.hpp
 * PURPOSE: Defines the DialogEvent event hierarchy.
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

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>

namespace SDF::UILayer::Gui::Qt::Events {
  template<class T>
  struct DialogEvent : public GuiEvent {};

  template<class T>
  struct AcceptEvent : public DialogEvent<T> {
    T dialogRv;

    AcceptEvent(T dialogRv)
      : dialogRv(dialogRv)
    {}
  };

  template<class T>
  struct RejectEvent : public DialogEvent<T> {};
}

#endif
