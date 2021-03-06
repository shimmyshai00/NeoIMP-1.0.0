#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_ITOOL_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_ITOOL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ITool.hpp
 * PURPOSE: Defines the ITool interface.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IDomainObject.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>

#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <memory>

namespace SDF::ModelLayer::Services::AbstractDomain {
  class IImageDelta;

  // Class:      ITool
  // Purpose:    Defines the interface for an editing tool.
  // Parameters: none.
  class ITool : public IDomainObject<ITool> {
  public:
    virtual ~ITool() = default;

    virtual UILayer::AbstractModel::Properties::Tool
    getToolType() const = 0;

    // These methods mirror those for the tool service.
    virtual void
    beginApplication(IImage *image) = 0;

    virtual void
    applyAt(float x, float y) = 0;

    virtual std::pair<IImage *, std::unique_ptr<IImageDelta>>
    commit() = 0;
  };
}

#endif
