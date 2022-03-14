#ifndef SDF_DATALAYER_EXCEPTIONS_HPP
#define SDF_DATALAYER_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions thrown from the data layer.
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

#include "../Common/Handle.hpp"
#include "../Exception.hpp"

namespace SDF::DataLayer {
  SDF_DEF_BUG_EXCEPTION(UidInUseException, "UID is already in use")
  SDF_DEF_BUG_EXCEPTION(FileSpecNotFoundException, "File spec not found")

  SDF_DEF_NRM_EXCEPTION_4(InconsistentDimensionsException, "Image with inconsistent background dimensionality tried (%u x %u background layer in %u x %u image)", std::size_t, std::size_t, std::size_t, std::size_t)
  SDF_DEF_NRM_EXCEPTION_1(EntityAlreadyInsertedException, "Entity %d already inserted", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(EntityNotFoundException, "Entity %d not found", Common::Handle)
  SDF_DEF_NRM_EXCEPTION(EmptyEntityException, "Cannot save an entity with no image data!")
  SDF_DEF_NRM_EXCEPTION(InvalidBackgroundLayerException, "Invalid or malformed background layer encountered")
}

#endif
