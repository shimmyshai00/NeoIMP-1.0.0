#ifndef SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_STATE_IOPENDOCUMENTSMODEL_HPP
#define SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_STATE_IOPENDOCUMENTSMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IOpenDocumentsModel.hpp
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

#include <SDF/Impl/Framework/IMVCAppModel.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Handle.hpp>

#include <boost/signals2/signal.hpp>

namespace SDF::Impl::UILayer::AbstractAppModel::State {
  struct OpenDocumentsObservables {
    boost::signals2::signal<void (Handle)> onDocumentAdded;
    boost::signals2::signal<void (Handle)> onDocumentRemoved;
  };

  class IOpenDocumentsModel : public Framework::IMVCAppModel<OpenDocumentsObservables> {
  public:
    virtual ~IOpenDocumentsModel() = default;

    virtual void addDocument(Handle handle) = 0;
    virtual void removeDocument(Handle handle) = 0;
  };
}

#endif
