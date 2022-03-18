#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_FILEFORMATNAMES_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_FILEFORMATNAMES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileFormatNames.hpp
 * PURPOSE: Defines GUI-specific description texts for the file formats enumerated in
 *          AbstractModel::Defs::EFileFormat.
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

#include "../../../AbstractModel/Defs/EFileFormat.hpp"

#include <QString>

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // These must be in the order in which they are enumerated. Keeping these separate from the
  // extension list, makes it slightly easier to change format names in the future (e.g. with
  // possible implementation of multi-language support) while keeping these changes separate from
  // the wildcards describing the file extensions. Might also make this usefully extractable outside
  // the Qt-specific subsystem (e.g. use an std::wstring instead of a QString).
  static QString g_fileFormatNames[AbstractModel::Defs::FILE_FORMAT_MAX] = {
    QString("Portable Network Graphics (PNG)") // FILE_FORMAT_PNG
  };

  static QString g_fileExtensionFilters[AbstractModel::Defs::FILE_FORMAT_MAX] = {
    QString("*.png")
  };
}

#endif
