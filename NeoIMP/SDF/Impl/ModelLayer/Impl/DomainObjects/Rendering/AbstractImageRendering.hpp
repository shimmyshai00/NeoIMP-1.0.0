#ifndef SDF_IMPL_MODELLAYER_IMPL_DOMAINOBJECTS_RENDERING_ABSTRACTIMAGERENDERING_HPP
#define SDF_IMPL_MODELLAYER_IMPL_DOMAINOBJECTS_RENDERING_ABSTRACTIMAGERENDERING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AbstractImageRendering.hpp
 * PURPOSE: The abstract common base interface for image rendering outputs.
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

#include <SDF/Impl/ModelLayer/Impl/DomainObjects/Math/Rect.hpp>
#include <cstdlib>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Rendering {
  class AbstractImageRendering {
  public:
    virtual ~AbstractImageRendering() = default;

    virtual std::size_t getRenderingWidthPx() = 0;
    virtual std::size_t getRenderingHeightPx() = 0;

    // TBA: methods to get pixel format
    virtual void accessRenderingData(const unsigned char *&origin,
                                     std::ptrdiff_t rowStride,
                                     Math::Rect<std::size_t> region
                                    ) = 0;
  };
}

#endif
