/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentView.cpp
 * PURPOSE: The Qt-based save document view implementation.
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

#include <SaveDocumentView.hpp>

#include <Dialogs/NewDocumentDialog.hpp>

#include <QDir>
#include <QStringList>
#include <QString>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  SaveDocumentView::SaveDocumentView()
    : m_saveDocumentDialog(new QFileDialog)
  {
    m_saveDocumentDialog->setAcceptMode(QFileDialog::AcceptSave);

    QObject::connect(m_saveDocumentDialog, &QFileDialog::accepted, [=]() {
      QDir selectedDirectory(m_saveDocumentDialog->directory());
      QStringList selectedFiles(m_saveDocumentDialog->selectedFiles());

      if(selectedFiles[0] != selectedDirectory.path()) {
        m_acceptSaveParametersSignal(Events::AcceptSaveParametersEvent {
          selectedFiles[0].toStdString(),
          AbstractModel::Properties::FILE_FORMAT_PNG
        });
      }
    });
  }

  QWidget *SaveDocumentView::getQWidget() {
    return m_saveDocumentDialog;
  }
  
  void SaveDocumentView::show() {
    m_saveDocumentDialog->open();
  }

  void SaveDocumentView::close() {
    m_saveDocumentDialog->close();
  }

  boost::signals2::connection SaveDocumentView::connectEventListener(
    std::function<void (Events::AcceptSaveParametersEvent)> listener
  ) {
    return m_acceptSaveParametersSignal.connect(listener);
  }
}
