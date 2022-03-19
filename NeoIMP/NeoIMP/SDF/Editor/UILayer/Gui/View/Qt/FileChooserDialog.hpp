#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_FILECHOOSERDIALOG_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_FILECHOOSERDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileChooserDialog.hpp
 * PURPOSE: Defines the FileChooserDialog class.
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

#include "../../../../../Common/IConnection.hpp"
#include "../IController.hpp"

#include "QtEvent.hpp"

#include <QFileDialog>

#include <cstddef>
#include <string>

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // Class:      FileChooserDialog
  // Purpose:    Defines a Qt view to integrate the standard file load/save dialogs into the MVC
  //             system.
  // Parameters: None.
  class FileChooserDialog : public QFileDialog {
    Q_OBJECT
  public:
    // basically cloned from Qt itself to make a clean extension
    FileChooserDialog(
      QWidget *parent = nullptr,
      const QString &caption = QString(),
      const QString &directory = QString(),
      const QString &filter = QString()
    );

    FileChooserDialog(QWidget *parent, ::Qt::WindowFlags flags);
    ~FileChooserDialog();

    // with these controller adjoinment methods
    Common::PIConnection
    hookOnAccept(std::unique_ptr<IController<std::wstring, std::size_t>> controller);
  private:
    QtEvent<std::wstring, std::size_t> m_onAcceptEvent;
  };
}

#endif
