#ifndef SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_STATE_IDOCUMENTAPPMODEL_HPP
#define SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_STATE_IDOCUMENTAPPMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentAppModel.hpp
 * PURPOSE: Provides an interface for accessing the editor state information of a single open document.
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

#include <SDF/Impl/UILayer/AbstractAppModel/Handle.hpp>

#include <boost/signals2/signal.hpp>
#include <cstdlib>

namespace SDF::Impl::UILayer::AbstractAppModel::State {
  class IDocumentAppModel {
  public:
    virtual ~IDocumentAppModel() = default;

    virtual Handle getDocumentHandle() = 0;
    virtual std::string getDocumentName() = 0;

    virtual int getDocumentWidthPx() = 0;
    virtual int getDocumentHeightPx() = 0;
    virtual float getDocumentResolutionPpi() = 0;

    virtual void getRenderedImageData(const unsigned char *&origin,
                                      std::ptrdiff_t &rowStride,
                                      int x1, int y1, int x2, int y2
                                     ) = 0;
  public:
    boost::signals2::signal<void (std::string)> onDocumentNameChanged;
  };
}

#endif
