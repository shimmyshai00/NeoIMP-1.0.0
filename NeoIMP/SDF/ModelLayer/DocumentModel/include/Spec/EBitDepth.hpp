#ifndef SDF_MODELLAYER_IFACE_DOCUMENTMODEL_EBITDEPTH_HPP
#define SDF_MODELLAYER_IFACE_DOCUMENTMODEL_EBITDEPTH_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EBitDepth.hpp
 * PURPOSE: Enumeration of the available color bit depth settings. These are given per color channel, not per whole
 *          pixel (hence a bit depth of 8 with RGB color model is 24 bits per pixel, or 32 if the alpha channel is
 *          included).
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
      namespace Spec {
        enum EBitDepth {
          BIT_DEPTH_8,
          BIT_DEPTH_10,
          BIT_DEPTH_12,
          BIT_DEPTH_16
        };
      }
    }
  }
}

#endif
