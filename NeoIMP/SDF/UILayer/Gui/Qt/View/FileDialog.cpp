/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileDialog.cpp
 * PURPOSE: Implements the FileDialog class.
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

#include <FileDialog.hpp>

#include <Events/DialogEvent.hpp>
#include <FileIndicator.hpp>

#include <safeConnect.hpp>

#include <QStringList>

namespace SDF::UILayer::Gui::Qt::View {
  FileDialog::FileDialog(std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                         const QString &caption,
                         QFileDialog::AcceptMode acceptMode,
                         QWidget *parent
                        )
    : QFileDialog(parent, caption),
      m_controller(std::move(controller))
  {
    setAcceptMode(acceptMode);

    safeConnect(static_cast<QDialog *>(this), &QDialog::accepted, [=]() {
      QStringList selectedFilesList(selectedFiles());
      QString fileNameQString(selectedFilesList[0]);

      std::shared_ptr<Events::AcceptEvent<FileIndicator>> acceptEvent(new Events::AcceptEvent<FileIndicator>({
        fileNameQString.toStdString(),
        AbstractModel::Properties::FILE_FORMAT_PNG
      }));

      m_controller->handleEvent(acceptEvent);
    });

    safeConnect(static_cast<QDialog *>(this), &QDialog::rejected, [=]() {
      m_controller->handleEvent(std::make_shared<Events::RejectEvent<FileIndicator>>());
    });
  }

  FileDialog::~FileDialog() {}

  IGuiElement *
  FileDialog::getParent() {
    if(auto p = dynamic_cast<IGuiElement *>(parentWidget())) {
      return p;
    } else {
      return nullptr;
    }
  }

  void
  FileDialog::show() {
    QFileDialog::show();
  }

  void
  FileDialog::close() {
    QFileDialog::close();
  }
}
