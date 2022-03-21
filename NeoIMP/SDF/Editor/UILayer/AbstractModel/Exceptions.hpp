#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_EXCEPTIONS_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the exceptions we "expect" to be thrown from the model layer due to bad input or
 *          else foreseeable by its abstraction here.
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

#include "../../../Common/Handle.hpp"
#include "../../../Exception.hpp"

namespace SDF::Editor::UILayer::AbstractModel {
  // Note: these would be "normal" exceptions (and are considered "non-bug" for the purposes of
  //       defining the interface) but should not be shown bare to the user and instead rendered in
  //       a more contextually intelligible error message if possible given some of these contain
  //       internal codes and the like. Hence when uncaught and emerging from a controller, we
  //       describe them as bugs.
  SDF_DEF_BUG_EXCEPTION_4(BadDimensionsException, "Tried to create an image with invalid dimensions: %f (u: %d) x %f (u: %d)", float, int, float, int)
  SDF_DEF_BUG_EXCEPTION_2(BadResolutionException, "Tried to create an image with bad resolution: %f (u: %d)", float, int)
  SDF_DEF_BUG_EXCEPTION(BadColorFormatException, "Tried to create an image with a bad color format.")
  SDF_DEF_BUG_EXCEPTION_1(PrefabNotFoundException, "Prefab %d not found.", Common::Handle)
  SDF_DEF_BUG_EXCEPTION_1(DocumentNotFoundException, "Document with handle %d not found.", Common::Handle)
  SDF_DEF_BUG_EXCEPTION_1(FileSpecNotAssociatedException, "File spec not associated to document id %d.", Common::Handle)
  SDF_DEF_BUG_EXCEPTION_1(FileFormatNotAssociatedException, "File format not associated to document id %d.", Common::Handle)
  SDF_DEF_BUG_EXCEPTION_1(InvalidUnitException, "Invalid measuring unit %d.", int)
  SDF_DEF_BUG_EXCEPTION_1(FileNotFoundException, "File with spec %s not found.", const char *)
  SDF_DEF_BUG_EXCEPTION_1(BadFileFormatException, "Bad file format %d.", int)
  SDF_DEF_BUG_EXCEPTION(BadFileException, "Tried to load a file but it was bad.")
  SDF_DEF_BUG_EXCEPTION(FileTypeUnsupportedException, "Tried to load a file but it turned out to be an unsupported, but valid, type.")
  SDF_DEF_BUG_EXCEPTION_1(RenderingNotFoundException, "Rendering with handle %d not found.", Common::Handle)
  SDF_DEF_BUG_EXCEPTION_1(ViewNotFoundException, "View coordinates with handle %d not found.", Common::Handle)
}

#endif
