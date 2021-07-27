/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.cpp
 * PURPOSE: Implements the Factory class.
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

#include "Factory.hpp"

#include "../../../../UILayer/AbstractModel/Data/LengthUnit.hpp"
#include "../../../../UILayer/AbstractModel/Data/ResolutionUnit.hpp"
#include "../../../Metrics/LengthUnit.hpp"
#include "../../../Metrics/ResolutionUnit.hpp"

#include "../../../Exceptions/Exceptions.hpp"
#include "Image.hpp"

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  // Helper functions.
  Metrics::LengthUnit localize(UILayer::AbstractModel::Data::LengthUnit unit) {
    switch(unit) {
      case UILayer::AbstractModel::Data::UNIT_PIXEL: return Metrics::LENGTH_UNIT_PIXEL;
      case UILayer::AbstractModel::Data::UNIT_MILLIMETER: return Metrics::LENGTH_UNIT_MILLIMETER;
      case UILayer::AbstractModel::Data::UNIT_POINT: return Metrics::LENGTH_UNIT_POINT;
      case UILayer::AbstractModel::Data::UNIT_PICA: return Metrics::LENGTH_UNIT_PICA;
      case UILayer::AbstractModel::Data::UNIT_CENTIMETER: return Metrics::LENGTH_UNIT_CENTIMETER;
      case UILayer::AbstractModel::Data::UNIT_INCH: return Metrics::LENGTH_UNIT_INCH;
      default: throw ModelLayer::Exceptions::InvalidLengthUnitException(unit);
    }
  }

  Metrics::ResolutionUnit localize(UILayer::AbstractModel::Data::ResolutionUnit unit) {
    switch(unit) {
      case UILayer::AbstractModel::Data::UNIT_PIXELS_PER_INCH: return Metrics::RESOLUTION_UNIT_PPI;
      case UILayer::AbstractModel::Data::UNIT_PIXELS_PER_CENTIMETER: return Metrics::RESOLUTION_UNIT_PIXELS_PER_CM;
      case UILayer::AbstractModel::Data::UNIT_PIXELS_PER_MILLIMETER: return Metrics::RESOLUTION_UNIT_PIXELS_PER_MM;
      default: throw ModelLayer::Exceptions::InvalidResolutionUnitException(unit);
    }
  }
}

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  Factory::Factory(IUidGenerator<int> *uidGenerator) : m_uidGenerator(uidGenerator) {}

  std::unique_ptr<IImage>
  Factory::create(UILayer::AbstractModel::Data::DocumentSpec spec)
  {
    using namespace UILayer::AbstractModel::Data;

    // Which type of image to create depends principally on the color model used.
    if((spec.documentColorModel == COLOR_MODEL_RGB) &&
       (spec.documentBitDepth == BIT_DEPTH_8)
      )
    {
      std::size_t id(m_uidGenerator->get());

      return std::make_unique<Image<boost::gil::rgb8_image_t,
                                    boost::gil::rgb8_view_t,
                                    boost::gil::rgb8_pixel_t
                                   >
                             >
             (
               id,
               "Untitled " + std::to_string(id),
               spec.documentWidth,
               localize(spec.documentWidthUnit),
               spec.documentHeight,
               localize(spec.documentHeightUnit),
               spec.documentResolution,
               localize(spec.documentResolutionUnit)
             );
    } else {
      throw Exceptions::BadDocumentSpecException();
    }
  }
}
