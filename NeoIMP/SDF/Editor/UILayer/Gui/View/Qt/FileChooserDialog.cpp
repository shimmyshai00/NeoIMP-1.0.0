/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileChooserDialog.cpp
 * PURPOSE: Implements the FileChooserDialog class.
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

#include "FileChooserDialog.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt {
  FileChooserDialog::FileChooserDialog(
    QWidget *parent = nullptr,
    const QString &caption = QString(),
    const QString &directory = QString(),
    const QString &filter = QString()
  )
    : QFileDialog(parent, caption, directory, filter)
  {
    connect(*this, &QFileDialog::accept(), [&]() {
      QStringList files = selectedFiles();
      m_onAcceptEvent.trigger(files[0].toStdString());
    });
  }

  FileChooserDialog::FileChooserDialog(QWidget *parent, Qt::WindowFlags flags)
    : QFileDialog(parent, flags)
  {
  }

  FileChooserDialog::~FileChooserDialog() {
  }

  Common::PIConnection
  FileChooserDialog::hookOnAccept(std::unique_ptr<IController<std::string>> controller) {
    return m_onAcceptEvent.hook(std::move(controller));
  }
}
