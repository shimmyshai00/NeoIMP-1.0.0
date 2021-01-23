/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDocumentView.cpp
 * PURPOSE: The Qt-based open-document view.
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

#include <OpenDocumentView.hpp>

#include <SDF/Exception/Exception.hpp>

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMessageBox>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  OpenDocumentView::OpenDocumentView()
    : m_fileDialog(new QFileDialog)
  {
    m_fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
    m_fileDialog->setFileMode(QFileDialog::ExistingFile);

    QObject::connect(m_fileDialog, &QFileDialog::accepted, [=]() {
      QStringList selectedFiles(m_fileDialog->selectedFiles());
      QString fileNameQString(selectedFiles[0]);

      try {
        onAccepted(fileNameQString.toStdString(), DataLayer::Properties::FILE_FORMAT_PNG);
      } catch(SDF::Exception::Exception &e) {
        QMessageBox::critical(nullptr, "Error", e.what());
      }
    });

    QObject::connect(m_fileDialog, &QFileDialog::rejected, [=]() {
      onDismissed();
    });

    m_fileDialog->show();
  }

  OpenDocumentView::~OpenDocumentView() {
    m_fileDialog->close();
    delete m_fileDialog;
  }
}
