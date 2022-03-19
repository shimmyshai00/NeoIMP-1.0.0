#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_RENDERER_VISITOR_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ALGORITHMS_RENDERER_VISITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Visitor.hpp
 * PURPOSE: Defines the Visitor class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IImageDataVisitor.hpp>
#include <SDF/ModelLayer/Math/Rect.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageImpl.hpp>

#include <boost/gil/extension/dynamic_image/dynamic_image_all.hpp>

#include <cstddef>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IRenderBuffer;
  }

  namespace DomainObjects::Algorithms::Renderer {
    // Class:      Visitor
    // Purpose:    Visits image data and renders it to a format suitable for display on screen. Right now, the sole
    //             supported target render format is a conventional 24-bit RGB style format, similar to the HTML Hex
    //             representation. (Namely, it is an ARGB32 format with the alpha always at 255.) THIS IS RESTRICTIVE,
    //             because this program is designed to support greater color depths internally, and thus this prohibits
    //             the display of such data with correspondingly greater fidelity. The reason this author does not
    //             include better support here is TESTING - this author does not have the money to purchase a monitor
    //             with a color depth surpassing 8 bits per channel (24 bits total). Thus it would be impossible to
    //             debug properly. This is thus a large FIXME for any potential future contributors who happen to have
    //             the relevant hardware.
    // Parameters: None.
    class Visitor : public Services::AbstractDomain::IImageDataVisitor {
    public:
      // Function:   Visitor
      // Purpose:    Construct a new rendering visitor.
      // Parameters: uid - The unique ID for this domain object.
      //             buffer - The buffer to retain the rendering in.
      Visitor(Services::AbstractDomain::IRenderBuffer *buffer);

      void
      visitGilRegion(Math::Rect<std::size_t> rect, Services::AbstractDomain::Defs::GilRegionType &gilRegion);
    private:
      Services::AbstractDomain::IRenderBuffer *m_buffer;
    };
  }
}

#endif
