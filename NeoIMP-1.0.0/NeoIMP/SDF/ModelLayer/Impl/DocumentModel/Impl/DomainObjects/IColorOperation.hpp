#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_ICOLOROPERATION_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_ICOLOROPERATION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IColorOperation.hpp
 * PURPOSE: Interface for operations on the color channels of a document.
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
namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects {
      class IColorOperation {
      public:
        virtual ~IColorOperation() {}

        virtual int processR(int r, int g, int b, int max) = 0;
        virtual int processG(int r, int g, int b, int max) = 0;
        virtual int processB(int r, int g, int b, int max) = 0;

        virtual int processC(int c, int m, int y, int k, int max) = 0;
        virtual int processM(int c, int m, int y, int k, int max) = 0;
        virtual int processY(int c, int m, int y, int k, int max) = 0;
        virtual int processK(int c, int m, int y, int k, int max) = 0;
      };
    }
  }
}

#endif
