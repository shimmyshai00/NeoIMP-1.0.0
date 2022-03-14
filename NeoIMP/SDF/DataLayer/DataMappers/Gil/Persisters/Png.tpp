#ifndef SDF_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_PNG_TPP
#define SDF_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_PNG_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Png.tpp
 * PURPOSE: Implements the Png persister.
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

#include "../../../Exceptions.hpp"

#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>

namespace SDF::DataLayer::DataMappers::Gil::Persisters {
  template<class GilSpecT>
  void
  Png::operator()(ModelLayer::AbstractData::Entity::Image<GilSpecT> &ent) {
    using namespace boost::gil;

    if(m_direction == DIR_SAVE) {
      // Sanity check
      if(ent.m_layers.size() == 0) {
        throw EmptyEntityException();
      } else {
        if(!ent.m_layers(0).m_bgRasterContent) {
          throw InvalidBackgroundLayerException();
        } else {
          if((ent.m_widthPx != ent.m_layers(0).m_bgRasterContent->m_view.width()) ||
             (ent.m_heightPx != ent.m_layers(0).m_bgRasterContent->m_view.height())
            )
          {
            throw InconsistentDimensionsException(ent.m_backgroundLayer.m_widthPx,
              ent.m_backgroundLayer.m_heightPx, ent.m_widthPx, ent.m_heightPx);
          }
        }
      }

      write_view(m_fileSpec, view(*ent.m_layers(0).m_bgRasterContent->m_data), png_tag());
    } else {
      throw "NOT YET IMPLEMENTED";
    }
  }
}

#endif
