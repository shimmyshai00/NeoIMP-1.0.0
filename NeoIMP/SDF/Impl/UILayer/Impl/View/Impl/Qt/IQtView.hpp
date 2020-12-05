#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_IQTVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_IQTVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IQtView.hpp
 * PURPOSE: The interface for Qt-based MVC views. This provides for specialized handling of hierarchy relatiosnhips
 *          amongst views that are not passed outside this specific UI implementation.
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

#include <QPointer>
#include <QWidget>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  class IQtView {
  public:
    virtual ~IQtView() = default;

    virtual QPointer<QWidget> getQWidget() = 0;
    virtual void setContextView(IQtView *contextView) = 0;
  };
}

#endif
