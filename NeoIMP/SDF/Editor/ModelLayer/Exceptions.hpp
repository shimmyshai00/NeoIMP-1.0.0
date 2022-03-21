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
  SDF_DEF_BUG_EXCEPTION(OutOfBoundsException, "Tried to perform an out-of-bounds access.")
  SDF_DEF_BUG_EXCEPTION(InvalidSizeException, "Invalid physical size passed.")
  SDF_DEF_BUG_EXCEPTION(BadCastException, "Tried to cast to wrong type.")
  SDF_DEF_BUG_EXCEPTION(BadLengthUnitException, "Bad length unit.")
  SDF_DEF_BUG_EXCEPTION(BadResolutionUnitException, "Bad resolution unit.")
  SDF_DEF_BUG_EXCEPTION_1(ComponentAlreadyAddedException, "Component with id %s already added to layer.", const char *)
}

#endif
