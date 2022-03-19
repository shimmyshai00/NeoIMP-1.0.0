#ifndef SDF_UILAYER_QTAPPLICATION_VIEW_IVIEW_HPP
#define SDF_UILAYER_QTAPPLICATION_VIEW_IVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IView.hpp
 * PURPOSE: Defines the IView interface.
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

namespace SDF::UILayer::QtApplication::View {
  // Class:      IView
  // Purpose:    Defines an interface for Qt MVC views.
  // Parameters: QWidgetT - The type of Qt QWidget this view derives from.
  template<class QWidgetT>
  class IView {
  public:
    virtual ~IView() = default;

    // Function:   getQWidget
    // Purpose:    Gets the underlying Qt widget.
    // Parameters: None.
    // Returns:    The QWidget of type QWidgetT underlying this view.
    virtual QWidgetT *
    getQWidget() = 0;
  };
}

#endif
