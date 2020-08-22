#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_COLORTYPES_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_COLORTYPES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorTypes.hpp
 * PURPOSE: Definition of color types for the available color models and bit depths (see EBitDepth and EColorModel in
 *          the Interface [Iface] section.).
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

#include <Impl/DomainObjects/Color/TRGBColor.hpp>
#include <Impl/DomainObjects/Color/TCMYKColor.hpp>
#include <Impl/DomainObjects/Color/TColorChannel.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      typedef Impl::DomainObjects::Color::TRGBColor<unsigned char, 8> RGB24;
      typedef Impl::DomainObjects::Color::TRGBColor<unsigned short, 10> RGB30;
      typedef Impl::DomainObjects::Color::TRGBColor<unsigned short, 12> RGB36;
      typedef Impl::DomainObjects::Color::TRGBColor<unsigned short, 16> RGB48;

      typedef Impl::DomainObjects::Color::TCMYKColor<unsigned char, 8> CMYK32;
      typedef Impl::DomainObjects::Color::TCMYKColor<unsigned short, 10> CMYK40;
      typedef Impl::DomainObjects::Color::TCMYKColor<unsigned short, 12> CMYK48;
      typedef Impl::DomainObjects::Color::TCMYKColor<unsigned short, 16> CMYK64;

      typedef Impl::DomainObjects::Color::TColorChannel<unsigned char, 8> Alpha8;
      typedef Impl::DomainObjects::Color::TColorChannel<unsigned short, 10> Alpha10;
      typedef Impl::DomainObjects::Color::TColorChannel<unsigned short, 12> Alpha12;
      typedef Impl::DomainObjects::Color::TColorChannel<unsigned short, 16> Alpha16;
    }
  }
}

#endif
