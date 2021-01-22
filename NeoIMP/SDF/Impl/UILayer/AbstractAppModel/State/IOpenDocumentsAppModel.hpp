#ifndef SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_STATE_IOPENDOCUMENTSAPPMODEL_HPP
#define SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_STATE_IOPENDOCUMENTSAPPMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IOpenDocumentsAppModel.hpp
 * PURPOSE: Provides an interface for accessing the editor state information about which documents are open.
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

namespace SDF::Impl::UILayer::AbstractAppModel::State {
  class IDocumentAppModel;

  class IOpenDocumentsAppModel {
  public:
    virtual ~IOpenDocumentsAppModel() = default;

    virtual std::vector<Handle> getOpenDocumentHandles() const = 0;
    virtual IDocumentAppModel *getDocumentModel(Handle handle) = 0;

    virtual Handle getFocusDocument() = 0;
  public:
    // Note that these are technically member variables, so this is technically not a "pure" interface - nonetheless,
    // we make an exception here because they are just meant to be hooked for observation and it keeps the code simple
    // and free of boilerplate.
    boost::signals2::signal<void (Handle)> onDocumentAdded;
    boost::signals2::signal<void (Handle)> onDocumentRemoved;

    boost::signals2::signal<void (Handle)> onFocusDocumentChanged;
  };
}

#endif
