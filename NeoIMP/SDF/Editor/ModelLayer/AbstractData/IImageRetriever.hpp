#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGRETRIEVER_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGRETRIEVER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImageRetriever.hpp
 * PURPOSE: Defines the IImageRetriever interface.
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

#include "../../../Common/Data/IOwningRetrievable.hpp"
#include "../../../Common/Handle.hpp"

#include <memory>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IImageRetriever
  // Purpose:    A convenience interface to specialize Common::Data::IOwningRetrievable for the
  //             image repository.
  // Parameters: ImageT - The image type.
  template<class ImageT>
  class IImageRetriever : public Common::Data::IOwningRetrievable<Common::Handle, ImageT>
  {
  };
}

#endif
