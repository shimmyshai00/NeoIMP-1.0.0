#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_PIXELFORMATS_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_PIXELFORMATS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PixelFormats.hpp
 * PURPOSE: Definitions of "standardized" pixel format types.
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

#include <Impl/DomainObjects/Pixel/TRGBPixel.hpp>
#include <Impl/DomainObjects/Pixel/TCMYKPixel.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Pixel {
        typedef TRGBPixel<unsigned char, 255> RGB24;
        typedef TRGBPixel<unsigned short, 1023> RGB30;
        typedef TRGBPixel<unsigned short, 4095> RGB36;
        typedef TRGBPixel<unsigned short, 65535> RGB48;

        typedef TCMYKPixel<unsigned char, 255> CMYK32;
        typedef TCMYKPixel<unsigned short, 1023> CMYK40;
        typedef TCMYKPixel<unsigned short, 4095> CMYK48;
        typedef TCMYKPixel<unsigned short, 65535> CMYK64;
      }
    }
  }
}

#endif
