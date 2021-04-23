#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_IIMAGEDATASOURCE_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_IIMAGEDATASOURCE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageDataSource.hpp
 * PURPOSE: Headers for image data sources for the document editor widget.
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

#include <cstdlib>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  class IImageDataSource {
  public:
    virtual ~IImageDataSource() = default;

    virtual int getImageWidth() = 0;
    virtual int getImageHeight() = 0;

    // Right now, expects to receive RGB32 format pixels only.
    virtual void accessImageData(const unsigned char *&origin,
                                 std::ptrdiff_t &rowStride,
                                 int x1, int y1, int x2, int y2
                                ) = 0;
  };
}

#endif
