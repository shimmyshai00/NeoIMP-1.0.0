#ifndef SDF_MODELLAYER_DOCUMENTMODEL_SERVICES_IPIXELRECEIVER_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_SERVICES_IPIXELRECEIVER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IPixelReceiver.hpp
 * PURPOSE: An interface to define an object to receive a single pixel of pixel data from a document.
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

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Services {
        class IPixelReceiver {
          virtual ~IPixelReceiver() {}

          virtual void receivePixelData(SRGBPixel rgbPixelData) = 0;
          virtual void receivePixelData(SCMYKPixel cmykPixelData) = 0;
        };
      }
    }
  }
}

#endif
