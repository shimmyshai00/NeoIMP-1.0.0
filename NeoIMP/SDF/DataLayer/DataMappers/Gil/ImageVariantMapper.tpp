#ifndef SDF_DATALAYER_DATAMAPPERS_GIL_IMAGEVARIANTMAPPER_TPP
#define SDF_DATALAYER_DATAMAPPERS_GIL_IMAGEVARIANTMAPPER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariantMapper.tpp
 * PURPOSE: Implements the ImageVariantMapper template.
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

#include "ImageMapper.hpp"

namespace SDF::DataLayer::DataMappers::Gil {
  template<class ... ImageEntityTs>
  ImageVariantMapper<ImageEntityTs...>::ImageVariantMapper(Context::FileRegistry *fileRegistry)
    : m_fileRegistry(fileRegistry)
  {
  }

  template<class ... ImageEntityTs>
  void
  ImageVariantMapper<ImageEntityTs...>::insert(Common::Handle uid, entity_t *entity) {

  }

  template<class ... ImageEntityTs>
  std::unique_ptr<entity_t>
  ImageVariantMapper<ImageEntityTs...>::retrieve(Common::Handle uid) {

  }

  template<class ... ImageEntityTs>
  void
  ImageVariantMapper<ImageEntityTs...>::update(Common::Handle uid, entity_t *entity) {

  }

  template<class ... ImageEntityTs>
  void
  ImageVariantMapper<ImageEntityTs...>::erase(Common::Handle uid) {

  }
}
#endif
