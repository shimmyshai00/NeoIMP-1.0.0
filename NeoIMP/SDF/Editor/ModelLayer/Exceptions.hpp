#ifndef SDF_EDITOR_MODELLAYER_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions thrown from the model layer.
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

#include "../../Common/Handle.hpp"
#include "../../Exception.hpp"

#include <cstddef>

namespace SDF::Editor::ModelLayer {
  SDF_DEF_NRM_EXCEPTION_1(InvalidImageWidthException, "Invalid image width: %u.", long)
  SDF_DEF_NRM_EXCEPTION_1(InvalidImageHeightException, "Invalid image height: %u.", std::ptrdiff_t)
  SDF_DEF_NRM_EXCEPTION_1(InvalidImageResolutionException, "Invalid image resolution: %f.", float)
  SDF_DEF_NRM_EXCEPTION_1(InvalidLengthUnitException, "Invalid length unit: %d.", int)
  SDF_DEF_NRM_EXCEPTION_1(InvalidResolutionUnitException, "Invalid resolution unit: %d.", int)
  SDF_DEF_NRM_EXCEPTION_1(PrefabNotFoundException, "Prefab with handle %u not found.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(ImageNotFoundException, "Image with handle %u not found.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(ViewNotFoundException, "View with handle %u not found.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(RenderingNotFoundException, "Rendering with handle %u not found.", Common::Handle)
  SDF_DEF_NRM_EXCEPTION_1(NonexistentLayerException, "Nonexistent layer: %d.", std::size_t)
  SDF_DEF_NRM_EXCEPTION_2(PosOutOfBoundsException, "Position out of range: (%d, %d).", int, int)
  SDF_DEF_NRM_EXCEPTION_2(UiDataElementNotFoundException, "UI state element with key %d-%d not found.", Common::Handle, const char *)

  SDF_DEF_BUG_EXCEPTION(InvalidSizeException, "Invalid size passed.")
  SDF_DEF_BUG_EXCEPTION(OutOfRangeException, "Tried to perform an out-of-bounds access.")
  SDF_DEF_BUG_EXCEPTION(ObjectNotFoundInRepositoryException, "Object not found in repository.")
  SDF_DEF_BUG_EXCEPTION(BadCastException, "Tried to cast to wrong type.")
  SDF_DEF_BUG_EXCEPTION(ComponentAlreadyAddedException, "Tried to add the same kind of component to a layer twice.")
  SDF_DEF_BUG_EXCEPTION(DocumentAlreadyRegisteredException, "Document already registered with editor data model.")
  SDF_DEF_BUG_EXCEPTION(DocumentNotFoundInDataModelException, "Document not found in data model.")
}

#endif
